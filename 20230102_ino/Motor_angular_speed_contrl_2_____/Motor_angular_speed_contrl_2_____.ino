/*
  MsTimer2 is a small and very easy to use library to interface Timer2 with
  humans. It's called MsTimer2 because it "hardcodes" a resolution of 1
  millisecond on timer2
  For Details see: http://www.arduino.cc/playground/Main/MsTimer2
*/
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

volatile float angular_speed = 0;
volatile float angular_speed_old = 0;

float target_angular_speed = 0;
float angular_speed_error = 0;
float angular_speed_error_old = 0;
float angular_speed_error_d = 0;
double angular_speed_error_sum = 0;

// PID gain angular position control
//float p = 1.6;
//float pd = 3.0;

// PID gain angular speed control
float pw = 1.2;
float pw_d = 2.01;
float pw_i = 3.4;

int pos_pid_pwm = 0;
int angular_pos_pid_pwm = 0;
int angular_speed_pid_pwm = 0;
int pwm = 0;

int dead_zone_threshold_positive = 14;
int dead_zone_threshold_negative = 13;

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

  //pos_pid_control();

  angular_speed = encoderPos - encoderPos_old;
  angular_speed_error = target_angular_speed - angular_speed;
  angular_speed_error_d = angular_speed - angular_speed_old;
  angular_speed_error_sum += angular_speed_error;
  
  angular_speed_error_sum = (angular_speed_error_sum > 100) ? (angular_speed_error_sum = 100) : (angular_speed_error_sum = angular_speed_error_sum);
  angular_speed_error_sum = (angular_speed_error_sum < -100) ? (angular_speed_error_sum = -100) : (angular_speed_error_sum = angular_speed_error_sum);

  angular_speed_pid_control();
  
  angular_speed_old = angular_speed;
  encoderPos_old = encoderPos;
  pos_error_old = pos_error;


//  if(angular_speed_pid_pwm > 0)
//  {
//    motor_control(1, angular_speed_pid_pwm);
//  }
//  
//  else{
//    motor_control(-1, angular_speed_pid_pwm);
//  }
  
  /*
  if(pos_pid_pwm > 0)
  {
    motor_control(1, pos_pid_pwm);
  }
  
  else{
    motor_control(-1, pos_pid_pwm);
  }
  */
  
  digitalWrite(check_pin, LOW);
}

int inverse_speed_mode(void)
{
  
  pwm = (10000*angular_speed_error + 26309)/3480;

  return pwm;
}
int angular_speed_pid_control(void){
  int angular_speed_pid_pwm1;
  angular_speed_pid_pwm1 = pw * angular_speed_error + pw_d * angular_speed_error_d + pw_i * angular_speed_error_sum;
  
  angular_speed_pid_pwm1 = (angular_speed_pid_pwm1 >= 255) ? angular_speed_pid_pwm1 = 255 : angular_speed_pid_pwm1 = angular_speed_pid_pwm1;
  angular_speed_pid_pwm1 = (angular_speed_pid_pwm1 <= -255) ? angular_speed_pid_pwm1 = -255 : angular_speed_pid_pwm1 = angular_speed_pid_pwm1;

  angular_speed_pid_pwm = dead_zone_pwm_correction(angular_speed_pid_pwm1);

  angular_speed_pid_pwm += inverse_speed_mode();
  if(angular_speed_pid_pwm > 0)
  {
    motor_control(1, angular_speed_pid_pwm);
  }
  
  else{
    motor_control(-1, -angular_speed_pid_pwm);
  }
}

int pos_pid_control(void){
  pos_pid_pwm = pw * angular_speed_error + pw_d * angular_speed_error_d;

  pos_pid_pwm = (pos_pid_pwm >= 255) ? pos_pid_pwm = 255 : pos_pid_pwm = pos_pid_pwm;
  pos_pid_pwm = (pos_pid_pwm <= -255) ? pos_pid_pwm = -255 : pos_pid_pwm = pos_pid_pwm;
}

int dead_zone_pwm_correction(int input_pwm){
  int pwm_out;

  if(input_pwm > 0)
  {
    pwm_out = input_pwm + dead_zone_threshold_positive;
  }
  else if(input_pwm < 0)
  {
    pwm_out = input_pwm - dead_zone_threshold_negative;
  }

  else{
    pwm_out = 0;
  }
  pwm_out = (pwm_out >= 255) ? pwm_out = 255 : pwm_out = pwm_out;
  pwm_out = (pwm_out <= -255) ? pwm_out = -255 : pwm_out = pwm_out;

  return pwm_out;
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
    case 1: digitalWrite(INA, LOW);
            analogWrite(PWM,pwm);
            break;
    case 0: digitalWrite(INA, LOW);
            analogWrite(PWM,0);
            break;
    case -1: digitalWrite(INA, HIGH);
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
  Serial.begin(115200);
  Serial.println("pos, pos_error");
  target_Pos = 0;
}

void loop()
{
  target_angular_speed = 20;
  Serial.print(angular_speed);
  Serial.print(", ");
  Serial.print(angular_speed_error);
  Serial.print(", ");
  Serial.print(angular_speed_error_d);
  Serial.print(", ");
  Serial.print(angular_speed_error_sum);
  Serial.print(", ");
  Serial.print(angular_speed_pid_pwm);
  Serial.print(", ");
  Serial.println(pwm);
  /*
  if(abs(pos_error) >= 5)
  {
    Serial.print("encoderpos : ");
    Serial.print(encoderPos);
    Serial.print(", angular_speed_error : ");
    Serial.print(angular_speed_error);
    Serial.print(", angular_speed_error_sum : ");
    Serial.print(angular_speed_error_sum);
    Serial.print(", angular_speed : ");
    Serial.println(angular_speed);
  }
  */
}
