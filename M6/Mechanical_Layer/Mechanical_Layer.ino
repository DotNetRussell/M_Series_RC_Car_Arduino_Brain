#include <AFMotor.h>

AF_DCMotor frontleft(1);
AF_DCMotor backleft(2);
AF_DCMotor frontright(3);
AF_DCMotor backright(4);


int forwardPin = 0; 
int backwardPin = 1; 
int turnLeftPin = 2; 
int turnRightPin = 3; 

void stopAll(){
   frontleft.run(RELEASE);
   backleft.run(RELEASE);
   frontright.run(RELEASE);
   backright.run(RELEASE);
}

void goForward(){
   frontleft.run(BACKWARD);
   backleft.run(BACKWARD);
   frontright.run(BACKWARD);
   backright.run(BACKWARD); 
}

void goBackward(){   
   frontleft.run(FORWARD);
   backleft.run(FORWARD);
   frontright.run(FORWARD);
   backright.run(FORWARD);
}

void turnLeft(){
   frontleft.run(FORWARD);
   backleft.run(FORWARD);
   frontright.run(BACKWARD);
   backright.run(BACKWARD); 
}

void turnRight(){
   frontleft.run(BACKWARD);
   backleft.run(BACKWARD);
   frontright.run(FORWARD);
   backright.run(FORWARD); 
}


void DEMO_MODE(){ 
  
    Serial.println("FORWARD");
    goForward();
    delay(2000);

    Serial.println("BACKWARD");
    goBackward(); 
    delay(2000);

    Serial.println("LEFT");
    turnLeft();
    delay(2000);
  
    Serial.println("RIGHT");
    turnRight();  
    delay(2000);
    
    stopAll();  
    delay(3000);    
}

void setup() {
  Serial.begin(9600);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  
  // turn on motor
  frontleft.setSpeed(255); 
  frontleft.run(RELEASE);
  
    // turn on motor
  backleft.setSpeed(255); 
  backleft.run(RELEASE);
  
    
  // turn on motor
  frontright.setSpeed(255); 
  frontright.run(RELEASE);
  
    // turn on motor
  backright.setSpeed(255); 
  backright.run(RELEASE);
}

void loop() {
 
    int f = 0;
    int b = 0;
    int l = 0;
    int r = 0;    
    
    f = digitalRead(A0);
    b = digitalRead(A1);
    l = digitalRead(A2);
    r = digitalRead(A3);    
    
    if(f != 0)
    {
      goForward();
    } 
    else if(b != 0)
    {
      goBackward(); 
    }
    else if(l != 0)
    {
      turnLeft();
    }
    else if(r != 0)
    {
      turnRight();  
    }
    else 
    {
     stopAll(); 
    }  
}



