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

void rStar(){
  motorSet(tipBar, 127); // bring out tip bar
  motorSet(claw, 127); // open claw
  delay(1500);
  motorSet(tipBar, 0); // stop tipbar
  delay(500);
  aDrive(3); //turn left
  delay(300);
  motorSet(claw, 0);
  aDrive(4); //stop bot
  delay(200);
  aDrive(1); // drive forward
  delay(800);
  motorSet(claw, 127); //close claw
  delay(800);
  motorStopAll();
  aLift(-127); //lift stars up
  delay(500);
  aLift(20); //hold the stars up
  aDrive(0); // reverse
  delay(1800);
  aDrive(4); // pause
  delay(300);
  aDrive(3); // turn left
  delay(420); // dank
  aDrive(4);
  delay(300);
  aDrive(0);
  delay(1000);
  aLift(-127);
  motorSet(claw, -127);
  delay(500);
  aLift(0);
  motorStopAll();
}


void straight(){
  motorSet(tipBar, 127); //bring out tip
  aDrive(1); // drive forward
  motorSet(claw, 127); // open claw
  aLift(-127); //start lifting arm
  delay(800);
  aLift(0);
  delay(800);
  motorSet(tipBar, 0); //stop the tip bars
  motorSet(claw, 0); // stop claw at half way
  aDrive(4); // stop driving
  delay(500);
  aDrive(0); // drive backward
  delay(500);
  motorSet(claw, 127);
  delay(500);
  motorStopAll(); //end routine
}
