#include <MsTimer2.h>

// Front Motor Drive
#define MOTOR1_PWM 5
#define MOTOR1_ENA 6
#define MOTOR1_ENB 7

// Rear Motor Drive
#define MOTOR2_PWM 2
#define MOTOR2_ENA 3
#define MOTOR2_ENB 4

//////////protocal//////////////
char data_buffer[4] = {0};
char direction;

int f_speed = 0, r_speed = 0;

void F_MOTOR_CONTROL(int motor1_pwm)
{
   if (motor1_pwm > 0) // forward
  {
    digitalWrite(MOTOR1_ENA, HIGH);
    digitalWrite(MOTOR1_ENB, LOW);
    analogWrite(MOTOR1_PWM, motor1_pwm);
  }
  else if (motor1_pwm < 0) // backward
  {
    digitalWrite(MOTOR1_ENA, LOW);
    digitalWrite(MOTOR1_ENB, HIGH);
    analogWrite(MOTOR1_PWM, -motor1_pwm);
  }
  else
  {
    digitalWrite(MOTOR1_ENA, LOW);
    digitalWrite(MOTOR1_ENB, LOW);
    digitalWrite(MOTOR1_PWM, 0);
  }
}

void R_MOTOR_CONTROL(int MOTOR2_pwm)
{
   if (MOTOR2_pwm > 0) // forward
  {
    digitalWrite(MOTOR2_ENA, HIGH);
    digitalWrite(MOTOR2_ENB, LOW);
    analogWrite(MOTOR2_PWM, MOTOR2_pwm);
  }
  else if (MOTOR2_pwm < 0) // backward
  {
    digitalWrite(MOTOR2_ENA, LOW);
    digitalWrite(MOTOR2_ENB, HIGH);
    analogWrite(MOTOR2_PWM, -MOTOR2_pwm);
  }
  else
  {
    digitalWrite(MOTOR2_ENA, LOW);
    digitalWrite(MOTOR2_ENB, LOW);
    digitalWrite(MOTOR2_PWM, 0);
  }
}


void motor_control(int front_speed,int rear_speed)
{
  F_MOTOR_CONTROL(front_speed);
  R_MOTOR_CONTROL(rear_speed);  
}


 static boolean output = HIGH;
void control_callback()
{  
  digitalWrite(13, output);
  output =!output;
  motor_control(f_speed,r_speed);
}

void setup() {
  
  pinMode(13, OUTPUT);

 
  pinMode(MOTOR1_PWM, OUTPUT);
  pinMode(MOTOR1_ENA, OUTPUT); 
  pinMode(MOTOR1_ENB, OUTPUT);

  pinMode(MOTOR2_PWM, OUTPUT);
  pinMode(MOTOR2_ENA, OUTPUT); 
  pinMode(MOTOR2_ENB, OUTPUT);
  
  MsTimer2::set(10, control_callback); 
  MsTimer2::start();
  Serial.begin(115200);


}

void loop() {
  
  int data;
  String s;
  char Read_char;

  if (Serial.available() > 0) 
  {
    delay(4);
    Read_char = Serial.read();
    if (Read_char == 's')  // Speed Control
    {
      direction = Serial.read();
      
      for (int i = 0; i < 3; i++) 
      {
        data_buffer[i] = Serial.read();
      }
      Serial.write(data_buffer[0]);
      Serial.write(data_buffer[1]);
      Serial.write(data_buffer[2]);
      
      s = String(data_buffer);
      data = s.toInt();
      
      if(direction =='r') data = -data;
      
      Serial.print("  : ");      
      Serial.println(data);
      
      delay(1000);
      f_speed = data;
      r_speed = f_speed;
     }

  }
  Serial.print("front_Speed = ");
  Serial.print(f_speed);
  Serial.print("rear_Speed = ");
  Serial.println(r_speed);
  
}
