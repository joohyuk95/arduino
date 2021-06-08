void setup() {
  Serial.begin(115200); // 통신 속도
  Serial.write('H');
  Serial.write('E');
  Serial.write('L');
  Serial.write('L');
  Serial.write('O');
  Serial.write('\n');

  Serial.println(78);
  Serial.println(1.23456, 5);
  Serial.println('N');
  Serial.println("Hello, world");
  pinMode(13, OUTPUT);
}


void loop() {
  digitalWrite(13, LOW);
}
