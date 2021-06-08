int PinLed = 13;

void setup() {      // 초기화
  pinMode(PinLed, OUTPUT);
}

void loop() {
  digitalWrite(PinLed, HIGH);
  delay(1000);
  digitalWrite(PinLed, LOW);
  delay(1000);
}
