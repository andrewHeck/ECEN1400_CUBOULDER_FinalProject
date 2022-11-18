#include <Stepper.h>

// defines number of steps in motor
#define STEPS 200

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's attached to
Stepper stepperA(STEPS, 10, 11, 12, 13);
Stepper stepperB(STEPS, 6, 7, 8, 9);

//solunoid pins and boolian
const int solenoidPin = 9;
const int buttonPin = 13;
bool sully = true;

//wires for the joystick
const int up = 22;
const int down = 23;
const int left =  24;
const int right = 25;

//wires for limit switches:
const int limitUp = 14;
const int limitDown = 15;
const int limitLeft = 16;
const int limitRight = 17;

//steps for each direction

const int steps = 1;
const int leftStep = -steps;
const int rightStep = steps;
const int upStep = steps;
const int downStep = -steps;

void setup() {
  Serial.begin(9600);
  
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(left, INPUT);
  pinMode(right, INPUT);

  pinMode(limitUp, INPUT);
  pinMode(limitDown, INPUT);
  pinMode(limitLeft, INPUT);
  pinMode(limitRight, INPUT);

  stepperA.setSpeed(60);
  stepperB.setSpeed(60);
}

void loop() {
  
  // direction control pretty self explanitory by what's printed
  if(digitalRead(up) == 0 && digitalRead(right) == 0 && digitalRead(limitUp) == 0 && digitalRead(limitRight) == 0){
    Serial.println("upRIGHT");
    stepperA.step(upStep);
    stepperB.step(rightStep);
    
  }else if(digitalRead(up) == 0 && digitalRead(left) == 0 && digitalRead(limitUp) == 0 && digitalRead(limitLeft) == 0){
    Serial.println("upLEFT"); 
    stepperA.step(upStep);
    stepperB.step(leftStep);
    
  }else if(digitalRead(down) == 0 && digitalRead(left) == 0 && digitalRead(limitLeft) == 0 && digitalRead(limitDown) == 0){
    Serial.println("downLEFT");
    stepperA.step(downStep);
    stepperB.step(leftStep);
    
  }else if(digitalRead(down) == 0 && digitalRead(right) == 0 && digitalRead(limitDown) == 0 && digitalRead(limitRight) == 0){
    Serial.println("downRight");
    stepperA.step(downStep);
    stepperB.step(rightStep);
    
  }else if(digitalRead(up)== 0 && digitalRead(limitUp) == 0){
    Serial.println("up");
    stepperA.step(upStep);
    //delay(200);
    
  }else if(digitalRead(down) == 0 && digitalRead(limitDown) == 0){
    Serial.println("down");
    stepperA.step(downStep);
    
  }else if(digitalRead(right)== 0 && digitalRead(limitRight) == 0){
    Serial.println("right");
    stepperB.step(rightStep);
    
  }else if(digitalRead(left) == 0 && digitalRead(limitLeft) == 0){
    Serial.println("left");
    stepperB.step(leftStep);
    
  }

  //solunoid controle
  if(digitalRead(buttonPin) == HIGH){
    sully = !sully;
    delay(200);
    Serial.println(sully);
  }

  if(sully == true){
    digitalWrite(solenoidPin, HIGH);
  }if(sully == false){
    digitalWrite(solenoidPin, LOW);
  }
  
}
