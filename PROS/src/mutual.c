#include "API.h"
#include "main.h"

void tip(){
  //tip-bar code
  if(joystickGetDigital(1, 7, JOY_UP)) {
    motorSet(1, 127); // pressing up, so tip-bar should open
  }else if(joystickGetDigital(1, 7, JOY_DOWN)) {
    motorSet(1, -127); // pressing down, so tip-bar should close
  }else {
    motorSet(1, 0); // no buttons are pressed, stop the tip-bar
  }
}

void Lift(int direction){
	if (direction < 0 && analogRead(1) > 1850){
		motorStop(4);
		motorStop(5);
		motorStop(6);
		motorStop(7);
	}else if(direction > -15
		 && analogRead(1) < 50){
		motorStop(4);
		motorStop(5);
		motorStop(6);
		motorStop(7);
	}else if(direction < 0 && analogRead(1) > 1200){
		direction = direction + 20;
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

void autoButton(){
  //auto button
  if(joystickGetDigital(1, 8, JOY_RIGHT) && isOnline() == false) {
    autonomous(); // this calls the autonomous code
  }
}

//function to switch between control modes
void controlSwitch(int controller){
  //control switch
  if(joystickGetDigital(1, 8, JOY_UP)){
    if(controller == 0){
      controller = 1;
      delay(500);
    }else{
      controller = 0;
      delay(500);
    }
  }
}
