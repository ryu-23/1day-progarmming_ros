#include <MsTimer2.h>
#define encodPinA1      2 
#define encodPinB1      3                       // Quadrature encoder B pin
#define check_pin       11
#define DIR 4
#define PWM 5
volatile int32_t encoderPos = 0;
volatile int32_t encoderPos_old = 0;
int32_t velocity = 0;

float P = 0.4;
float Pd = 1.0;
float Pi = 0.5;

int pwm = 0;
int new_pwm = 0;
float pos_error_sum = 0;


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
  digitalWrite(check_pin, HIGH);
  output = !output;
  velocity = encoderPos - encoderPos_old;
  new_pwm = (0.9991*pwm + 0.0763)+10;
  new_pwm = (new_pwm>=255) ? 255 : new_pwm;
  if(pwm > 0) motor_control(1,new_pwm);
  else if(pwm <= 0) motor_control(-1,-new_pwm);
  
  encoderPos_old = encoderPos;
  
  digitalWrite(check_pin, LOW); //항상 시작과 끝에 있어야됨
}

void motor_control(int Direction, int pwm)
{
  pwm = (pwm>=255) ? 255 : pwm;
  switch(Direction)
  {
    case 1:
      digitalWrite(DIR,HIGH);
      analogWrite(PWM,pwm);
      break;
      
    case 0:
      digitalWrite(DIR,LOW);
      analogWrite(PWM,0);
      break;
      
    case -1:
      digitalWrite(DIR,LOW);
      analogWrite(PWM,pwm);  
      break;  
  }
}

void setup()
{

  pinMode(check_pin, OUTPUT);
  pinMode(DIR,OUTPUT);
  pinMode(PWM,OUTPUT);
  MsTimer2::set(50, timer); // 500ms period
  MsTimer2::start();
  interrupt_setup();
  Serial.begin(115200);
  Serial.println("velocity,pwm");
}

void loop()
{

    pwm++;
    delay(1000);
    Serial.print(velocity);
    Serial.print(", ");
    Serial.println(new_pwm);
  
  
}
