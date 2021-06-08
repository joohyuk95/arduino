// FND의 앞 두자리에 원하는 숫자를 표시

int aPinFndData[8] = {13, 12, 11, 10, 9, 8, 7, 6};
int aPinFndSel[6] = {5, 4, 3, 2, 1, 0};
uint8_t aFndData[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,
                        0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71}; //0부터 F까지 표현
void setup() {
  for (int i = 0; i < 8; ++i) {
    pinMode(aPinFndData[i], OUTPUT);
  }
  for (int i = 0; i < 6; ++i) {
    pinMode(aPinFndSel[i], OUTPUT);
  }
}

void loop() {
  for (int i = 1; i < 7; ++i) {
    fndDataOut(i);  //display 데이터
    fndSelOut(i);   //display 위치
    delay(1);
    
    fndSelOut(0); // display off
    delay(1);
  }
}

void fndSelOut(int data) // 출력하고싶은 digit를 선택, data = 1~4
{
  for (int i = 0; i < 6; ++i) {
    digitalWrite(aPinFndSel[i], HIGH);
  }      
  if (data < 7 && data > 0) {
    digitalWrite(aPinFndSel[data-1], LOW);    
  }
}

void fndDataOut(int data) // 출력할 값을 선택
{
  for (int i = 0; i < 8; ++i) {
    if (aFndData[data] & (0x01 << i)) {
      digitalWrite(aPinFndData[i], HIGH);  
    } else {
      digitalWrite(aPinFndData[i], LOW);
    }    
  }
}
