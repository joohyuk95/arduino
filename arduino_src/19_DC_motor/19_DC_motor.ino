int pinPos = 5;
int pinNeg = 4;
int pinEn = 3;

void setup() {
  Serial.begin(115200);
  pinMode(pinPos, OUTPUT);
  pinMode(pinNeg, OUTPUT);
  pinMode(pinEn, OUTPUT);

}

void loop() {                 // CW -> stop -> CCW -> brake
  // CW
  digitalWrite(pinPos, HIGH);
  digitalWrite(pinNeg, LOW);
  digitalWrite(pinEn, HIGH);
  delay(1000);
  // stop
  digitalWrite(pinPos, LOW);
  digitalWrite(pinNeg, LOW);
  digitalWrite(pinEn, HIGH);
  delay(1000);
  // CCW
  digitalWrite(pinPos, LOW);
  digitalWrite(pinNeg, HIGH);
  digitalWrite(pinEn, HIGH);
  delay(1000);
  // brake
  digitalWrite(pinPos, LOW);
  digitalWrite(pinNeg, HIGH);
  digitalWrite(pinEn, LOW);
  delay(1000);
}
