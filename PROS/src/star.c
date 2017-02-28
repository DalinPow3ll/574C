#include "autoFunc.h"
#include "main.h"

int toDo;
int loopClock;


void rStar(){

  //bring lift up and open claw
  motorSet(1, 127); //start tip
  aLift(-127); delay(900); aLift(10); //lift
  motorStop(1); //stop tip
  motorSet(claw, 127); delay(1460); motorStop(claw); //claw

  //bring lift down
  aLift(80); delay(1400); aLift(20);


  //forward and grab

  aDrive(1); delay(600); motorSet(claw, 15); delay(950); aDrive(4); delay(200); // drive forward
  motorSet(claw, 127); delay(500); motorSet(claw, 40);
  aLift(-127); delay(800); aLift(-20); // lift up


  //reverse and throw

  aDrive(0); delay(1500); aDrive(4); delay(300); aTank(-127, 25);
  delay(720);
  aDrive(0);
  delay(1150);
  aLift(-127);
  delay(550);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();


}


void lStar(){


}
