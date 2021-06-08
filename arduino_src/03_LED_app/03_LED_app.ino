int PinLed[8] = {12, 11, 10, 9, 8, 7, 6, 5};

void setup() {      // 초기화
  for (int i = 0; i < 8; ++i) {
    pinMode(PinLed[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; ++i) {
    digitalWrite(PinLed[i], HIGH);
    digitalWrite(PinLed[i+4], HIGH);
    delay(50);
    digitalWrite(PinLed[i], LOW);
    digitalWrite(PinLed[i+4], LOW);  
  }
  for (int i = 2; i > 0; --i) {
    digitalWrite(PinLed[i], HIGH);
    digitalWrite(PinLed[i+4], HIGH);
    delay(50);
    digitalWrite(PinLed[i], LOW);
    digitalWrite(PinLed[i+4], LOW);  
  }
}
