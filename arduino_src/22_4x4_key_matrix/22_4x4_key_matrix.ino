int pinRow[4] = {13, 12, 11, 10};
int pinCol[4] = {9, 8, 7, 6};

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 4; ++i) {
    pinMode(pinRow[i], OUTPUT);
    pinMode(pinCol[i], INPUT);
  }
}

void loop() {
  int nRow, nColumn, nNumber;
  for (int i = 0; i < 4; ++i) {
    digitalWrite(pinRow[i], HIGH);
    nRow = 0;
    nRow = i*4;
    for (int j = 0; j < 4; ++j) {
      nColumn = 0;
      nColumn += j;
      if (digitalRead(pinCol[j])) {
        nNumber = nRow + nColumn;
        Serial.print("KEY [");
        Serial.print(nNumber, HEX);
        Serial.println("] PUSH");
      }
    }
    digitalWrite(pinRow[i], LOW);
    delay(100);
  }
}
