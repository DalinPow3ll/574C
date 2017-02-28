#include "progInc.h"
#include "main.h"

void clawBack(){
  int complete = 0;

  while(complete == 0){
    //claw logic
    if(analogRead(clawPot) < cMid){ //if claw not at open position
      motorSet(claw, -127); //move it back
    }else{
      motorSet(claw, 0); //stop claw
      complete = 1; // task complete
    }
  }
}

void tankDriveEnc (int speed, int distance){
  encoderReset(driveEnc); //reset drive encoder
  int complete = 0;
  int margin = 10;
    while (complete == 0){
      if(encoderGet(driveEnc) < distance - margin){
        aTank(-speed, speed);
      }else if(encoderGet(driveEnc) > distance + margin){
        aTank(speed, -speed);
      }else{
        aDrive(4); // stop
        complete = 1;
      }
  }
}
