#include "progInc.h"
#include "autoFunc.h"
#include "sensFunc.h"

#include "star.h"

void launch(int pause){
  aDrive(0);
  delay(200);
  aLift(-127);
  delay(pause);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();
}

void reset(){
  aLift(80);
  delay(1300);
  aLift(10); //hold lift down
  clawBack();
}

void grab(int left, int right, int pause){
  aTank(left, right); //forward
  delay(pause);
  motorSet(claw, 127);
  delay(600);
  aTank(-left, -right);
  delay(400);
  motorSet(claw, 40);
}

void rSensor(){

  //back three
  rStar();
  delay(500);


  //first preload
  reset();
  grab(127, 127, 1000); // drive left and right motors at full power
  launch(1250);

  //second preload
  delay(400);
  reset();
  grab(127, 110, 1000); //slant
  launch(1200);

  //corner
  delay(400);
  reset();
  aTank(-60, 60);
  delay(170);
  grab(127, 110, 1000); //slant
  aTank(-50,-127);
  delay(300);
  launch(1200);

  //old cube code
  aLift(80);
  delay(2400);
  aLift(30);
  aDrive(2);
  delay(400);
  aDrive(1);
  delay(1400);
  motorSet(claw, 127);
  delay(400);
  aDrive(4);
  aLift(-127);
  motorSet(claw, 60);
  delay(500);
  aLift(0);
  aDrive(3);
  delay(500);
  aDrive(0);
  delay(900);
  aLift(-127);
  delay(950);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();

  /*
  //reset
  reset();
  //forward
  delay(200);
  aDrive(1);
  delay(700);
  aDrive(4);
  //spin
  delay(200);
  tankDriveEnc(40, 420);
  motorSet(claw, -127);
  delay(500);
  motorStop(claw);
  aLift(20);
  //grab
  aDrive(1); //forward
  delay(1200);
  aDrive(4);
  motorSet(claw, 127);
  delay(1400);
  motorSet(claw, 45); //squeeze

  aDrive(0);//reverse
  delay(400);

  //regrab
  motorSet(claw, -127);
  delay(200);
  aDrive(4);
  delay(200);
  aDrive(1);
  delay(200);
  motorSet(claw, 127);
  delay(200);
  aDrive(4);
  delay(400);
  aDrive(0);

  aLift(-127); //lift
  delay(500);
  aLift(-20); //hold
  aDrive(4);
  delay(250);

  //spin 2
  tankDriveEnc(60, 550);
  launch(600);
  */

  //rear cube
  reset();
  tankDriveEnc(60, -180);
  delay(200);
  grab(127, 127, 1500);
  delay(200);
  aLift(-127);
  delay(400);
  aLift(-20);
  aTank(-127,127);
  delay(200);
  launch(1000);

  //final star
  reset();
  delay(400);
  reset();
  grab(127, 65, 1200); //slant
  launch(1400);


}
