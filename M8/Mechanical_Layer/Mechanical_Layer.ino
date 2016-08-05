#include <AFMotor.h>

AF_DCMotor leftMotors(3);
AF_DCMotor rightMotors(4);

const int STOP_PIN = A0;
const int FORWARD_PIN = A2;
const int BACKWARD_PIN = A3;
const int LEFT_PIN = A0;
const int RIGHT_PIN = A1;

void StopAll(){
   leftMotors.run(RELEASE);
   rightMotors.run(RELEASE);
}

void GoForward(){
   leftMotors.run(FORWARD);
   rightMotors.run(FORWARD);
}

void GoBackward(){   
   leftMotors.run(BACKWARD);
   rightMotors.run(BACKWARD);
}

void TurnLeft(){
   leftMotors.run(BACKWARD);
   rightMotors.run(FORWARD);
}

void TurnRight(){
   leftMotors.run(FORWARD);
   rightMotors.run(BACKWARD);
}


void DEMO_MODE(){ 
  
    Serial.println("FORWARD");
    GoForward();
    delay(2000);

    Serial.println("BACKWARD");
    GoBackward(); 
    delay(2000);

    Serial.println("LEFT");
    TurnLeft();
    delay(2000);
  
    Serial.println("RIGHT");
    TurnRight();  
    delay(2000);
    
    StopAll();  
    delay(3000);    
}

void setup() {
  Serial.begin(9600);
    
  // turn on motor
  leftMotors.setSpeed(255); 
  leftMotors.run(RELEASE);
  
  // turn on motor
  rightMotors.setSpeed(255); 
  rightMotors.run(RELEASE); 
}

void loop() {  
  
  if(digitalRead(FORWARD_PIN)){
    Serial.println("FORWARD");
    GoForward();  
  }
  else if(digitalRead(BACKWARD_PIN)){
    Serial.println("BACKWARD");
    GoBackward();
  }
  else if(digitalRead(LEFT_PIN)){
    //Serial.println("LEFT");
    TurnLeft();
  }
  else if(digitalRead(RIGHT_PIN)){
    Serial.println("RIGHT");
    TurnRight();
  }
  else{
    Serial.println("STOP");
    StopAll();  
  }
}



