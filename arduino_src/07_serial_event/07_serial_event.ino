void setup() {
  Serial.begin(115200);
  Serial.println("Serial Test !!");
  Serial.print("ECHO >>");
}

void loop() {


}

void serialEvent(void) {  // 데이터가 수신되면 자동으로 호출
  char data;
  data = serial.read();
  Serial.print(data);
}
