#include <Servo.h>

Servo myservo;

const int LED = 3;  //LED Socket Kit
const int RLY = 2; //Raley v1.2

int valueLED;
int valueSRV;
int valueRLY;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(RLY, OUTPUT);
  myservo.attach(6);
  Serial.begin(9600);
  
  Serial.println("Pour agir sur la LED, tapez L puis une valeur entre 0 et 255");
  Serial.println("Pour agir sur le servo, tapez S puis une valeur entre 10 et 120");
  Serial.println("Pour agir sur le relay, tapez R puis 1 ou 0");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0) {
    String s = Serial.readStringUntil('S'); //servo
    valueSRV = Serial.parseInt();
    String l = Serial.readStringUntil('L'); //LED
    valueLED = Serial.parseInt();
    String r = Serial.readStringUntil('R'); //Relay
    valueRLY = Serial.parseInt();

    Serial.print("servo : ");
    Serial.println(valueSRV);
    Serial.print("LED : ");
    Serial.println(valueLED);
    Serial.print("relay : ");
    Serial.println(valueRLY);

    // Valeur min du servomoteur
    if (valueSRV < 10)
    {
      valueSRV = 10;
    }
    // Valeur max du servomoteur
    if (valueSRV > 120)
    {
      valueSRV = 120;
    }
  
    // Valeur min du servomoteur
    if (valueLED < 0)
    {
      valueLED = 0;
    }
    // Valeur max du servomoteur
    if (valueLED > 255)
    {
      valueLED = 255;
    }
  
    // Valeur min du servomoteur
    if (valueRLY < 0)
    {
      valueRLY = 0;
    }
    // Valeur max du servomoteur
    if (valueRLY > 1)
    {
      valueRLY = 1;
    }
  
      
    valueSRV = map(valueSRV, 0, 1023, 10, 120);
    myservo.write(valueSRV);
  
    valueLED = map(valueLED, 0, 1023, 0, 255);
    analogWrite(LED, valueLED);
  
    if (valueRLY == 0) {
      digitalWrite(RLY, LOW); //Relay Off
    }else{
      digitalWrite(RLY, HIGH); //Relay On
    }
  }

}
