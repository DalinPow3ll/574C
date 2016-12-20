#include "API.h"
#include "mutual.h"

//drive variables
int right = 0;
int left = 0;

void nDrive(){

  float slew = 0.1; // slew constant

  //driving
  int joyR = joystickGetAnalog(1, 2);
  int joyL = -joystickGetAnalog(1, 3);


  if(abs(joyR) < 15){joyR = 0;}
  if(abs(joyL) < 15){joyL = 0;}

  //slowly accelerate motors to where joystick is
  //accelerate at rate of slew

  left = left + (joyL - left) * slew;
  right = right + (joyR - right) * slew;

  //set motors
  motorSet(drive1, left);
  motorSet(drive4, left);
  motorSet(drive2, right);
  motorSet(drive3, right);
}

//nick's Lift mech
void nLift(){
  //lift
  if(joystickGetDigital(1, 6, JOY_UP)){
    lift(-127);
  }else if(joystickGetDigital(1, 6, JOY_DOWN)){
    lift(127);
  }else{
    lift(0);
  }
}

void nClaw(){
  //claw
  if(joystickGetDigital(1, 5, JOY_UP)) {
    motorSet(claw, 127); //set motor full power
  }else if(joystickGetDigital(1, 5, JOY_DOWN)) {
    motorSet(claw ,-127);
  }else{
    motorSet(claw, 0);
  }
}
