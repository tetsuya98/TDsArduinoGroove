
const int PTM = A0; //Rotary Angle Sensor (Potentiometre)
const int LED = 3;  //LED Socket Kit

int valuePTM;
int valueLED;

void setup() {
  // put your setup code here, to run once:
  pinMode(PTM, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valuePTM = analogRead(PTM);
  valueLED = map(valuePTM, 0, 1023, 0, 255);
  analogWrite(LED, valueLED);
  //delay(1000);
}
