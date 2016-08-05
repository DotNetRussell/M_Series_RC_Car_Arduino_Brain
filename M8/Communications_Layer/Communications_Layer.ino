#include <SoftwareSerial.h>

const int FORWARD_COMMAND = 1;
const int BACKWARD_COMMAND = 2;
const int LEFT_COMMAND = 3;
const int RIGHT_COMMAND = 4;
const int STOP_COMMAND = 5;

const int FORWARD_PIN = 13;
const int BACKWARD_PIN = 12;
const int LEFT_PIN = 7;
const int RIGHT_PIN = 10;

const int TX_BT = 0;
const int RX_BT = 1;

int command = 0;

SoftwareSerial btSerial(TX_BT, RX_BT);

void GoForward() {
  //Serial.println("Go Forward");
  digitalWrite(BACKWARD_PIN, LOW);
  digitalWrite(RIGHT_PIN, LOW);
  digitalWrite(LEFT_PIN, LOW);
  
  digitalWrite(FORWARD_PIN, HIGH);
}

void GoBackward() {
  //Serial.println("Go Backward");
  digitalWrite(FORWARD_PIN, LOW);
  digitalWrite(RIGHT_PIN, LOW);
  digitalWrite(LEFT_PIN, LOW);
  
  digitalWrite(BACKWARD_PIN, HIGH);
  }

void TurnLeft() {
  //Serial.println("Turn Left");
  digitalWrite(FORWARD_PIN, LOW);
  digitalWrite(BACKWARD_PIN, LOW);
  digitalWrite(RIGHT_PIN, LOW);
  
  digitalWrite(LEFT_PIN, HIGH); 
}

void TurnRight() {
  //Serial.println("Turn Right");
  digitalWrite(FORWARD_PIN, LOW);
  digitalWrite(BACKWARD_PIN, LOW);
  digitalWrite(LEFT_PIN, LOW);
  
  digitalWrite(RIGHT_PIN, HIGH);
  }

void StopAll() {
  //Serial.println("Stop All");
  digitalWrite(FORWARD_PIN, LOW);
  digitalWrite(BACKWARD_PIN, LOW);
  digitalWrite(RIGHT_PIN, LOW);
  digitalWrite(LEFT_PIN, LOW);

}

void setup() {
  //Serial.begin(9600);
  btSerial.begin(9600);
  
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(7,OUTPUT);  
}

void DEMO_MODE() {
  delay(2000);
  if (command < 5) {
    ++command;
  }
  else {
    command = 0;
  }
}


void loop() {
    
  command = btSerial.read();  
  
  if (command != -1 && command != ' ') {
    
    //Serial.println("Command Received");
    
    btSerial.flush();
    
    switch (command)
    {
      case (FORWARD_COMMAND):
        GoForward();
        break;
      case (BACKWARD_COMMAND):
        GoBackward();
        break;
      case (LEFT_COMMAND):
        TurnLeft();
        break;
      case (RIGHT_COMMAND):
        TurnRight();
        break;
      case (STOP_COMMAND):
        StopAll();
        break;
      default:
        StopAll();
        break;
    }
  }
}
