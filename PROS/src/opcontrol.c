#include "main.h"
#include "mutual.h"
#include "micah.h"
#include "nick.h"

//main operator control statement
void operatorControl() {

	int cSet = 0; // 0 = nick's controls, 1 = micah's

	//main loop
		while (1) {


			//n fuctions are in nick.c
			//m functions are in micah.c
			//check who's controls to use
			if (cSet == 1){
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
			autoButton(); // autonomous activator button

			//control switcher
			if(joystickGetDigital(1, 8, JOY_UP)){
		    cSet = 1 - cSet; // switch control
		    delay(500);
		  }

			//kill switch
			if(joystickGetDigital(1, 7, JOY_LEFT)){ //if left button pressed
				motorStopAll(); //stop ALL motors
				delay(10000); // wait ten seconds, gives time to turn off the bot
			}

			//potentiometer read out
			int pot = analogRead(2);
			printf("%d\n",pot);

      delay(20);
    }

}
