int pinLed = 0;
void setup() {
  Serial.begin(115200);
  Serial.println("Serial Test !!");
  Serial.print("ECHO >> ");
  pinMode(12, OUTPUT);
  digitalWrite(pinLed, HIGH);
}

void loop() {
  char data;
  if(Serial.available() > 0) {
    data = Serial.read();
    switch (data) {
      case 'A':
        pinLed = 12;
        break;
      case 'B':
        pinLed = 11;
        break;
      case 'C':
        pinLed = 10;
        break;
      case 'D':
        pinLed = 9;
        break;
      case 'E':
        pinLed = 8;
        break;
      case 'F':
        pinLed = 7;
        break;
      case 'G':
        pinLed = 6;
        break;
      case 'H':
        pinLed = 5;
        break;
    }

    digitalWrite(pinLed, HIGH);
    delay(1000);
    digitalWrite(pinLed, LOW);
    delay(1000);
  }
}
