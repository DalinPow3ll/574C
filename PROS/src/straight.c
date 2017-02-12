#include "progInc.h"

void straight(){
  //first preload
  aDrive(0);
  motorSet(1, 127);
  motorSet(claw, 127);
  delay(600);
  aDrive(4);
  motorSet(1, 0);
  delay(700);
  motorStop(claw);
  aTank(127, -60);
  delay(300);
  aDrive(1);
  delay(800);
  aDrive(4);
  motorSet(claw, 60);
  delay(1000);
  aTank(-127, -75);
  delay(400);
  aLift(-127);
  aDrive(0);
  delay(1050);
  motorSet(claw, -127);
  delay(600);
  motorStopAll();

}
