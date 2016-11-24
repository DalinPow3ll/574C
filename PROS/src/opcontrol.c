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
void startUp(int on){
	on = 0;
	if (on == 0){
		delay(2500);
			//lcdPrint("Program has Succesfully Complied, and is now running v1.5.05"):
	}
	on = 1;
}


//function for the lift arm
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


//tip-bar code
void tipSet(int direction){
	motorSet(1, direction); // main tip motor
}

void clawCode(int clawDirection){
	//claw code
	if(joystickGetDigital(1, 5, JOY_UP) && clawDirection != 1) {
		clawSet(127); // pressing up, so claw should open
		clawDirection = 1;
	}
	else if(joystickGetDigital(1, 5, JOY_DOWN) && clawDirection != 2) {
		clawSet(-127); // pressing down, so claw should close
		clawDirection = 2;
	}
	else if(clawDirection == 3){
		// low power mode
		clawSet(-50);
	}
	else if(clawDirection != 0){
		clawSet(0); // no buttons are pressed, stop the claw
	}
}

//main operator control statement
void operatorControl() {
	int power;
  int turn;


	//controls direction of claw movement
	int clawDirection = 0; // 0 = stop, 1 = open, 2 = close, 3 = low power
	int clawClock = 0; // controls the time of the claw opening and closing

    while (1) {


				//drive code
        power = joystickGetAnalog(1, 1); // vertical axis on left joystick
        turn  = joystickGetAnalog(1, 2); // horizontal axis on left joystick
        motorSet(2, power + turn); // set left wheels
        motorSet(3, power - turn); // set right


				//lift code
				if(joystickGetDigital(1, 6, JOY_UP)) {
		      liftSet(-127); // pressing up, so lift should go up
		    }
		    else if(joystickGetDigital(1, 6, JOY_DOWN)) {
		      liftSet(127); // pressing down, so lift should go down
		    }
		    else {
		      liftSet(-30); // no buttons are pressed, hold the lift in place with a little power
		    }

				//if the claw is moving, turn on the clock
				if(clawDirection != 0){
					//claw clock reset if it is finished moving
					if (clawClock > 50){
						clawClock = 0; // reset clock
						if (clawDirection == 1){
							clawDirection = 3; // low power mode if claw is going forward
						}else{
							clawDirection = 0; // 0 = stop claw
						}
					}else{
						clawClock ++; // increment claw clock
					}
				}
				clawCode(clawDirection); // moves claw based on state

				//tip-bar code
				if(joystickGetDigital(1, 7, JOY_UP)) {
		      tipSet(127); // pressing up, so tip-bar should open
		    }
		    else if(joystickGetDigital(1, 7, JOY_DOWN)) {
		      tipSet(-127); // pressing down, so tip-bar should close
		    }
		    else {
		      tipSet(0); // no buttons are pressed, stop the tip-bar
		    }


				//button on the far right to trigger autonomous when no competition switch is connected
				if(joystickGetDigital(1, 8, JOY_RIGHT) && isOnline() == false) {
		      autonomous(); // this calls the autonomous code
		    }


        delay(20);
    }

}
