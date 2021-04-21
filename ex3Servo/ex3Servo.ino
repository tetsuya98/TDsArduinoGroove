#include <Servo.h>

Servo myservo;

const int PTM = A0; //Rotary Angle Sensor (Potentiometre)

int valuePTM;
int valueSRV;

void setup() {
  // put your setup code here, to run once:
  pinMode(PTM, INPUT);
  myservo.attach(3);
}

void loop() {
  // Valeur min du potentiometre
  if (valuePTM < 10)
  {
    valuePTM = 10;
  }
  // Valeur max du potentiometre
  if (valuePTM > 120)
  {
    valuePTM = 120;
  }
  
  // put your main code here, to run repeatedly:
  valueSRV = analogRead(PTM);
  valueSRV = map(valueSRV, 0, 1023, 10, 120);
  myservo.write(valueSRV);
  
  //delay(15);
}
