#include "sensFunc.h"
#include "main.h"

int toDo;
int loopClock;


void rStar(){
  printf("autonomous");

  //starting loop
  encoderReset(driveEnc);
  loopClock = 0;
  while(1){
    toDo = 2;

    toDo -= tipOut(loopClock);
    toDo -= clawForward(cClose);

    //end of loop functions
    if(toDo == 0){break;} //end loop if all tasks are complete
    delay(10); //wait an interval to allow tip bar to complete
    loopClock += 10; //add to the total amount of time this loop has been running
  }

  encoderReset(driveEnc);
  while(1){
    toDo = 1;

    toDo -= tankDriveEnc(60, 10, -100);

    //end of loop functions
    if(toDo == 0){break;} //end loop if all tasks are complete
    delay(10); //wait an interval to allow tip bar to complete
    loopClock += 10; //add to the total amount of time this loop has been running
  }
}


void lStar(){

}
