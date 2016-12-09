#include "API.h"

void mDrive(){
  //drive code
  int power;
  int turn;
  power = -joystickGetAnalog(1, 1); // vertical axis on left joystick
  turn  = joystickGetAnalog(1, 2); // horizontal axis on left joystick
  if(power > 15 || power < -15 || turn > 15 || turn < -15){
    motorSet(2, power - turn); // set left wheels
    motorSet(9, power + turn); // set left wheels
    motorSet(3, power + turn); // set right
    motorSet(10, power - turn); // set right
  }else{
    motorStop(2);
    motorStop(3);
    motorStop(9);
    motorStop(10);
  }
}

void mClaw(){
  // claw code
  if(joystickGetDigital(1, 6, JOY_UP)) {
    if(analogRead(2) > 100){
      motorSet(8, 40); // set motor low power
    }else{
      motorSet(8, 127); //set motor full power
    }
  }else if(joystickGetDigital(1, 6, JOY_DOWN)) {
    motorSet(8, -127); // set motor
  }else{
    motorSet(8, 0);
  }
}
