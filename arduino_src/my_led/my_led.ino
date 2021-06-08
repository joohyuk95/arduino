int pinLed0 = 12;
int pinSwitch0 = 2;
boolean led0_state == false;

void setup() {
  Serial.begin(115200);
  
  pinMode(pinLed0, OUTPUT);
  pinMode(pinSwitch0, INPUT);
}

void loop() {
  if (digitalRead(pinSwitch0) == HIGH) }
    if(led0_state == false) {
      led0_state == true;
    } else {
      led0_state == false;
    }  

    Serial.println("Pushed SW0");
    delay(500);
  }
  
  if (led0_state == false) {
    digitalWrite(pinLed0, LOW);
  } else {
    digitalWrite(pinLed0, HIGH);
    delay(500);
    digitalWrite(pinLed0, HIGH);
    delay(500);
  }
}
