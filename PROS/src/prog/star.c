#include "sensFunc.h"
#include "main.h"

void rStar(){
  printf("autonomous");

  int toDo;
  int loopClock;

  //starting loop
  encoderReset(driveEnc);
  loopClock = 0;
  while(1){
    lcdClear(uart1);
    lcdSetText(uart1, 1, "autonomous");
    toDo = 2; //amount of tasks

    toDo -= tipOut(loopClock);
    toDo -= clawForward(cClose);


    //end of loop functions
    if(toDo == 0){break;} //end loop if all tasks are complete
    delay(10); //wait an interval to allow tip bar to complete
    loopClock += 10; //add to the total amount of time this loop has been running
  }
}


void lStar(){

}
