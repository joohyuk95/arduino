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
  digitalWrite(pinled0, HIGH);
}

void loop() {
  int adcData = analogRead(pinCds);
  double adcled = adcData * (255.0/1023);
  LED_control_by_CDS(adcled);
  double voltage = adcData * (5.0 / 1024);
  Serial.print("CDS :");
  Serial.print(adcData);
  Serial.print("  Volt :");
  Serial.println(voltage, 2);
  delay(500);
}

void LED_control_by_CDS(double duty)
{
  analogWrite(pinled0, duty);
}
