#include "API.h"
#include "main.h"

//drive variables
int turn = 0;
int power = 0;



void mDrive(){

  int joyT;
  int joyP;

  int slew = 15; //slew constant


  joyT = -joystickGetAnalog(1, 1); // horizontal axis on left joystick
  joyP = joystickGetAnalog(1, 2); // vertical axis on left joystick

  /*
  //dead zone
  if(abs(joyT) > 15){ // get the absolute value of joystick on horizontal axis
    joyT = 0;
  }
  if(abs(joyP) > 15 ){ // get the absolute value of joystick on horizontal axis
    joyP = 0;
  }
  */

  //slowly accelerate motors to where joystick is
  //accelerate at rate of slew

  //turn
  if(turn < joyT){
    turn += slew;
  }else if(turn > joyT){
    turn -= slew;
  }else{
    turn = 0;
  }

  //power
  if(power < joyP){
    power += slew;
  }else if(power > joyP){
    power -= slew;
  }else{
    power = 0;
  }


  //right wheels
  motorSet(drive3, turn + power);
  motorSet(drive2, turn + power);

  //left wheels
  motorSet(drive4, turn - power);
  motorSet(drive1, turn - power);
}

void mClaw(){
  // claw code
  if(joystickGetDigital(1, 6, JOY_UP)) {
    if(analogRead(2) > 100){
      motorSet(claw, 40); // set motor low turn
    }else{
      motorSet(claw, 127); //set motor full turn
    }
  }else if(joystickGetDigital(1, 6, JOY_DOWN)) {
    motorSet(claw, -127); // set motor
  }else{
    motorSet(claw, 0);
  }
}
