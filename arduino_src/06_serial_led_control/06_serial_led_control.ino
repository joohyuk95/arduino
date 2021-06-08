int pinLed[8] = {12, 11, 10, 9, 8, 7, 6, 5};

void setup() {
  Serial.begin(115200);                       // 통신속도 설정
  Serial.println("Serial LED Control !!");    
  Serial.print("ECHO >> ");

  for (int i = 0; i < 8; ++i)
    pinMode(pinLed[i], OUTPUT);                 // 각 핀을 출력으로 지정 ( 12 ~ 5 ) 8개

void loop() {
  char data = 0;
  if (Serial.available() > 0) {           // 수신된 데이터가 있으면, 수신 데이터의 개수를 반환
    data = Serial.read();                 // 시리얼 모니터에 입력한 값 읽기
    Serial.write(data);                   // 데이터 다시 PC로 송신

    int ledState[8];        
    for (int i = 0; i < 8; ++i)                 // 각 핀의 LED 점등 상태를 파악
      ledState[i] = digitalRead(pinLed[i]);

    int ledNum;                     // 입력한 문자를 LED 번호로 바꿔서 변수에 넣음
    switch (data) {
      case 'A':
        ledNum = 0;
        break;
      case 'B':
        ledNum = 1;
        break;
      case 'C':
        ledNum = 2;
        break;
      case 'D':
        ledNum = 3;
        break;
      case 'E':
        ledNum = 4;
        break;
      case 'F':
        ledNum = 5;
        break;
      case 'G':
        ledNum = 6;
        break;
      case 'H':
        ledNum = 7;
        break;         
    }

    if (data != 0) {
      if (ledState[ledNum] == HIGH) {
        digitalWrite(pinLed[ledNum], LOW);
      }
      else if (ledState[ledNum] == LOW) {    
        digitalWrite(pinLed[ledNum], HIGH);
      }
    }
  } 
}
