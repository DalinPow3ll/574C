#include "main.h"
#include "mutual.h"
#include "micah.h"
#include "nick.h"

//main operator control statement
void operatorControl() {

	int controller = 0; // 0 = nick's controls, 1 = micah's

	//main loop
		while (1) {


			//n fuctions are in nick.c
			//m functions are in micah.c
			//check who's controls to use
			if (controller == 1){
				// micah specific controls
				mDrive(); // micah drive
				lift(joystickGetAnalog(1, 3) - 8); // micah lift
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
			controlSwitch(controller);// control switcher
			autoButton(); // autonomous activator button


      delay(20);
    }

}
