#include "main.h"
#include "autoFunc.h"
void skills(){
  aDrive(0);
  motorSet(1, 127);
  motorSet(claw, 127);
  delay(600);
  aDrive(4);
  motorSet(1, 0);
  delay(500);
  aDrive(1);
  delay(800);
  motorSet(claw, 50);
  aDrive(0);
  delay(300);
  aLift(-127);
  delay(800);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();

  aLift(80);
  delay(300);
  aDrive(1);
  delay(900);
  motorSet(claw, 60);
  delay(500);
  aDrive(0);
  delay(300);
  aLift(-127);
  delay(1050);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();

  aLift(80);
  delay(300);
  aDrive(1);
  delay(900);
  motorSet(claw, 60);
  delay(500);
  aDrive(0);
  delay(300);
  aLift(-127);
  delay(950);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();

  aLift(80);
  delay(300);
  aDrive(1);
  delay(900);
  motorSet(claw, 60);
  delay(500);
  aDrive(0);
  delay(300);
  aLift(-127);
  delay(1050);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();

  aLift(80);
  delay(300);
  aDrive(2);
  delay(420);
  aDrive(1);
  delay(700);
  motorSet(claw, 60);
  delay(500);
  aDrive(3);
  delay(300);
  aDrive(4);
  delay(400);
  aDrive(0);
  delay(300);
  aLift(-127);
  delay(1150);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();

  aLift(80);
  delay(300);
  aDrive(1);
  delay(900);
  motorSet(claw, 60);
  delay(500);
  aDrive(0);
  delay(300);
  aLift(-127);
  delay(1050);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();
  
}
