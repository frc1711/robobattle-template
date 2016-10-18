#include <SoftwareSerial.h>

int blueLedPin = 13;
int redLedPin = 14;
long baudRate = 9600;

// Intialize motor pins:
int motor1 = 1;
int motor2 = 2;
int motor3 = 3;
int motor4 = 4;

// Intialize motor speed variables:
int motor1Speed = 0;
int motor2Speed = 0;
int motor3Speed = 0;
int motor4Speed = 0;

int readState = 1;
boolean robotIsEnabled;
SoftwareSerial wifi(7, 8);

void setup() {
  
  pinMode(redLedPin, OUTPUT); // Remember to make an accommodation for the blueLedPin as well.
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);
  wifi.begin(baudRate);
  
  while (// WiFi is not available...)
  {
    // Empty.
  }
  
}

void loop() {
  
  // Robot configuration:
  if (robotIsEnabled == true)
  {
    // While timer for keeping track of game time.
    if(!readState){
      
      switch (mySerial.read()){ // mySerial is never declared.
        case 'a':
          readState = 1;
          break;
        case 'b':
          readState = 2;
          break;
        case 'c':
          readState = 3;
          break;
        case 'd':
          readState = 4;
          break;
        default: 
          // ERR
          break;
      }
    }
    if(readState != 0){
      
      if(readState == 1 && mySerial.read()!= 'a') { // mySerial is never declared.
         // Create a numerical value for the motor from the character the Arduino recieves.
         char motorSpeedChar = mySerial.read();
         motor1Speed = map(int(motorSpeedChar - '0'),0,9,0,255); // If you want to use a map, you'll want to find a library for Arduino called StandardCplusplus and import that, otherwise this won't compile.
        }
        
        if(readState == 1 && mySerial.read() != 'b') { // mySerial is never declared.
         // Create a numerical value for the motor from the character the Arduino recieves.
         char motorSpeedChar = mySerial.read();
         motor2Speed = map(int(motorSpeedChar - '0'),0,9,0,255); // If you want to use a map, you'll want to find a library for Arduino called StandardCplusplus and import that, otherwise this won't compile.
        }
        
        if(readState == 1 && mySerial.read() != 'c') { // mySerial is never declared.
         // Create a numerical value for the motor from the character the Arduino recieves.
         char motorSpeedChar = mySerial.read();
          motor3Speed = map(int(motorSpeedChar - '0'),0,9,0,255); // If you want to use a map, you'll want to find a library for Arduino called StandardCplusplus and import that, otherwise this won't compile.
        }
        
        if(readState == 1 && mySerial.read() != 'd'){ // mySerial is never declared.
         // Create a numerical value for the motor from the character the Arduino recieves.
         char motorSpeedChar = mySerial.read();
         motor4Speed = map(int(motorSpeedChar - '0'),0,9,0,255); // If you want to use a map, you'll want to find a library for Arduino called StandardCplusplus and import that, otherwise this won't compile.
        }
        
      }
      
      analogWrite(motor1,motor1Speed);
      analogWrite(motor2,motor2Speed);
      analogWrite(motor3,motor3Speed);
      analogWrite(motor4,motor4Speed);
      
    // USER CODE HERE for running...
    // After game ends, return to robot config for robot.
    
  }
  
}
