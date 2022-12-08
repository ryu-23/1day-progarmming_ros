/*
  MsTimer2 is a small and very easy to use library to interface Timer2 with
  humans. It's called MsTimer2 because it "hardcodes" a resolution of 1
  millisecond on timer2
  For Details see: http://www.arduino.cc/playground/Main/MsTimer2
*/
#include <MsTimer2.h>
#define encodPinA1      2 
#define encodPinB1      3                       // Quadrature encoder B pin
#define INA 4
#define PWM 5
#define check_pin 6
volatile int32_t encoderPos = 0;
volatile int32_t encoderPos_old = 0;
volatile int32_t encoderPos_trem = 0;
int32_t target_Pos = 0;
int32_t Pos_error = 0;
int32_t Pos_error_d = 0;
int32_t Pos_error_old = 0;

float P = 0.5; 
float Pd = 1;
float Pi = 0.4;

double pid_pwm = 0;

double pos_error_sum = 0.0;



// Switch on LED on and off each half second

#if ARDUINO >= 100
const int led_pin = LED_BUILTIN;   // 1.0 built in LED pin var
#else
const int led_pin = 13;         // default to pin 13
#endif



void encoder_read()  
{
  
  delayMicroseconds(5);
  if(digitalRead(encodPinB1)==LOW)    encoderPos++;           
  else                                 encoderPos--; 
}

void interrupt_setup(void)
{
  pinMode(encodPinA1, INPUT_PULLUP); 
  pinMode(encodPinB1, INPUT_PULLUP);  
  attachInterrupt(0, encoder_read, RISING);  
}



void timer()
{
  static boolean output = HIGH;
  
  digitalWrite(led_pin, output);
  digitalWrite(check_pin, HIGH);
  output = !output;
  
 // digitalWrite(check_pin, LOW);
 //if(pid_pwm < 11) pid_pwm + 11; 
 Pos_error = target_Pos - encoderPos;
 Pos_error_d = Pos_error- Pos_error_old;
 Pos_error_old = Pos_error;
// pid_pwm = P*Pos_error + Pd * Pos_error_d ;
 pos_error_sum += encoderPos;
 pos_error_sum = (pos_error_sum>50) ? 50 : pos_error_sum;
 pos_error_sum = (pos_error_sum<-50) ? -50 : pos_error_sum;
 /////////////////////////////////////////
 encoderPos_trem = encoderPos - encoderPos_old;
 /////////////////////////////////////////
 encoderPos_old = encoderPos;

  
  if(fabs(Pos_error)<=2) pos_error_sum = 0;
  pid_pwm = P*Pos_error + Pd * Pos_error_d + Pi* pos_error_sum;

  pid_pwm = (pid_pwm>=255) ? 255: pid_pwm;
  pid_pwm = (Pos_error >= (double)target_Pos*0.1) ? 255 : pid_pwm;
  
 if(pid_pwm >0)motor_control(-1,pid_pwm);
 else motor_control(1,-pid_pwm);
 digitalWrite(check_pin, LOW);
 
 
}
void motor_control(int direc, int pwm)
{
  pwm = (pwm>=255) ? 255: pwm;
  switch(direc){
    case 1 : digitalWrite(INA,HIGH);
             analogWrite(PWM,pwm);
             break;
    case 0 : digitalWrite(INA,LOW);
             analogWrite(PWM,0);
             break;
    case -1 : digitalWrite(INA,LOW);
             analogWrite(PWM,pwm);
             break;
  }
  
  
  
  }
void setup()
{
  pinMode(led_pin, OUTPUT);
//  pinMode(check_pin, OUTPUT);
  pinMode(INA, OUTPUT);
  pinMode(PWM, OUTPUT);
  MsTimer2::set(50, timer); // 500ms period
  MsTimer2::start();
  interrupt_setup();
  Serial.begin(115200);
  Serial.println("pos,pos_error");
  target_Pos = 1500;
}

void loop()
{
 /* if(fabs(Pos_error) >= 5){
  Serial.print(encoderPos);
  Serial.print(",");
  Serial.println(Pos_error);
  }*/
 /* if(fabs(Pos_error) < 5){
    motor_control(-1,0);  
  }
  else
  {
    motor_control(-1,14);
    }
 // motor_control(-1,12);
*/
  //motor_control(-1,50);
 /* Serial.print("  encoderPos = ");
  Serial.print(encoderPos);
  
  Serial.print("  Pos_error = ");
  Serial.print(Pos_error);

  Serial.print("  pos_error_sum = ");
  Serial.print(pos_error_sum);
  
  Serial.print("  pid_pwm = ");
  Serial.println(pid_pwm);*/
  if(fabs(Pos_error) >= 5){
  Serial.print(encoderPos);
  Serial.print(",");
  Serial.print(Pos_error);
  Serial.print(",");
  Serial.println(pid_pwm);
  }
  //backward 12 1
  //forward 11 -1
}
