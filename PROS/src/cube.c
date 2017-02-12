#include "progInc.h"

//right cube function
void rCube (){
  // right cube
  aDrive(1); // forward
  motorSet(tipBar, 127); // start tipbar
  delay(400);
  motorSet(claw, 127); // close claw
  delay(700);
  aDrive(4); //stop
  motorSet(tipBar, 0); // stop tip bar
  delay(1000);
  motorSet(claw, 40); //low power
  delay(300);
  aLift(-127); //lift the cube
  delay(500);
  aLift(-20); //hold the cube
  aDrive(3); //turn
  delay(620);
  aDrive(4); //stop
  delay(300);
  aDrive(0); //reverse
  aLift(-127);
  delay(800);
  motorSet(claw, -127); //open claw
  delay(500);
  aLift(0); // stop lift
  delay(600);
  motorSet(claw, 0);
  aDrive(4); // stop
  motorStopAll(); //pause
  motorSet(claw, 127);
  delay(500);
  aLift(127); //bring lift down
  delay(1500);
  aLift(40); //slower
  aDrive(1); //forward
  delay(400);
  aLift(0);//stop lift
  aDrive(4);//stop bot
  motorStopAll();//end routine
}


void lCube(){
  // left cube
  aDrive(1); // forward
  motorSet(tipBar, 127); // start tipbar
  delay(400);
  motorSet(claw, 127); // close claw
  delay(700);
  aDrive(4); //stop
  motorSet(tipBar, 0); // stop tip bar
  delay(1000);
  motorSet(claw, 40); //low power
  delay(300);
  aLift(-127); //lift the cube
  delay(500);
  aLift(-20); //hold the cube
  aDrive(2); //turn
  delay(620);
  aDrive(4); //stop
  delay(300);
  aDrive(0); //reverse
  aLift(-127);
  delay(800);
  motorSet(claw, -127); //open claw
  delay(500);
  aLift(0); // stop lift
  delay(600);
  motorSet(claw, 0);
  aDrive(4); // stop
  motorStopAll(); //pause
  motorSet(claw, 127);
  delay(500);
  aLift(127); //bring lift down
  delay(1500);
  aLift(40); //slower
  aDrive(1); //forward
  delay(400);
  aLift(0);//stop lift
  aDrive(4);//stop bot
  motorStopAll();//end routine
}


void rCubeLong(){
  rCube();
  motorSet(claw, -127); delay(800); motorStop(claw); //open claw
  aDrive(1); delay(1100); aDrive(4);//forward
  motorSet(claw, 127); delay(1200); motorSet(claw, 40); // grab stars

  //reverse and throw
  aDrive(0);
  delay(400);
  aLift(-127);
  delay(1150);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();
}

void lCubeLong(){
  lCube();
  motorSet(claw, -127); delay(800); motorStop(claw); //open claw
  aDrive(1); delay(1100); aDrive(4);//forward
  motorSet(claw, 127); delay(1200); motorSet(claw, 40); // grab stars

  //reverse and throw
  aDrive(0);
  delay(400);
  aLift(-127);
  delay(1150);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();
}
