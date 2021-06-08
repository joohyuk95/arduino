int pinSwitch0 = 2;
int pinSwitch1 = 3;
void setup() {
  Serial.begin(115200);
  pinMode(pinSwitch0, INPUT);
  pinMode(pinSwitch1, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinSwitch0), led_on, RISING);
  attachInterrupt(digitalPinToInterrupt(pinSwitch1), led_off, RISING);
}

void loop() {
}

void led_on()
{
  Serial.println("ON");
}

void led_off()
{
  Serial.println("OFF");
}
