#include "progInc.h"

void rStar(){
  motorSet(tipBar, 127); // bring out tip bar
  motorSet(claw, 127); // close claw
  delay(1500);
  motorSet(tipBar, 0); // stop tipbar
  delay(300);
  aDrive(3); //turn left
  delay(300);
  aDrive(4); //stop bot
  delay(200);
  motorSet(claw, 50);
  aDrive(1); // drive forward
  delay(1400);
  aDrive(4); //stop
  delay(200);
  motorStopAll();
  motorSet(claw, 40); // hold stars
  aLift(-127); //lift stars up
  delay(600);
  aLift(-30); //hold the stars up
  aDrive(0);
  delay(700);
  aTank(-127,-40); //slant reverse
  delay(1300);
  aDrive(0);//reverse
  delay(600);
  aLift(-127);
  delay(500);
  motorSet(claw, -127);
  delay(700);
  aLift(0);
  motorStopAll();
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


void lStar(){
  motorSet(tipBar, 127); // bring out tip bar
  motorSet(claw, 127); // close claw
  delay(1500);
  motorSet(tipBar, 0); // stop tipbar
  delay(300);
  aDrive(2); //turn right
  delay(300);
  aDrive(4); //stop bot
  delay(200);
  motorSet(claw, 50);
  aDrive(1); // drive forward
  delay(1400);
  aDrive(4); //stop
  delay(200);
  motorStopAll();
  motorSet(claw, 40); // hold stars
  aLift(-127); //lift stars up
  delay(600);
  aLift(-30); //hold the stars up
  aTank(-55,-127); //slant reverse
  delay(1400);
  aDrive(0);//reverse
  delay(1200);
  aLift(-127);
  delay(500);
  motorSet(claw, -127);
  delay(700);
  aLift(0);
  motorStopAll();
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
