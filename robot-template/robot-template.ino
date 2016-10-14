#include <SoftwareSerial.h>

int blueLedPin = 13;
int redLedPin = 14;
long baudRate;
boolean isEnabled;
SoftwareSerial wifi(7, 8);


void setup() {
  // put your setup code here, to run once:

  pinMode(redLedPin, OUTPUT);
  wifi.begin(baudRate);
  while (!wifi)
  {
    
  }
}

void loop() {
  // put your main code here, to run repeatedly 
  // robot config 
  if (isEnabled == true)
  {
    //while timer for game time 
    //USER CODE HERE for running 
    //after game ends return to robo config for robit  
  }
}
