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

  float slew = 0.04; //slew constant
  int power = motorGet(lift1);
  power = power + (direction - power) * slew;
	motorSet(lift1, power); // set arm  1
	motorSet(lift2, power); // set arm  2
	motorSet(lift3, power); // set arm  3
	motorSet(lift4, power); // set arm  4
}

void autoButton(){
  //auto button
  if(joystickGetDigital(1, 8, JOY_RIGHT) && isOnline() == false) {
    autonomous(); // this calls the autonomous code
  }
}
