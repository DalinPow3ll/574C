#include "claw.h"
#include "main.h"

//claw position variables
int cOpen = 1000;
int cMid = 1500;
int cClose = 2000;
bool isMid = false;

//claw Actions
void clawStop(){
  motorStop(8);
}

void clawStart(int direction){
  motorSet(8, direction);
}


//claw logic
int clawGetDirection(){
  int direction; //define direciton variable
  int pot = analogRead(1);

  //start joystick if button is pressed
  if(joystickGetDigital(1, 6, JOY_UP)){
    direction = 1; // 1 = closed
  }else if(joystickGetDigital(1, 6, JOY_DOWN)){
    direction = 2; // 2 = open
  }


  //stop claw if potentiometer at limit
  if (pot < cOpen) {
    direction = 0; //stop claw if too open
  }else if (pot > cClose) {
    direction = 0; //stop claw if too closed
  }else if (pot == cMid && isMid == false) {
    direction = 0;
    isMid = true;
  }

  //check if claw is not in middle
  if (pot < cMid || pot > cMid) {
    isMid = false;
  }

  return direction; //return direction of claw rotation
}


void clawMove(int direction){
  //check direction and potentiometer
  if(direction == 1){
    clawStart(127);
  }else if(direction == 2) {
    clawStart(-127);
  }else{
    clawStop();
  }
}
