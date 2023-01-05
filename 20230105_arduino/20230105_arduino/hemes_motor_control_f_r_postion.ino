#include <MsTimer2.h>
#include <SPI.h>

// Rear Motor Drive
#define MOTOR1_PWM 2
#define MOTOR1_ENA 3
#define MOTOR1_ENB 4

// Front Motor Drive
#define MOTOR2_PWM 5
#define MOTOR2_ENA 6
#define MOTOR2_ENB 7
//////////encoder count///////////////
#define ENC1_ADD 22
#define ENC2_ADD 23
signed long encoder1count = 0;
signed long encoder2count = 0;
/////////postion control////////////////
//latile int32_t encoder1count = 0;
volatile int32_t encoder1count_old = 0;

int f_speed = 0, r_speed = 0;


int32_t target_Pos = 0;
int32_t pos_error = 0;
int32_t pos_error_old = 0;
int32_t pos_error_d = 0;
int32_t pos_error_sum = 0;

float P = 3.0;
float Pd = 5.0;
float Pi = 0.25;

int pos_pid_pwm = 0;

int pos_pid_control(void){
  pos_pid_pwm = P * pos_error + Pd * pos_error_d + Pi *pos_error_sum ;

  pos_pid_pwm = (pos_pid_pwm >= 135) ? 135 : pos_pid_pwm;
  pos_pid_pwm = (pos_pid_pwm <= -135) ? -135 : pos_pid_pwm;

  motor_control(pos_pid_pwm);
}

void Timer()
{
  //static boolean output = HIGH;
  
 // digitalWrite(led_pin, output);
//  digitalWrite(check_pin, output);
//  output = !output;

  pos_error = target_Pos - encoder2count;
  pos_error_d = pos_error - pos_error_old;
  
  pos_error_sum += pos_error;
  pos_error_sum = (pos_error_sum > 50) ? 50 : pos_error_sum;
  pos_error_sum = (pos_error_sum < -50) ? -50: pos_error_sum;
  if(fabs(pos_error)<=2) pos_error_sum = 0;
  
  pos_pid_control();
  
//pid

//  angular_speed_old = angular_speed;
 // encoder1count_old = encoder2count;
  pos_error_old = pos_error;
  
//  digitalWrite(check_pin, LOW);
}


void initEncoders() {
  
  // Set slave selects as outputs
  pinMode(ENC1_ADD, OUTPUT);
  pinMode(ENC2_ADD, OUTPUT); 
  
  // Raise select pins
  // Communication begins when you drop the individual select signsl
  digitalWrite(ENC1_ADD,HIGH);
  digitalWrite(ENC2_ADD,HIGH);
 
  SPI.begin();
  
  // Initialize encoder 1
  //    Clock division factor: 0
  //    Negative index input
  //    free-running count mode
  //    x4 quatrature count mode (four counts per quadrature cycle)
  // NOTE: For more information on commands, see datasheet
  digitalWrite(ENC1_ADD,LOW);        // Begin SPI conversation
  SPI.transfer(0x88);                       // Write to MDR0
  SPI.transfer(0x03);                       // Configure to 4 byte mode
  digitalWrite(ENC1_ADD,HIGH);       // Terminate SPI conversation 

  // Initialize encoder 2
  //    Clock division factor: 0
  //    Negative index input
  //    free-running count mode
  //    x4 quatrature count mode (four counts per quadrature cycle)
  // NOTE: For more information on commands, see datasheet
  digitalWrite(ENC2_ADD,LOW);        // Begin SPI conversation
  SPI.transfer(0x88);                       // Write to MDR0
  SPI.transfer(0x03);                       // Configure to 4 byte mode
  digitalWrite(ENC2_ADD,HIGH);       // Terminate SPI conversation 
}

long readEncoder(int encoder_no) 
{  
  // Initialize temporary variables for SPI read
  unsigned int count_1, count_2, count_3, count_4;
  long count_value;   
  
  digitalWrite(ENC1_ADD + encoder_no-1,LOW);      // Begin SPI conversation
   // digitalWrite(ENC4_ADD,LOW);      // Begin SPI conversation
  SPI.transfer(0x60);                     // Request count
  count_1 = SPI.transfer(0x00);           // Read highest order byte
  count_2 = SPI.transfer(0x00);           
  count_3 = SPI.transfer(0x00);           
  count_4 = SPI.transfer(0x00);           // Read lowest order byte
  digitalWrite(ENC1_ADD+encoder_no-1,HIGH);     // Terminate SPI conversation 
  //digitalWrite(ENC4_ADD,HIGH);      // Begin SPI conversation
// Calculate encoder count
  count_value= ((long)count_1<<24) + ((long)count_2<<16) + ((long)count_3<<8 ) + (long)count_4;
  
  return count_value;
}

