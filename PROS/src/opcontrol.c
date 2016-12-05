/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "claw.h"

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */


//function for the lift arm
void lift(int direction){
	if (direction < 0 && analogRead(1) > 1850){
		motorStop(4);
		motorStop(5);
		motorStop(6);
		motorStop(7);
	}else if(direction > 0 && analogRead(1) < 50){
		motorStop(4);
		motorStop(5);
		motorStop(6);
		motorStop(7);
	}else if(direction < 0 && analogRead(1) > 1200){
		direction = direction + 20;
		direction = direction - analogRead(1)/600;
		motorSet(4, direction); // set arm left 1
		motorSet(5, direction); // set arm left 2
		motorSet(6, direction); // set arm left 3
		motorSet(7, direction); // set arm left 4
	}else{
		motorSet(4, direction); // set arm left 1
		motorSet(5, direction); // set arm left 2
		motorSet(6, direction); // set arm left 3
		motorSet(7, direction); // set arm left 4
	}
}

//tip-bar code
void tipSet(int direction){
	motorSet(1, direction); // main tip motor
}

//main operator control statement
void operatorControl() {
	int power;
  int turn;

	//int clawDirection; // current movement of the claw
	// 0 = stop, 1 = close, 2 = open

    while (1) {
				//drive code
        power = joystickGetAnalog(1, 1); // vertical axis on left joystick
        turn  = joystickGetAnalog(1, 2); // horizontal axis on left joystick
        motorSet(2, power + turn); // set left wheels
				motorSet(9, power - turn); // set left wheels
        motorSet(3, power - turn); // set right
				motorSet(10, power + turn); // set right


				//lift code
				lift(joystickGetAnalog(1, 3) - 8);


				//tip-bar code
				if(joystickGetDigital(1, 7, JOY_UP)) {
		      tipSet(127); // pressing up, so tip-bar should open
		    }else if(joystickGetDigital(1, 7, JOY_DOWN)) {
		      tipSet(-127); // pressing down, so tip-bar should close
		    }else {
		      tipSet(0); // no buttons are pressed, stop the tip-bar
		    }

				/*not using potentiometer right now
				//claw
				clawDirection = clawGetDirection(); // get the input of the controller and set direction
			  clawMove(clawDirection); // move claw based on direction
				*/
				//alternate claw code
				if(joystickGetDigital(1, 6, JOY_UP)) {
		      clawStart(127);
		    }else if(joystickGetDigital(1, 6, JOY_DOWN)) {
		      clawStart(-127);
		    }else{
		      clawStart(0);
		    }


				//button on the far right to trigger autonomous when no competition switch is connected
				if(joystickGetDigital(1, 8, JOY_RIGHT) && isOnline() == false) {
		      autonomous(); // this calls the autonomous code
		    }

				//print out psition of potentiometer to the terminal
				int readOut = analogRead(1);
				printf("%d\n", readOut);


        delay(20);
    }

}
