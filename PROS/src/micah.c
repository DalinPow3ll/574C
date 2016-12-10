#include "API.h"

//drive variables
int power = 0;
int turn = 0;

void mDrive(){

  int joyP;
  int joyT;

  int slew = 3; //slew constant

  joyP = -joystickGetAnalog(1, 1); // horizontal axis on left joystick
  joyT = joystickGetAnalog(1, 2); // vertical axis on left joystick

  //dead zone
  if(abs(joyP) > 15){ // get the absolute value of joystick on horizontal axis
    joyP = 0;
  }
  if(abs(joyT) > 15 ){ // get the absolute value of joystick on horizontal axis
    joyT = 0;
  }


  //slowly accelerate motors to where joystick is
  //accelerate at rate of slew

  //power
  if(power < joyP-slew){
    power += slew;
  }else if(power > joyP+slew){
    power -= slew;
  }else{
    power = 0;
  }

  //turn
  if(turn < joyT-slew){
    turn += slew;
  }else if(turn > joyT+slew){
    turn -= slew;
  }else{
    turn = 0;
  }

    //left wheels
    motorSet(9, power + turn);
    motorSet(3, power + turn);

    // right wheels
    motorSet(10, power - turn);
    motorSet(2, power - turn);
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
