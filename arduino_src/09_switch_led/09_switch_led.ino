int pinLed0 = 12;
int pinLed1 = 11;
int pinSwitch0 = 2;
int pinSwitch1 = 3;

void setup() {
  Serial.begin(115200);
  pinMode(pinLed0, OUTPUT);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinSwitch0, INPUT);
  pinMode(pinSwitch1, INPUT);
}

void loop() {
  if (digitalRead(pinSwitch0) == HIGH) {
    if (digitalRead(pinLed0) == LOW) {
      digitalWrite(pinLed0, HIGH);
    } else {
      digitalWrite(pinLed0, LOW);
    }
    delay(500);
  }
  
  if (digitalRead(pinSwitch1) == HIGH) {
    if (digitalRead(pinLed1) == LOW) {
      digitalWrite(pinLed1, HIGH);
    } else {
      digitalWrite(pinLed1, LOW);
    }
    delay(500);
  }
}
