#include "API.h"
#include "main.h"


void tip(){
  //tip-bar code
  if(joystickGetDigital(1, 7, JOY_UP)) {
    motorSet(tipBar, 127); // pressing up, so tip-bar should open
  }else if(joystickGetDigital(1, 7, JOY_DOWN)) {
    motorSet(tipBar, -127); // pressing down, so tip-bar should close
  }else {
    motorSet(tipBar, 0); // no buttons are pressed, stop the tip-bar
  }
}

void lift(int direction){

	if (direction < 0 && analogRead(1) > 1850){
		motorStop(lift1);
		motorStop(lift2);
		motorStop(lift3);
		motorStop(lift4);
	}else if(direction > -15
		 && analogRead(1) < 50){
		motorStop(lift1);
		motorStop(lift2);
		motorStop(lift3);
		motorStop(lift4);
	}else if(direction < 0 && analogRead(1) > 1200){
		direction = direction + 25;
		motorSet(lift1, direction); // set arm  1
		motorSet(lift2, direction); // set arm  2
		motorSet(lift3, direction); // set arm  3
		motorSet(lift4, direction); // set arm  4
	}else{
		motorSet(lift1, direction); // set arm  1
		motorSet(lift2, direction); // set arm  2
		motorSet(lift3, direction); // set arm  3
		motorSet(lift4, direction); // set arm  4
	}
}

void autoButton(){
  //auto button
  if(joystickGetDigital(1, 8, JOY_RIGHT) && isOnline() == false) {
    autonomous(); // this calls the autonomous code
  }
}
