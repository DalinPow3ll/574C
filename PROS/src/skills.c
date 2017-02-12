#include "main.h"
#include "autoFunc.h"
void skills(){
  //first preload
  aDrive(0); // reverse
  motorSet(1, 127); //tip out
  motorSet(claw, 127); //claw out

  //stop
  delay(600);
  aDrive(4); //stop drive
  motorSet(1, 0); //stop tip
  delay(500); //waiting for claw

  aDrive(1); //forawrd
  delay(600);
  aDrive(4); //stop

  motorSet(claw, 60); //low power
  delay(300);

  //reverse and throw
  aDrive(0); //reverse
  delay(400);
  aLift(-127); //bring up lift
  delay(1250);
  motorSet(claw, -127); //open claw
  delay(400);
  motorStopAll();

  //second preload
  //bring down lift
  aLift(80);
  delay(2200);
  aLift(20); //hold lift down

  aDrive(1); //forward
  delay(1100);
  motorSet(claw, 60);
  delay(400);
  aDrive(4);
  delay(500);
  aDrive(0);
  delay(400);
  aLift(-127);
  delay(1250);
  motorSet(claw, -127);
  delay(350);
  motorStopAll();




  //preload 3
  aLift(80);
  delay(2200);
  aLift(30);
  aDrive(1);
  delay(1200);
  motorSet(claw, 40);
  delay(500);
  aDrive(4);
  delay(400);
  aDrive(0);
  delay(400);
  aLift(-127);
  delay(1150);
  motorSet(claw, -127);
  delay(400);
  motorStopAll();


  //cube
  aLift(80);
  delay(2400);
  aLift(30);
  aDrive(2);
  delay(350);
  aDrive(1);
  delay(1500);
  motorSet(claw, 127);
  delay(1000);
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


  //Far cube
  aLift(80);
  delay(2200);
  aLift(20);
  motorSet(claw, -127);
  delay(400);
  motorStop(claw);
  aTank(127,65);
  delay(1800);
  aDrive(4);
  motorSet(claw, 60);
  delay(800);
  aDrive(0);
  delay(400);
  aLift(-127);
  delay(1450);
  motorSet(claw, -127);
  delay(700);
  motorStopAll();



}
