int cdsPin = A0;
int cdsVal;
int echo = 3;     //IO 핀번호
int trig = 2;       //
unsigned long duration;
float distance;
void setup() {

   Serial.begin(9600);               
    pinMode(echo, INPUT);      
    pinMode(trig, OUTPUT);      //  
    while (!Serial) {
   }
   Serial.println("CLEARDATA"); 
   Serial.println("LABEL,Time,illumination"); 
  
    
}
void loop() {
  char i;
  duration = 0;
  for( i=0 ; i<10 ; i++)
  {
    // Trigger Signal output
    digitalWrite(trig, HIGH);   // 
     delay(10);
    digitalWrite(trig, LOW);  //
   
     // Echo Signal Input
    duration += pulseIn(echo, HIGH); 
     delay(10);
  }
  duration = duration/10;
 
  // Calcurate distance
  distance = ((float)(340*duration)/10000) / 2;
  Serial.print("DATA,TIME,");
  Serial.print(distance);
  Serial.println("cm");
  delay(100); 
}
