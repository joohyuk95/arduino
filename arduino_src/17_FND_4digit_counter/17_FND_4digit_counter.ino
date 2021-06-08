// FND의 앞 두자리에 원하는 숫자를 표시
#include <YetAnotherPcInt.h>

int sig = A0;
int vcc = A1;
int gnd = A2;

int aPinFndData[8] = {13, 12, 11, 10, 9, 8, 7, 6};
int aPinFndSel[6] = {5, 4, 3, 2, 1, 0};
uint8_t aFndData[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,
                        0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71}; //0부터 F까지 표현
void setup() {
  // FND
  for (int i = 0; i < 8; ++i) {
    pinMode(aPinFndData[i], OUTPUT);
  }
  for (int i = 0; i < 6; ++i) {
    pinMode(aPinFndSel[i], OUTPUT);
  }
  
  // mini reed
  pinMode(sig, INPUT);
  pinMode(vcc, OUTPUT);
  pinMode(gnd, OUTPUT);
  digitalWrite(vcc, HIGH);
  digitalWrite(gnd, LOW);

  PcInt::attachInterrupt(A0,number_counter, RISING);
}

int num = 0;

void loop() {
  FND6_Display(num);
}

void number_counter() {
  num += 100;
  delay(500);
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

void FND6_Display(int data) // 1자리에서 6자리까지 입력하면 그대로 출력
{
  int num_100000 = data / 100000;
  int num_10000 = (data%100000) / 10000;
  int num_1000 = (data%10000) / 1000;
  int num_100 = (data%1000) / 100;
  int num_10 = (data%100) / 10;
  int num_1 = (data%10);

  int nums[6] = {num_100000, num_10000, num_1000, num_100, num_10, num_1};
  
  for (int i = 0; i < 6; ++i) {
    fndDataOut(nums[i]);  //display 데이터
    fndSelOut(i+1);   //display 위치
    delay(1);
    
    fndSelOut(0); // display off
    delay(1);
  }  
}
