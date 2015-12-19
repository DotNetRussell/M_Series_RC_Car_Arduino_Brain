#include <SoftwareSerial.h>

const int BACKWARD_COMMAND = 1;
const int FORWARD_COMMAND = 2;
const int RIGHT_COMMAND = 3;
const int LEFT_COMMAND = 4;
const int STOP_COMMAND = 5;

const int FORWARD_PIN = 11;
const int BACKWARD_PIN = 10;
const int LEFT_PIN = 9;
const int RIGHT_PIN = 8;

const int TX_BT = 0;
const int RX_BT = 1;
 
SoftwareSerial btSerial(TX_BT, RX_BT);
 
const unsigned long periodicMessageFrequency = 5000;
unsigned long time = 0;
 
void GoForward(bool turnOn){
  if(turnOn){
    digitalWrite(FORWARD_PIN,HIGH);
  }
  else{
    digitalWrite(FORWARD_PIN,LOW);
  }
}

void GoBackward(bool turnOn){
  if(turnOn){
    digitalWrite(BACKWARD_PIN,HIGH);
  }
  else{
    digitalWrite(BACKWARD_PIN,LOW);
  }
}

void Turn(int direc){

  if(direc ==0){
    digitalWrite(LEFT_PIN,LOW);
    digitalWrite(RIGHT_PIN,LOW);
  }
  else if(direc == 1){
    digitalWrite(RIGHT_PIN,LOW);    
    digitalWrite(LEFT_PIN,HIGH);
  }
  else if(direc == 2){    
    digitalWrite(LEFT_PIN,LOW);
    digitalWrite(RIGHT_PIN,HIGH);
  }
  else{
    digitalWrite(LEFT_PIN,LOW);
    digitalWrite(RIGHT_PIN,LOW);
  }
}


//Setup Arduino function
void setup() {
  pinMode(FORWARD_PIN,OUTPUT);
  pinMode(BACKWARD_PIN,OUTPUT);
  pinMode(LEFT_PIN,OUTPUT);
  pinMode(RIGHT_PIN,OUTPUT);
  
  Serial.begin(9600);
  Serial.println("USB Connected");
  btSerial.begin(9600);
}

 int DEMO_MODE(int command){
    delay(2000);
    if(command < 5){
	return ++command;
    }
    else{
        command = 0;
	return command;
    }
}

void loop() {

  int command = btSerial.read(); 
 
  if(command != -1 && command != ' '){ 
    btSerial.flush();
   
    if(command > 0)
    {
      if(command == FORWARD_COMMAND){
        GoBackward(false);
        GoForward(true);
        Turn(0);      
      }
      else if(command == BACKWARD_COMMAND){
        GoForward(false);
        GoBackward(true);
        Turn(0); 
      }
      else if(command == LEFT_COMMAND){      
        GoBackward(false);
        GoForward(false);
        Turn(1); 
        
      }
      else if(command == RIGHT_COMMAND){ 
        GoBackward(false);
        GoForward(false);
        Turn(2); 
      }
      else if(command == STOP_COMMAND){
        GoBackward(false);
        GoForward(false);
        Turn(0); 
      }
    }  
  }  
}
