#include "progInc.h"

//right cube function
void rCube (){
  // right cube
  motorSet(tipBar, 127); // start tipbar
  aDrive(1); // forward
  motorSet(claw, 127); // close claw
  delay(1100);
  aDrive(4); //stop
  motorSet(tipBar, 0); // stop tip bar
  delay(700);
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
  aLift(-127);
  delay(800);
  motorSet(claw, -127);
  delay(500);
  aLift(0); // stop lift
  delay(600);
  motorSet(claw, 0);
  aDrive(4); // stop
  motorStopAll(); //pause
  delay(500);
  aLift(80); //bring lift down
  delay(900);
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
  aDrive(1); // forward
  motorSet(claw, 127); // close claw
  delay(1100);
  aDrive(4); //stop
  motorSet(tipBar, 0); // stop tip bar
  delay(700);
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
  /*
  delay(500);
  aLift(80); //bring lift down
  delay(900);
  aLift(40); //slower
  aDrive(1); //forward
  delay(400);
  aLift(0);//stop lift
  aDrive(4);//stop bot
  motorStopAll();//end routine
  */
}
