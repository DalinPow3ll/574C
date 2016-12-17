#include "main.h"
#include "mutual.h"
#include "micah.h"
#include "nick.h"

//main operator control statement
void operatorControl() {

	int cSet; // variable to set control mappings

	if(digitalRead(controlPin) == HIGH){
		cSet = 0; // 0 = nick's controls
	}else{
		cSet = 1; // 1 = micah's controls
	}

	//main loop
		while (1) {


			//n fuctions are in nick.c
			//m functions are in micah.c
			//check who's controls to use
			if (cSet == 1){
				// micah specific controls
				mDrive(); // micah drive
				lift(joystickGetAnalog(1, 3)); // micah lift
				mClaw(); // micah claw
			}else{
				//nick specific controls
				nDrive(); //nick Drive
				nLift(); // nick lift
				nClaw(); // nick claw
			}


			//mutual controls
			//these funtctions are located in "mutual.c"
			tip(); // tip bar control
			autoButton(); // autonomous activator button

			//control switcher
			if(joystickGetDigital(1, 8, JOY_UP)){
		    cSet = 1 - cSet; // switch control
		    delay(500);
		  }

      delay(20);
    }

}
