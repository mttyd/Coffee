#include <SoftwareSerial.h>
#include "max6675.h"
SoftwareSerial BT(2, 3); 
int ktcSO = 8;
int ktcCS = 9;
int ktcCS2 = 11;
int ktcCLK = 10;

MAX6675 ktc(ktcCLK, ktcCS, ktcSO);
MAX6675 ktc2(ktcCLK, ktcCS2, ktcSO);


// creates a "virtual" serial port/UART
// connect BT module TX to D2
// connect BT module RX to D3
// connect BT Vcc to 5V, GND to GND
void setup()  
{
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  Serial.begin(9600);
  // give the MAX a little time to settle
  delay(500);
}
char a; // stores incoming character from other device
void loop() 
{
  if (BT.available())
  // if text arrived in from BT serial...
  {
    a=(BT.read());
    if (a=='1')
    {
      //output temps to BT
      for(int i = 0; i<50; i++){
        //sensor 1
        BT.print(ktc.readFahrenheit());
        delay(10);
        //sensor 2   
        BT.print(",");
        BT.println(ktc2.readFahrenheit());
        delay(500);
        i=BT.read();
        //sensor 1 serial
        Serial.print(ktc.readFahrenheit());
        delay(10);
        //sensor 2 serial 
         Serial.print(",");
         Serial.println(ktc2.readFahrenheit());
         delay(500);
      }    
    }
  }
}
