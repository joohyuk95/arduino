int pinLed0 = 12;
int pinLed1 = 11;
int pinSwitch0 = 2;
int pinSwitch1 = 3;
int state0 = 0;
int state1 = 0;

void setup() {
  Serial.begin(115200);
  
  pinMode(pinLed0, OUTPUT);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinSwitch0, INPUT);
  pinMode(pinSwitch1, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(pinSwitch0), state0_change, RISING);
  attachInterrupt(digitalPinToInterrupt(pinSwitch1), state1_change, RISING);
}

void loop() {
  if (state0 == 1) {
    digitalWrite(pinLed0, HIGH);
    delay(500);
    digitalWrite(pinLed0, LOW);
    delay(500);
  } else {
    digitalWrite(pinLed0, LOW);
  }
  if (state1 == 1) {
    digitalWrite(pinLed1, HIGH);
    delay(300);
    digitalWrite(pinLed1, LOW);
    delay(300);
  } else {
    digitalWrite(pinLed1, LOW);
  }

}

void state0_change() {
  switch(state0) {
    case 1:
      state0 = 0;
      break;
    case 0:
      state0 = 1;
      break;
  }
}
void state1_change() {
  switch(state1) {
    case 1:
      state1 = 0;
      break;
    case 0:
      state1 = 1;
      break;
  }
}
