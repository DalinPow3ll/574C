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
  motorStop(9);
}

void clawStart(int direction){
  motorSet(8, direction);
  motorSet(9, -direction);
}


//claw logic
int clawGetDirection(){
  int direction; //define direciton variable

  //start joystick if button is pressed
  if(joystickGetDigital(1, 6, JOY_UP)){
    direction = 1 // 1 = closed
  }else if(joystickGetDigital(1, 6, JOY_DOWN)){
    direction = 2 // 2 = open
  }


  //stop claw if potentiometer at limit
  if (analogRead(1) < cOpen) {
    direction = 0; //stop claw if too open
    isMid = false;
  }else if (analogRead(1) > cclose) {
    direction = 0; //stop claw if too closed
    isMid = false;
  }else if (analogRead(1) == cMid && isMid == false) {
    direction = 0;
    isMid = true;
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
