int pinLed0 = 12;
int pinSwitch0 = 2;

boolean pre_value = LOW, cur_value = LOW; // 스위치 이전값, 현재값

void setup() {
  Serial.begin(115200);
  pinMode(pinLed0, OUTPUT);
  pinMode(pinSwitch0, INPUT);
}

void loop() {
  cur_value = digitalRead(pinSwitch0); // 현재값을 읽어서 저장
  
  if (pre_value == LOW && cur_value == HIGH) {    //edge check
    if (digitalRead(pinLed0) == LOW) {
      digitalWrite(pinLed0, HIGH);
    } else {
      digitalWrite(pinLed0, LOW);
    }
  }
  // 현재값을 이전값에 저장
  pre_value = cur_value;
}
