

#include "main.h"
#include "autoFunc.h"

void autonomous() {

  /*
  motor key
  1 tip-bar
  2, 3, 9, 10 drive
  4-7 arm
  8 claw
  */

  /*drive key
  0 = forward
  1 = backward
  2 = left
  3 = right
  4 = stop
  */

  // basic auto program
  motorSet(tipBar, 127); //bring out tip-bar
  aDrive(0); //drive forward
  motorSet(claw, 127); //claw open
  aLift(-127); //lift arm
  delay(900);
  aLift(0); //stop lift
  delay(400);
  motorSet(claw, 0); //stop claw
  motorSet(tipBar, 0); // stop the tip bar
  delay(1100);
  aDrive(4); //stop
  delay(500);
  aDrive(1); //drive backward
  delay(1200);
  aDrive(4); //stop
}
