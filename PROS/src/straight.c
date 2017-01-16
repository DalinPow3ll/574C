#include "progInc.h"

void straight(){
  motorSet(tipBar, 127); //bring out tip
  aDrive(1); // drive forward
  motorSet(claw, 127); // open claw
  aLift(-127); //start lifting arm
  delay(900);
  aLift(0);
  delay(850);
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
