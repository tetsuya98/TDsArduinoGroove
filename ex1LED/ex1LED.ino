#define LED 4 //LED Socket Kit
#define BTN 2 //Button

int etatLED;
int etatBTNPrecedent;
int etatBTN;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  etatBTN = digitalRead(BTN);

  if (etatBTN != etatBTNPrecedent && etatBTN == HIGH) {
    etatLED = !etatLED;
    digitalWrite(LED, etatLED);
  }
  etatBTNPrecedent = etatBTN;
  

  

}
