#include <SoftwareSerial.h>

int blueLedPin = 13;
int redLedPin = 14;
long baudRate;
boolean isEnabled;
SoftwareSerial wifi(7, 8);


void setup() {
  // put your setup code here, to run once:
  pinMode(blueLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  wifi.begin(baudRate);
  while (!wifi)
  {   
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (isEnabled == true)
  {
    
  }
}
