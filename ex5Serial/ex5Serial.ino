#include <stdio.h>
#include <string.h>

const int PTM = A0; //Rotary Angle Sensor

int valuePTM;
char serialValue;
int curseur = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(PTM, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() )
  { 
    serialValue = char(Serial.read());  
    if (serialValue == 'A') {
      curseur = 1;
    }
    if (serialValue == 'd') {
      curseur = 2;
    }
    
    serialValue = "";
  }
  
  if (curseur == 1) {
    valuePTM = analogRead(PTM);
    Serial.print("Value PTM A : ");
    Serial.println(valuePTM);
    delay(100);
  }
  if (curseur == 2) {
    valuePTM = analogRead(PTM);
    Serial.print("Value PTM d : ");
    Serial.println(valuePTM);
    curseur = 0;
  }
}
