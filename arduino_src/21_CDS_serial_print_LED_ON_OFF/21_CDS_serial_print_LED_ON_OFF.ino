int pinCds = A0;
int pinVcc = A1;
int pinGnd = A2;
int pinled0 = 3;

void setup() {
  Serial.begin(115200);
  
  pinMode(pinCds, INPUT);
  pinMode(pinVcc, OUTPUT);
  pinMode(pinGnd, OUTPUT);
  pinMode(pinled0, OUTPUT);
  
  digitalWrite(pinVcc, HIGH);
  digitalWrite(pinGnd, LOW);
}

void loop() {
  int adcData = analogRead(pinCds);
  LED_control_by_CDS(adcData);
  double voltage = adcData * (5.0 / 1024);
  Serial.print("CDS :");
  Serial.print(adcData);
  Serial.print("  Volt :");
  Serial.println(voltage, 2);
  delay(500);
}

void LED_control_by_CDS(int adcData)
{
  if (adcData > 600) {
    digitalWrite(pinled0, HIGH);
  } else {
    digitalWrite(pinled0, LOW);
  }
}
