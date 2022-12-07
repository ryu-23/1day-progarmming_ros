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
volatile int32_t New_encoderPos = 0;
int32_t target_Pos = 0;
int32_t Pos_error = 0;
int32_t Pos_error_d = 0;
int32_t Pos_error_old = 0;

float P = 3.5; 
float Pd = 6.0;
float Pi = 0.3;

double pid_pwm = 0;

double pos_error_sum = 0.0;

//int dead_zone_count = 0;
double dead_zone_count = 0;


// Switch on LED on and off each half second

#if ARDUINO >= 100
const int led_pin = LED_BUILTIN;   // 1.0 built in LED pin var
#else
const int led_pin = 13;         // default to pin 13
#endif



void encoder_read()  
{
  
  delayMicroseconds(5);
  //encoderPos = encoderPos + dead_zone_count; 
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

 if(encoderPos == 0){
  dead_zone_count++;
  pid_pwm++;
  //pid_pwm--;
 }
 else
 {
  pid_pwm = 50;
 // pid_pwm = -50;
 }
 pid_pwm = (pid_pwm>=255) ? 255: pid_pwm;
 pid_pwm = (pid_pwm<=-255) ? -255: pid_pwm;

 if(pid_pwm >0)motor_control(-1,pid_pwm);
 else motor_control(1,-pid_pwm);
 digitalWrite(check_pin, LOW);
 
 
}
void motor_control(int direc, int pwm)
{
  pwm = (pwm>=255) ? 255: pwm;
  pwm = (pwm<=-255) ? -255: pwm;
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
  pinMode(INA, OUTPUT);
  pinMode(PWM, OUTPUT);
  MsTimer2::set(50, timer); // 500ms period
  MsTimer2::start();
  interrupt_setup();
  Serial.begin(115200);
}

void loop()
{
  if(encoderPos < 2){
   Serial.print("encoderPos =");
   Serial.print(encoderPos);
   Serial.print(", dead_zone_count = ");
   Serial.println(dead_zone_count);
  }
  //backward 12 1
  //forward 11 -1
}
