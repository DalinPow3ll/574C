

#include "main.h"
#include "autoFunc.h"

void autonomous() {

  /*drive key
  0 = backward
  1 = forward
  2 = left
  3 = right
  4 = stop
  */

  // basic auto program for right side
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
}
