#include "API.h"

//variable for mClaw PID
int position = analogRead(2);

void mDrive(){
  //drive code
  int power;
  int turn;
  power = joystickGetAnalog(1, 1); // vertical axis on left joystick
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
  int clawPot = analogRead(2); // set potentiometer value

  // claw code
  if(joystickGetDigital(1, 6, JOY_UP)) {
    motorSet(8, 127); //set motor
    position = clawPot; // set current position of claw
  }else if(joystickGetDigital(1, 6, JOY_DOWN)) {
    motorSet(8, -127); // set motor
    position = clawPot; // set current position of claw
  }else{
    // if statement for error correction
    if(clawPot > position){
      int dif = clawPot - position; // find the difference
      motorSet(8, 127-(dif/2)); // set the motor to the make up the difference
    }else{
      motorSet(8, 0);
    }
  }
}
