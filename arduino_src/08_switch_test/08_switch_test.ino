int pinSwitch = 2;
int count = 0;
void setup() {
  Serial.begin(115200);
  pinMode(pinSwitch, INPUT);
}

void loop() {
  if (digitalRead(pinSwitch) == HIGH) {
    Serial.println("Pushed");
    ++count;
    Serial.println(count);
    delay(500);
  }
}
