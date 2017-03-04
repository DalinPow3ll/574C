#include "API.h"
#include "main.h"

//drive variables
int turn = 0;
int power = 0;



void mDrive(){

  int joyT;
  int joyP;

  float slew = 0.5; //slew constant
  float turnSlew = 1;


  joyT = -joystickGetAnalog(1, 1); // horizontal axis on left joystick
  joyP = -joystickGetAnalog(1, 2); // vertical axis on left joystick

  //deadzone
  if(abs(joyT) < 15){joyT = 0;}
  if(abs(joyP) < 15){joyP = 0;}

  turn = turn + (joyT - turn) * turnSlew;
  power = power + (joyP - power) * slew;

  //right wheels
  motorSet(drive3, turn + power);
  motorSet(drive4, turn + power);

  //left wheels
  motorSet(drive1, turn - power);
    motorSet(drive2, turn - power);
}

void mClaw(){
  // claw code
  if(joystickGetDigital(1, 6, JOY_UP) && analogRead(clawPot) < cClose){
    motorSet(claw, 127); //set motor full turn
  }else if(joystickGetDigital(1, 6, JOY_DOWN)) {
    motorSet(claw, -127); // set motor
  }else{
    motorSet(claw, 0);
  }
}