void clearEncoderCount(int encoder_no) {    
  // Set encoder1's data register to 0
  digitalWrite(ENC1_ADD+encoder_no-1,LOW);      // Begin SPI conversation  
  // Write to DTR
  SPI.transfer(0x98);    
  // Load data
  SPI.transfer(0x00);  // Highest order byte
  SPI.transfer(0x00);           
  SPI.transfer(0x00);           
  SPI.transfer(0x00);  // lowest order byte
  digitalWrite(ENC1_ADD+encoder_no-1,HIGH);     // Terminate SPI conversation 
  
  delayMicroseconds(100);  // provides some breathing room between SPI conversations
  
  // Set encoder1's current data register to center
  digitalWrite(ENC1_ADD+encoder_no-1,LOW);      // Begin SPI conversation  
  SPI.transfer(0xE0);    
  digitalWrite(ENC1_ADD+encoder_no-1,HIGH);     // Terminate SPI conversation 
}

////////////////////////////////
//////////protocal//////////////
char data_buffer[5] = {0};
char direction;



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
    digitalWrite(MOTOR2_ENA, LOW);
    digitalWrite(MOTOR2_ENB, HIGH);
    analogWrite(MOTOR2_PWM, MOTOR2_pwm);
  }
  else if (MOTOR2_pwm < 0) // backward
  {
    digitalWrite(MOTOR2_ENA, HIGH);
    digitalWrite(MOTOR2_ENB, LOW);
    analogWrite(MOTOR2_PWM, -MOTOR2_pwm);
  }
  else
  {
    digitalWrite(MOTOR2_ENA, LOW);
    digitalWrite(MOTOR2_ENB, LOW);
    digitalWrite(MOTOR2_PWM, 0);
  }
}


void motor_control(int set_speed)
{
  F_MOTOR_CONTROL(set_speed);
  R_MOTOR_CONTROL(set_speed);  
}


 static boolean output = HIGH;
/*void control_callback()
{  
  digitalWrite(13, output);
  output =!output;
  motor_control(f_speed);
}
*/
void setup() {
  
  pinMode(13, OUTPUT);

 
  pinMode(MOTOR1_PWM, OUTPUT);
  pinMode(MOTOR1_ENA, OUTPUT); 
  pinMode(MOTOR1_ENB, OUTPUT);

  pinMode(MOTOR2_PWM, OUTPUT);
  pinMode(MOTOR2_ENA, OUTPUT); 
  pinMode(MOTOR2_ENB, OUTPUT);
  ///////////////////encoder count////////////////////
  initEncoders();          // initialize encoder
  clearEncoderCount(1); 
  clearEncoderCount(2); 
  
  MsTimer2::set(50, Timer); 
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
    encoder1count = 0;
    encoder1count_old = 0;
    target_Pos = 0;
    clearEncoderCount(1);
    clearEncoderCount(2);
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
      pos_pid_pwm = data;
      r_speed = pos_pid_pwm;
     }
     if (Read_char == 'p') 
    {
    encoder1count = 0;
    encoder2count = 0;
    encoder1count_old = 0;
    target_Pos = 0;
    clearEncoderCount(1);
    clearEncoderCount(2);
      direction = Serial.read();
      

   
      for (int i = 0; i < 4; i++) 
      {
        data_buffer[i] = Serial.read();
      }
      
      Serial.write(data_buffer[0]);
      Serial.write(data_buffer[1]);
      Serial.write(data_buffer[2]);
      Serial.write(data_buffer[3]);
      s=String(data_buffer);
      data = s.toInt();
      if(direction =='r') data = -data;
      Serial.print("  : ");      
      Serial.println(data);
      //target_angular_speed = data;

      delay(1000);
      target_Pos = data;
      
     }

  }
 /* Serial.print("front_Speed = ");
  Serial.print(f_speed);
  Serial.print("rear_Speed = ");
  Serial.println(r_speed);*/
  ////////////////////////encoder count/////////////////////////
  encoder1count = -readEncoder(1);
  encoder2count = -readEncoder(2);

  Serial.print("target_Pos = ");
  Serial.print(target_Pos);
  Serial.print(" encodercount = ");
  Serial.print(encoder2count);
  Serial.print(" pos_error = ");
  Serial.print(pos_error);
  Serial.print(" pos_pid_pwm = ");
  Serial.println(pos_pid_pwm);
  
}
