// Sample Arduino MAX6675 Arduino Sketch

#include "max6675.h"

int ktcSO = 8;
int ktcCS = 9;
int ktcCS2 = 11;
int ktcCLK = 10;

int aPin = 0;
int rValue = 0;
float tp = 0;
float tpF = 0;

MAX6675 ktc(ktcCLK, ktcCS, ktcSO);
MAX6675 ktc2(ktcCLK, ktcCS2, ktcSO);

  
void setup() {
  Serial.begin(9600);
  // give the MAX a little time to settle
  delay(500);
}

void loop() {
  // basic readout test
  rValue = analogRead(aPin);
//Serial.println(readValue);
tp = (rValue * 0.0049);
tp = tp * 100;
tpF = (tp * 1.8) + 32;
Serial.print(tpF);
delay(10);

//sensor 1
   Serial.print(",");
   Serial.print(ktc.readFahrenheit());
delay(10);
//sensor 2   
    Serial.print(",");
   Serial.println(ktc2.readFahrenheit());
   delay(500);
}


