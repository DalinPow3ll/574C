#include "progInc.h"
#include "main.h"

int liftLoop(int loopClock, int time, int speed, int endPower){
  int complete = 0;
  //tip bar stop
  if (loopClock < time) {
    aLift(speed);
  }else{
    aLift(endPower);
    complete = 1;
  }

  return complete;
}

int clawForward(int position, int squeeze){
  int complete = 0;

  //claw logic
  if(analogRead(clawPot) > position){ //if claw not at closed position
    motorSet(claw, 127); //move it forward
  }else{
    motorSet(claw, squeeze); //stop claw
    complete = 1; // task complete
  }

  return complete;
}


int clawBack(int position){
  int complete = 0;

  //claw logic
  if(analogRead(clawPot) < position){ //if claw not at closed position
    motorSet(claw, -127); //move it forward
  }else{
    motorSet(claw, 0); //stop claw
    complete = 1; // task complete
  }

  return complete;
}

int tipOut(int loopClock){
  int complete = 0;
  //tip bar stop
  if (loopClock > 1500) { //if loop has been runnning for 1.3 seconds
    motorSet(tipBar, 0); // stop the tip bar
    complete = 1;
  }else{
    motorSet(tipBar, 127); // start the tip bar
  }

  return complete;
}

int tankDriveEnc (int left, int right, int distance){
  int complete = 0;
  int margin = 10;
  if (encoderGet(driveEnc) < distance - margin){
    aTank(left, right);
  }else if(encoderGet(driveEnc) > distance + margin){
    aTank(-left, -right);
  }else{
    aDrive(4); // stop
    complete = 1;
  }
  return complete;
}
