#include "API.h"
#include "main.h"

void mDrive(){

  int turn;
  int power;

  turn = -joystickGetAnalog(1, 1); // horizontal axis on left joystick
  power = joystickGetAnalog(1, 2); // vertical axis on left joystick

  //dead zone
  if(abs(power) < 15){
    power = 0;
  }
  if(abs(turn) < 15){
    turn = 0;
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
