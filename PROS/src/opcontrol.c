#include "main.h"
#include "mutual.h"
#include "micah.h"
#include "nick.h"
#include "straight.h"

//main operator control statement
void operatorControl() {

	//main loop
		while (1) {


			// micah specific controls
			mDrive(); // micah drive
			lift(joystickGetAnalog(1, 3)); // micah lift
			mClaw(); // micah claw


			//mutual controls
			//these funtctions are located in "mutual.c"
			tip(); // tip bar control
			autoButton(); // autonomous activator button

			//printf("ticks: %d\n", encoderGet(driveEnc));
			printf("Readout, %d\n", analogRead(armPot));

      delay(20);
    }

}
