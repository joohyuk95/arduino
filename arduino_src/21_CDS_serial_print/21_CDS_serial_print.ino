int pinCds = A0;
int pinVcc = A1;
int pinGnd = A2;

void setup() {
  Serial.begin(115200);
  
  pinMode(pinCds, INPUT);
  pinMode(pinVcc, OUTPUT);
  pinMode(pinGnd, OUTPUT);
  digitalWrite(pinVcc, HIGH);
  digitalWrite(pinGnd, LOW);
}

void loop() {
  int adcData = analogRead(pinCds);
  double voltage = adcData * (5.0 / 1024);
  Serial.print("CDS :");
  Serial.print(adcData);
  Serial.print("  Volt :");
  Serial.println(voltage, 2);
  delay(500);
}
