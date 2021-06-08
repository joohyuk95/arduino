int pinLed0 = 12;
int pinLed1 = 11;
int pinSwitch0 = 2;
int pinSwitch1 = 3;

boolean pre_value = LOW, cur_value = LOW; // 스위치 이전값, 현재값

void setup() {
  Serial.begin(115200);
  pinMode(pinLed0, OUTPUT);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinSwitch0, INPUT);
  pinMode(pinSwitch1, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinSwitch0), led0_state_change, RISING);
  attachInterrupt(digitalPinToInterrupt(pinSwitch1), led1_state_change, RISING);
}

void loop() {
}

void led0_state_change()    // 스위치 눌렀을 때 할일
{
  if (digitalRead(pinLed0) == LOW) {
    digitalWrite(pinLed0, HIGH);
  } else {
    digitalWrite(pinLed0, LOW);
  }
}


void led1_state_change()    // 스위치 눌렀을 때 할일
{
  if (digitalRead(pinLed1) == LOW) {
    digitalWrite(pinLed1, HIGH);
  } else {
    digitalWrite(pinLed1, LOW);
  }
}
