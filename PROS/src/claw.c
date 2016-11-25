#include "claw.h"

//variables in this scope
int clawDirection = 0; // 0 = stop, 1 = open, 2 = close, 3 = low power
int clawPosition = 0; // cposition of claw set by encoder

//claw code
void clawSet(int direction){
	motorSet(8, direction); // claw motor 1
	motorSet(9, direction); // claw motor 2
}

void clawMove(int clawDirection){
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

void clawControl(){
  int clawPosition = encoderGet(clawEnc); // retrieve encoder position
  //figure out what to do based on where claw is
  if(clawPosition < 10 && clawDirection == 1){
    clawDirection = 0;
  }else if(clawPosition == 90 && clawDirection != 0){
    clawDirection = 0;
  }else if(clawPosition > 150 && clawDirection == 2){
    clawDirection = 0;
  }
  clawMove(clawDirection); // moves claw based on clawDirection
}
