#include <rgb_lcd.h>
#include <Wire.h>

rgb_lcd lcd;


const int PTM = A0; //Rotary Angle Sensor
const int TMP = A2; //Temperature Sensor
const int RLY = 2; //Raley v1.2
//LCD Screen on I2C Port

const int R0 = 100000;
const int B = 4275;

int colorR = 255;
int colorG = 255;
int colorB = 0;


int valuePTM;
int valueTMP;
int count;
float temp;
int printPTM;

void setup() {
  // put your setup code here, to run once:
  pinMode(PTM, INPUT);
  pinMode(RLY, OUTPUT);

  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);

  count = 0;
}

void loop() {
  if (count < 30) {
       valuePTM = analogRead(PTM);
       valueTMP = analogRead(TMP);

       printPTM = map(valuePTM, 1023, 0, 255, 0);
       // put your main code here, to run repeatedly:
       if (printPTM < 0)
       {
         printPTM = 0;
       }
       // Valeur max du potentiometre
       if (printPTM > 30)
       {
         printPTM = 30;
       }
       
       count++;
       delay(1);
   } else {
       temp = (1023.0 / valueTMP - 1.0) * R0;
       temp = 1.0 / (log(temp / R0) / B + 1 / 298.15) - 273.15;
       lcd.setCursor(0,0);
       lcd.print("Temp : ");
       lcd.print(temp);

       lcd.setCursor(0,1);
       lcd.print("Ptm : ");
       lcd.print(printPTM);

       if (temp < printPTM) { //RED
           int colorR = 255;
           int colorG = 0;
           int colorB = 0;
           lcd.setRGB(colorR, colorG, colorB);
           digitalWrite(RLY, HIGH); //Relay On
       }else{ //GREEN
           int colorR = 0;
           int colorG = 255;
           int colorB = 0;
           lcd.setRGB(colorR, colorG, colorB);
           digitalWrite(RLY, LOW); //Relay Off
       }
       
       count = 0;
   }
}
