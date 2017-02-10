#include "main.h"
#include "autoFunc.h"
void skills(){
  //first preload
  aDrive(0);
  motorSet(1, 127);
  motorSet(claw, 127);
  delay(600);
  aDrive(4);
  motorSet(1, 0);
  delay(500);
  aDrive(1);
  delay(900);
  motorSet(claw, 60);
  delay(400);
  aDrive(4);
  delay(500);
  aTank(-100,-127);
  delay(400);
  aLift(-127);
  delay(1450);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();

  //second preload
  aLift(80);
  delay(2200);
  aLift(0);
  aTank(127,100);
  delay(1100);
  motorSet(claw, 60);
  delay(400);
  aDrive(4);
  delay(500);
  aDrive(0);
  delay(400);
  aLift(-127);
  delay(1250);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();


  //corner star
  aLift(80);
  delay(2200);
  aLift(30);
  aTank(55,127);
  delay(900);
  motorSet(claw, 40);
  delay(700);
  aTank(-55,-127);
  delay(400);
  aLift(-127);
  delay(1150);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();


  //cube
  aLift(80);
  delay(2200);
  aLift(40);
  aDrive(2);
  delay(400);
  aDrive(1);
  delay(900);
  motorSet(claw, 60);
  delay(600);
  aLift(-127);
  delay(400);
  aLift(0);
  aTank(80,127);
  delay(420);
  aDrive(4);
  delay(400);
  aDrive(0);
  delay(900);
  aLift(-127);
  delay(950);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();


  //back star
  aLift(80);
  delay(2200);
  aLift(0);
  aTank(127,100);
  delay(1100);
  aDrive(4);
  motorSet(claw, 60);
  delay(800);
  aDrive(0);
  delay(400);
  aLift(-127);
  delay(1450);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();
}
