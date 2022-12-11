#include <MsTimer2.h>

#define encodrpinA1 2
#define encodrpinB1 3
#define INA 4
#define PWM 5
#define check_pin 6
// Switch on LED on and off each half second

volatile int32_t encoderPos = 0;
volatile int32_t encoderPos_old = 0;
int32_t target_Pos = 0;
int32_t pos_error = 0;
int32_t pos_error_old = 0;
int32_t pos_error_d = 0;

float p = 0.8;
float pd = 1.5;
float pi = 0.2;

int pid_pwm = 0;

long pos_error_sum = 0.0;

#if ARDUINO >= 100
const int led_pin = LED_BUILTIN;  // 1.0 built in LED pin var
#else
const int led_pin = 13;     // default to pin 13
#endif

void Timer()
{
  static boolean output = HIGH;
  
  digitalWrite(led_pin, output);
  digitalWrite(check_pin, output);
  output = !output;
  pos_error = target_Pos - encoderPos;
  pos_error_d = pos_error - pos_error_old;
  encoderPos_old = encoderPos;
  pos_error_sum += pos_error;
  pos_error_sum = (pos_error_sum > 50) ? 50 : pos_error_sum;
  pos_error_sum = (pos_error_sum < -50) ? -50 : pos_error_sum;

  if(abs(pos_error) <= 1)
  {
    pos_error_sum = 0;
  }
  pos_error_old = pos_error;

//  pid_pwm = pi*pos_error_sum + p*pos_error + pd*pos_error_d;

//  pid_pwm = (pos_error > (double)target_Pos * 0.5) ? 255 : pid_pwm;  Feedfoward control
   pid_pwm = pid_pwm > 255 ? 255 : pid_pwm;

  if(pid_pwm > 0)
  {
    motor_control(1, pid_pwm);
  }
  else{
    motor_control(-1, pid_pwm);
  }
  
  digitalWrite(check_pin, LOW);
}

void interrupt_setup(void)
{
  delayMicroseconds(50);
  pinMode(encodrpinA1, INPUT_PULLUP);                 
  pinMode(encodrpinB1, INPUT_PULLUP);             
  attachInterrupt(0, encoder, RISING);                               
}
  
void motor_control(int direc, int pwm)
{
  switch(direc)
  {
    case 1: digitalWrite(INA, HIGH);
            analogWrite(PWM,pwm);
            break;
    case 0: digitalWrite(INA, LOW);
            analogWrite(PWM,0);
            break;
    case -1: digitalWrite(INA, LOW);
            analogWrite(PWM,pwm);
            break;
  }
}

void encoder()  
{                                               
  if(digitalRead(encodrpinB1)==LOW){
    encoderPos++;            
  }
  else{
    encoderPos--;          
  }
}

void setup()
{
  pinMode(led_pin, OUTPUT);
  pinMode(check_pin, OUTPUT);
  MsTimer2::set(50, Timer); // 500ms period
  MsTimer2::start();
  interrupt_setup();
  Serial.begin(9600);
  target_Pos = 500;
}

void loop()
{   
    Serial.print(pos_error_d);
    Serial.print(",");
    //Serial.print("  pid_pwm: ");
    Serial.println(pid_pwm);

    pid_pwm++;
    delay(1000);
//  motor_control(-1, 23);   // foward 23  , backward 20
}
