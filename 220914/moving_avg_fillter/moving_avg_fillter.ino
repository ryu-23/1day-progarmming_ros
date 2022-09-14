#define MASK_LENGTH   3
#define TRIG 9 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO 8 //ECHO 핀 설정 (초음파 받는 핀)


int raw_array[MASK_LENGTH] = {0,}; // 질문 지물 {0,} 이게 뭔가용???

int raw_array_index = 0;
float x;
/* make mean siez of MASK. */
float movingAverageFilter()
{
    int i = 0;
    int sum = 0;

    for (i = 0; i < MASK_LENGTH; i++) {
      sum += raw_array[i];
    }
    return ((float)sum / MASK_LENGTH);

    
}

/* inset new array */
void insertIntoRawArray(int value)
{
    raw_array[raw_array_index] = value;

    raw_array_index++;

    if (raw_array_index >= MASK_LENGTH) {
      raw_array_index = 0;
    }


}
void setup() {
  Serial.begin(9600); 
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.println("cm,avg");
}


void loop(){
  long duration, distance;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn (ECHO, HIGH); //물체에 반사되어돌아온 초음파의 시간을 변수에 저장합니다.
  //34000*초음파가 물체로 부터 반사되어 돌아오는시간 /1000000 / 2(왕복값이아니라 편도값이기때문에 나누기2를 해줍니다.)
  //초음파센서의 거리값이 위 계산값과 동일하게 Cm로 환산되는 계산공식 입니다. 수식이 간단해지도록 적용했습니다.
  distance = duration * 17 / 1000; 
  //PC모니터로 초음파 거리값을 확인 하는 코드 입니다.
  insertIntoRawArray(distance); //측정된 물체로부터 거리값(cm값)을 보여줍니다.
  Serial.print(distance);
  Serial.print(",");
  //Serial.print("movingAverageFilter = ");
  Serial.println(movingAverageFilter());
  delay(200); //0.2초마다 측정값을 보여줍니다.


  


}
