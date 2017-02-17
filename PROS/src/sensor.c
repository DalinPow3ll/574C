#include "progInc.h"
#include "autoFunc.h"

#include "star.h"

void launch(){
  aDrive(0);
  delay(400);
  aLift(-127);
  delay(1250);
  motorSet(claw, -127);
  delay(350);
  motorStopAll();
}

void reset(){
  aLift(80);
  delay(2200);
  aLift(20); //hold lift down
}

void grab(int left, int right, int pause){
  aTank(left, right); //forward
  delay(pause);
  motorSet(claw, 127);
  delay(400);
  aDrive(4);
  motorSet(claw, 40);
}

void rSensor(){
  //back three
  rStar();
  delay(500);

  //first preload
  reset();
  grab(127, 127, 1400); // drive left and right motors at full power for 1100 miliseconds
  launch();
}
