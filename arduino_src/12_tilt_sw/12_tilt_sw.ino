int vcc = 3;
int gnd = 4;
int sig = 2;

void setup() {
  Serial.begin(115200);

  pinMode(vcc, OUTPUT);
  pinMode(gnd, OUTPUT);
  pinMode(sig, INPUT);

  digitalWrite(gnd, LOW);
  digitalWrite(vcc, HIGH);

  attachInterrupt(digitalPinToInterrupt(sig), tilt_state_print, CHANGE);
}

void loop() {
}

void tilt_state_print() {
  if (!digitalRead(sig)) {
    Serial.println("Tilt on");
    delay(500);
  } else {
    Serial.println("Tilt off");
    delay(500);
  }
}
