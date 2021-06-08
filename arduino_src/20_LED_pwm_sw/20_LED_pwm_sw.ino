// 스위치 3개를 이용해서 모터의 속도 조절
// sw0 : duty cycle 25씩 증가 (인터럽트 사용)
// sw1 : 25씩 감소
// sw2 : 모터 정지

#include <YetAnotherPcInt.h>
#define PCINT_PIN8 8
#define PCINT_PIN9 9
#define PCINT_PIN10 10
#define led0 11

unsigned char velocity = 0;
int pinPos = 5;
int pinNeg = 4;
int pinPwm = 3;

void setup() {
  Serial.begin(115200);

  pinMode(led0, OUTPUT);

  pinMode(pinPos, OUTPUT);
  pinMode(pinNeg, OUTPUT);
  pinMode(pinPwm, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  
  PcInt::attachInterrupt(PCINT_PIN8, duty_up, RISING);
  PcInt::attachInterrupt(PCINT_PIN9, duty_down, RISING);
  PcInt::attachInterrupt(PCINT_PIN10, motor_stop, RISING);
}

void loop() {                 // CW -> stop -> CCW -> brake
  analogWrite(led0, velocity);
}


void motor_cntl(int mode) 
{
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

void duty_up()
{
  if (velocity <= 230) {
    velocity += 25;
    Serial.println(velocity);
  } else {
    velocity = 255;
    Serial.println(velocity);
  }
  analogWrite(pinPwm, velocity);
}
void duty_down()
{
  if (velocity >= 25) {
    velocity -= 25;
    Serial.println(velocity);
  } else {
    velocity = 0;
    Serial.println(velocity);
  }
  analogWrite(pinPwm, velocity);
}
void motor_stop()
{
  velocity = 0;
  Serial.println(velocity);
  analogWrite(pinPwm, velocity);
}
