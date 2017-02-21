#include "progInc.h"
#include "main.h"

void clawBack(int position){
  int complete = 0;

  while(complete == 0){
    //claw logic
    if(analogRead(clawPot) < position){ //if claw not at closed position
      motorSet(claw, -127); //move it forward
    }else{
      motorSet(claw, 0); //stop claw
      complete = 1; // task complete
    }
  }
}

void tankDriveEnc (int speed, int distance){
  encoderReset(driveEnc); //reset drive encoder
  int complete = 0;
    while (complete == 0){
    int margin = 10;
    if (encoderGet(driveEnc) < distance - margin){
      aTank(speed, -speed);
    }else if(encoderGet(driveEnc) > distance + margin){
      aTank(-speed, speed);
    }else{
      aDrive(4); // stop
      complete = 1;
    }
  }
}
