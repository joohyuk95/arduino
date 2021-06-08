#define duty_rate 25

int pinPos = 5;
int pinNeg = 4;
int pinPwm = 3;

void setup() {
  Serial.begin(115200);
  pinMode(pinPos, OUTPUT);
  pinMode(pinNeg, OUTPUT);
  pinMode(pinPwm, OUTPUT);

}

void loop() {                 // CW -> stop -> CCW -> brake
  motor_cntl(1, 255);
  motor_cntl(2, 255);
  motor_cntl(3, 255);
  motor_cntl(4, 255);
}


void motor_cntl(int mode, char speed) 
{
  analogWrite(pinPwm, speed);
  switch (mode) {
    case 1: // CW
      digitalWrite(pinPos, HIGH);
      digitalWrite(pinNeg, LOW);
      delay(1000);
      break;
    case 2:
      digitalWrite(pinPos, LOW);
      digitalWrite(pinNeg, LOW);
      delay(1000);
      break;
    case 3:
      digitalWrite(pinPos, LOW);
      digitalWrite(pinNeg, HIGH);
      delay(1000);
      break;
    case 4:
      digitalWrite(pinPos, LOW);
      digitalWrite(pinNeg, HIGH);
      delay(1000); 
      break;     
  }
}
