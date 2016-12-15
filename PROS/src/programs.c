#include "autoFunc.h"
#include "API.h"
#include "main.h"

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
  delay(520); //the most dank delay
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
  delay(420); //the most dank delay
  aDrive(4); //stop
  delay(300);
  aDrive(0); //reverse
  delay(300);
  aLift(-127);
  motorSet(claw, -127);
  delay(300);
  aLift(0); // stop lift
  delay(600);
  motorStopAll(); //stop everything
  aDrive(4); // stop
  motorStopAll(); //end routine
}


void straight(){
  motorSet(tipBar, 127); //bring out tip
  aDrive(1); // drive forward
  motorSet(claw, 127); // open claw
  delay(1500);
  motorSet(tipBar, 0); //stop the tip bars
  motorSet(claw, 0); // stop claw at half way
  aLift(-127); //start lifting arm
  aDrive(4); // stop driving
  delay(300);
  aLift(0); // stop lift
  delay(200);
  aDrive(0); // drive backward
  delay(500);
  motorStopAll(); //end routine
}
