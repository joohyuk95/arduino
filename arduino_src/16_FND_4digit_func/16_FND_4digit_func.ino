// 6자리 숫자를 입력받으면 FND에 출력

int PinFndData[8] = {13, 12, 11, 10, 9, 8, 7, 6};
int PinFndSel[6] = {5, 4, 3, 2, 1, 0};
uint8_t FndData[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,
                        0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71}; //0부터 F까지 표현

void setup() {                           // FND 문자핀과 위치핀을 출력으로 설정
  for (int i = 0; i < 8; ++i) {
    pinMode(PinFndData[i], OUTPUT);
  }
  for (int i = 0; i < 6; ++i) {
    pinMode(PinFndSel[i], OUTPUT);
  }
}

long num = 424253;
void loop() {
  FND6_Display(num);
}

void fndSelOut(int data)        // 출력하고싶은 digit를 선택, data = 1~6
{
  for (int i = 0; i < 6; ++i) {           //출력안되게 high 값으로, active low니까
    digitalWrite(PinFndSel[i], HIGH);
  }      
  if (data != 0) {               // 입력된 위치핀만 LOW로
    digitalWrite(PinFndSel[data-1], LOW);    
  }
}

void fndDataOut(int data) // 출력할 값을 선택
{
  for (int i = 0; i < 8; ++i) {
    if (FndData[data] & (0x01 << i)) {
      digitalWrite(PinFndData[i], HIGH);  
    } else {
      digitalWrite(PinFndData[i], LOW);
    }    
  }
}

void FND6_Display(long long data) // 1자리에서 6자리까지 입력하면 그대로 출력
{
  int num_100000 = data / 100000;
  int num_10000 = (data % 100000) / 10000;
  int num_1000 = (data % 10000) / 1000;
  int num_100 = (data % 1000) / 100;
  int num_10 = (data % 100) / 10;
  int num_1 = (data % 10);

  int nums[6] = {num_100000, num_10000, num_1000, num_100, num_10, num_1};
  
  for (int i = 0; i < 6; ++i) {
    fndDataOut(nums[i]);  //display 데이터
    fndSelOut(i+1);   //display 위치
    delay(1);
    
    fndSelOut(0); // display off
    delay(1);
  }  
}
