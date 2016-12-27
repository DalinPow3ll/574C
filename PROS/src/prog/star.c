#include "progInc.h"

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
  motorSet(claw, 40); // hold stars
  aLift(-127); //lift stars up
  delay(550);
  aLift(-30); //hold the stars up
  aDrive(0); // reverse
  delay(1800);
  aDrive(4); // pause
  delay(300);
  aDrive(3); // turn left
  delay(330);
  aDrive(4);
  delay(300);
  aDrive(0); // reverse
  delay(1200);
  aLift(-127);
  delay(200);
  motorSet(claw, -127);
  delay(500);
  aLift(0);
  motorStopAll();
}


void lStar(){
  motorSet(tipBar, 127); // bring out tip bar
  motorSet(claw, 127); // open claw
  delay(1500);
  motorSet(tipBar, 0); // stop tipbar
  delay(500);
  aDrive(2); //turn right
  delay(300);
  motorSet(claw, 0);
  aDrive(4); //stop bot
  delay(200);
  aDrive(1); // drive forward
  delay(800);
  motorSet(claw, 127); //close claw
  delay(600);
  motorStopAll();
  motorSet(claw, 40); // hold stars
  aLift(-127); //lift stars up
  delay(550);
  aLift(-30); //hold the stars up
  aDrive(0); // reverse
  delay(1800);
  aDrive(4); // pause
  delay(300);
  aDrive(2); // turn right
  delay(330);
  aDrive(4);
  delay(300);
  aDrive(0); // reverse
  delay(1200);
  aLift(-127);
  delay(200);
  motorSet(claw, -127);
  delay(500);
  aLift(0);
  motorStopAll();
}
