#include <rgb_lcd.h>
#include <Wire.h>

rgb_lcd lcd;

const int LGT = A0; //Light Sensor
const int TMP = A2; //Temperature Sensor

const int R0 = 100000;
const int B = 4275;

const int colorR = 255;
const int colorG = 255;
const int colorB = 0;

int count;
int valueLGT;
int valueTMP;
float light;
float temp;

void setup() 
{
    pinMode(LGT, INPUT);
    pinMode(TMP, INPUT);

    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);
    
    count = 0;
}

void loop() 
{
   if (count < 30) {
       valueLGT = analogRead(LGT);
       valueTMP = analogRead(TMP);
       count++;
       delay(1);
   } else {
       light = valueLGT * 5.0 / 1023.0;
       lcd.setCursor(0,0);
       lcd.print("Lux : ");
       lcd.print(light); 

       temp = (1023.0 / valueTMP - 1.0) * R0;
       temp = 1.0 / (log(temp / R0) / B + 1 / 298.15) - 273.15;
       lcd.setCursor(0,1);
       lcd.print("Temp : ");
       lcd.print(temp);
       
       count = 0;
   }
   
}
