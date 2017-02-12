#include "autoFunc.h"
#include "main.h"

int toDo;
int loopClock;


void rStar(){

  //bring lift up and open claw
  motorSet(1, 127); //start tip
  aLift(-127); delay(900); aLift(10); //lift
  motorStop(1); //stop tip
  motorSet(claw, 127); delay(1400); motorStop(claw); //claw

  //bring lift down
  aLift(80); delay(1300); aLift(20);


  //forward and grab

  aDrive(1); delay(600); motorSet(claw, 15); delay(1150); aDrive(4); delay(200); // drive forward
  motorSet(claw, 127); delay(500); motorSet(claw, 40);
  aLift(-127); delay(600); aLift(0); // lift up


  //reverse and throw

  aDrive(0); delay(700); aTank(-127, 20);
  delay(800);
  aDrive(0);
  delay(1000);
  aLift(-127);
  delay(1450);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();


}


void lStar(){


}
