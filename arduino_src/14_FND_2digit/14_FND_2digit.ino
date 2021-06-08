// 0 부터 F까지 1초마다 모든 FND 출력

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
    digitalWrite(aPinFndSel[0], LOW);
  }
}

void loop() {
  for (int j = 0; j < 16; ++j) {  
    for (int i = 0; i < 8; ++i) {
      if (aFndData[j] & (0x01 << i)) {
        digitalWrite(aPinFndData[i], HIGH);  
      } else {
        digitalWrite(aPinFndData[i], LOW);
      }    
    }
    delay(1000);
  }
}
