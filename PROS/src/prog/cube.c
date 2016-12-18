#include "progInc.h"

//right cube function
void rCube (){
  // right cube
  aDrive(1); // forward
  motorSet(claw, 127); // close claw
  delay(1350);
  aDrive(4); //stop
  delay(1600);
  motorSet(claw, 40); //low power
  delay(300);
  aLift(-127); //lift the cube
  delay(500);
  aLift(-20); //hold the cube
  aDrive(3); //turn
  delay(520);
  aDrive(4); //stop
  delay(300);
  aDrive(0); //reverse
  delay(300);
  aLift(-127);
  delay(500);
  motorSet(claw, -127);
  delay(300);
  aLift(0); // stop lift
  delay(600);
  motorSet(claw, 0);
  aDrive(4); // stop
  motorStopAll(); //end routine
}


void lCube(){
  // left cube
  aDrive(1); // forward
  motorSet(claw, 127); // close claw
  delay(1350);
  aDrive(4); //stop
  delay(1600);
  motorSet(claw, 40); //low power
  delay(300);
  aLift(-127); //lift the cube
  delay(500);
  aLift(-20); //hold the cube
  aDrive(2); //turn
  delay(600); // left is slower for some reason
  aDrive(4); //stop
  delay(300);
  aDrive(0); //reverse
  delay(300);
  aLift(-127);
  delay(500);
  motorSet(claw, -127);
  delay(300);
  aLift(0); // stop lift
  delay(600);
  motorSet(claw, 0);
  aDrive(4); // stop
  motorStopAll(); //end routine
}
