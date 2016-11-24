/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost,  the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */

 //functions for autonomous

//arm lift
 void liftSet(int direction){
 	motorSet(4, direction); // set arm left 1
 	motorSet(5, direction); // set arm left 2
 	motorSet(6, direction); // set arm left 3
 	motorSet(7, direction); // set arm left 4
 }


 //claw code
 void clawSet(int direction){
 	motorSet(8, direction); // claw motor 1
 	motorSet(9, direction); // claw motor 2
 }


 void drive (int direction) {
   /*directions
   0 = forward
   1 = backward
   2 = left
   3 = right
   4 = stop
   */

   if (direction == 0 || direction == 3) {
     motorSet(2, 127);
   }else if (direction == 4){
     motorSet(2, 0);
   }else{
     motorSet(2, -127);
   }

   if (direction == 0 || direction == 2) {
     motorSet(3, 127);
   }else if (direction == 4){
     motorSet(2, 0);
   }else{
     motorSet(2, -127);
   }

 }

void autonomous() {

  //pseudo code

  /*
  motor key
  1 tip-bar
  2 & 3 drive
  4-7 arm
  8-9 claw
  */

  motorSet(1, 127); //bring out tip-bar
  drive(0); //drive forward
  clawSet(127); //claw open
  liftSet(-127); //lift arm
  delay(700); //delay 700
  clawSet(0); //stop claw
  delay(500); //delay 500
  liftSet(0);//stop arm
  delay(300); //delay 300
  drive(4); //stop
  delay(100); //delay 100
  drive(1); //reverse
  delay(150); //delay 150
  //drop arm
  drive(4); //stop
  //delay 100
  //turn left
  //delay 200
  //drive forward
  //delay 600
  //stop
  //claw grab
  //delay 400
  //raise arm
  //delay 150
  //turn left
  //delay 100
  //stop arm
  //delay
  //stop
  //delay 50
  //reverse
  //lift arm
  //delay 300
  //stop arm
  //delay 200
  //stop
  //open claw
  //delay 250
  //close claw
  //lower arm
  //delay 200
  //stop claw
  //delay 300
  //stop arm

}
