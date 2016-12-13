

#include "main.h"
#include "autoFunc.h"

void autonomous() {

  /*drive key
  0 = forward
  1 = backward
  2 = left
  3 = right
  4 = stop
  */

  // basic auto program
  aDrive(1); // forward
  motorSet(claw, 127); // close claw
  delay(1500);
  aDrive(4); //stop
  delay(1300);
  motorSet(claw, 40); //low power
  delay(300);
  aLift(-127); //lift the cube
  delay(500);
  aLift(-20); //hold the cube
  aDrive(3); //turn
  delay(1300);
  aDrive(4); //stop
  delay(300);
  aDrive(0); //reverse
  delay(400);
  aLift(-127);
  delay(300);
  motorSet(claw, -127);
  delay(300);
  motorStopAll(); //stop everything
  aDrive(4); // stop
}
