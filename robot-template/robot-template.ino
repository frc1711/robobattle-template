#include <SoftwareSerial.h>

int blueLedPin = 13;
int redLedPin = 14;
long baudRate = 9600;
//intialize motor pins
int m1 = 1;
int m2 = 2;
int m3 = 3;
int m4 = 4;
//intialize motor speed variables
int m1s = 0;
int m2s = 0;
int m3s = 0;
int m4s = 0;
int readstate = 1;
boolean isEnabled;
SoftwareSerial wifi(7, 8);


void setup() {
  // put your setup code here, to run once:

  pinMode(redLedPin, OUTPUT);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  wifi.begin(baudRate);
  while (!wifi.available())
  {
    
  }
}

void loop() {
  // put your main code here, to run repeatedly 
  // robot config 
  if (isEnabled == true)
  {
    //while timer for game time 
    if(!readstate){
    switch (wifi.read()){
    case 'a':
    readstate = 1;
    break;
    case 'b':
    readstate = 2;
    break;  
    case 'c':
    readstate = 3;
    break;
    case 'd':
    readstate = 4;
    break;
    default: 
    //error!!!!
    break;
    }
    }
    if(readstate != 0){
      if(readstate == 1&&wifi.read()!='a'){
         //create a numeric val for the motor from the char the arduino recieves
         char mspeedchar = wifi.read();
         m1s = map(int(mspeedchar - '0'),0,9,0,255);
        }
        if(readstate == 1&&wifi.read()!='b'){
         //create a numeric val for the motor from the char the arduino recieves
         char mspeedchar = wifi.read();
         m2s = map(int(mspeedchar - '0'),0,9,0,255);
        }
        if(readstate == 1&&wifi.read()!='c'){
         //create a numeric val for the motor from the char the arduino recieves
         char mspeedchar = wifi.read();
          m3s = map(int(mspeedchar - '0'),0,9,0,255);
        }
        if(readstate == 1&&wifi.read()!='d'){
         //create a numeric val for the motor from the char the arduino recieves
         char mspeedchar = wifi.read();
         m4s = map(int(mspeedchar - '0'),0,9,0,255);
        }
      }
      analogWrite(m1,m1s);
      analogWrite(m2,m2s);
      analogWrite(m3,m3s);
      analogWrite(m4,m4s);
    //USER CODE HERE for running 
    //after game ends return to robo config for robit  
  }
}
