#include "progInc.h"

//program includes
#include "prog/straight.h"

int RIGHT = -260;
int LEFT = 260;


void rSensor(){
  int toDo; // variable to tell how many tasks in a loop have finished
  int loopClock; // for controlling delays inside of loops

  int margin = 10; //encoder turn margin

  motorSet(tipBar, 127); // open the tip bar, will need a loop delay bc there is no sensor

  loopClock = 0; //reset loop clock for next loop


  encoderReset(driveEnc);

  //simultaneous loop for claw, arm, and drive
  while(1){
    //loop will go until it sees a break

    toDo = 3; // number of tasks to do in this loop

    //claw logic
    if(analogRead(clawPot) < cMid){ //if claw not at middle position
      motorSet(claw, 127); //move it forward
    }else{
      motorSet(claw, 0);
      toDo--; // task complete
    }

    //tip bar stop
    if (loopClock > 1300) { //if loop has been runnning for 1.3 seconds
      motorSet(tipBar, 0); // stop the tip bar
      toDo--; // task complete
    }

    //turn 90 degrees
    if (encoderGet(driveEnc) > RIGHT + margin){
      aTank(70,-70);
    }else if(encoderGet(driveEnc) < RIGHT - margin){
      aTank(-50,50); // on over shoot, go back
    }else{
      aDrive(4); // stop
      toDo--;
    }
    printf("encoder: %d\n", encoderGet(driveEnc) );


    if(toDo == 0){break;} //end loop if all tasks are complete

    delay(20); //wait an interval to allow tip bar to complete
    loopClock += 20; //add to the total amount of time this loop has been running
  }
}
