#include "progInc.h"
#include "sensFunc.h"

int toDo;
int loopClock;


int margin = 10; //encoder turn margin

void rSensor(){

    //claw out
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 2;
      toDo -= tipOut(loopClock);
      toDo -= clawForward(cClose, 0);
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }


    //reverse
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 1;
      toDo -= tankDriveEnc(60, 10, -100);
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }


    //forward
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 1;
      toDo -= tankDriveEnc(115, 127, 1200);
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //grab and reverse
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 3;
      if(loopClock > 700){toDo -= tankDriveEnc(127, 60, -1200); toDo -= liftLoop(loopClock, 1200, -127, -35);}
      toDo -= clawForward(cSqz, 40);
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //throw
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 2;
      toDo -= liftLoop(loopClock, 1500, -127, 0);
      if(loopClock > 900){toDo -= clawBack(cClose);}
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //reset and correct
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 2;
      toDo -= liftLoop(loopClock, 1400, 60, 0);
      if(loopClock > 700){toDo -= tankDriveEnc(127, 95, 700);}
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //grab and reverse cube # 1
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 3;
      toDo -= clawForward(cSqz+300, 35);
      if(loopClock > 800){toDo -= liftLoop(loopClock, 1400, -127, -40);}
      if(loopClock > 1200){toDo -= tankDriveEnc(127, 127, -700);}
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //throw
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 2;
      toDo -= liftLoop(loopClock, 1500, -127, 0);
      if(loopClock > 900){toDo -= clawBack(cClose);}
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //reset
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 2;
      toDo -= liftLoop(loopClock, 1400, 60, 0);
      if(loopClock > 700){toDo -= tankDriveEnc(127, 127, 700);}
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //grab and reverse # 2
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 3;
      toDo -= clawForward(cSqz+300, 35);
      if(loopClock > 800){toDo -= liftLoop(loopClock, 1400, -127, -40);}
      if(loopClock > 1200){toDo -= tankDriveEnc(127, 127, -700);}
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //throw
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 2;
      toDo -= liftLoop(loopClock, 1500, -127, 0);
      if(loopClock > 900){toDo -= clawBack(cClose);}
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //reset
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 2;
      toDo -= liftLoop(loopClock, 1400, 60, 0);
      if(loopClock > 700){toDo -= tankDriveEnc(115, 127, 700);}
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //grab and reverse # 3
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 3;
      toDo -= clawForward(cSqz+300, 35);
      if(loopClock > 800){toDo -= liftLoop(loopClock, 1400, -127, -40);}
      if(loopClock > 1200){toDo -= tankDriveEnc(127, 127, -700);}
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //throw
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 2;
      toDo -= liftLoop(loopClock, 1500, -127, 0);
      if(loopClock > 900){toDo -= clawBack(cClose);}
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //mid cube line up reset
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 2;
      toDo -= liftLoop(loopClock, 1400, 60, 0);
      if(loopClock > 700){toDo -= tankDriveEnc(127, 20, 600);}
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //grab and reverse
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 3;
      toDo -= clawForward(cSqz+300, 35);
      if(loopClock > 800){toDo -= liftLoop(loopClock, 1400, -127, -40);}
      if(loopClock > 1200){toDo -= tankDriveEnc(127, 15, -500);}
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //throw
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 2;
      toDo -= liftLoop(loopClock, 1500, -127, 0);
      if(loopClock > 900){toDo -= clawBack(cClose);}
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //reset
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 2;
      toDo -= liftLoop(loopClock, 1400, 60, 0);
      if(loopClock > 700){toDo -= tankDriveEnc(95, 127, 700);}
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //grab and reverse # 4
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 3;
      toDo -= clawForward(cSqz+250, 35);
      if(loopClock > 800){toDo -= liftLoop(loopClock, 1400, -127, -40);}
      if(loopClock > 1200){toDo -= tankDriveEnc(127, 127, -700);}
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }

    //throw
    loopClock = 0; encoderReset(driveEnc);
    while(1){
      toDo = 2;
      toDo -= liftLoop(loopClock, 1500, -127, 0);
      if(loopClock > 900){toDo -= clawBack(cClose);}
      if(toDo == 0){break;}delay(10);loopClock += 10;
    }
}
