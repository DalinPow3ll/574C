#include "progInc.h"

//program includes
#include "prog/straight.h"

int RIGHT90 = -260;
int LEFT90 = 260;

int RIGHTCUBE = 330;
int LEFTCUBE = 330;

int margin = 10; //encoder turn margin

void rSensor(){
  int toDo; // variable to tell how many tasks in a loop have finished
  int loopClock; // for controlling delays inside of loops

  motorSet(tipBar, 127); // open the tip bar, will need a loop delay bc there is no sensor

  loopClock = 0; //reset loop clock for next loop


  encoderReset(driveEnc);

  //simultaneous loop for claw, arm, and drive
  while(1){
    //loop will go until it sees a break

    toDo = 3; // number of tasks to do in this loop

    //claw logic
    if(analogRead(clawPot) < cClose){ //if claw not at closed position
      motorSet(claw, 127); //move it forward
    }else{
      motorSet(claw, 30); //low power
      toDo--; // task complete
    }

    //tip bar stop
    if (loopClock > 1300) { //if loop has been runnning for 1.3 seconds
      motorSet(tipBar, 0); // stop the tip bar
      toDo--; // task complete
    }

    //drive forward
    if (encoderGet(driveEnc) < 820){
      aDrive(1); //drive forward
    }else{
      aDrive(4); // stop
      toDo--;
    }


    if(toDo == 0){break;} //end loop if all tasks are complete

    delay(20); //wait an interval to allow tip bar to complete
    loopClock += 20; //add to the total amount of time this loop has been running
  }


  /*
  //turn to throw
  if (encoderGet(driveEnc) > RIGHTCUBE + margin){
    aTank(70,-70);
  }else if(encoderGet(driveEnc) < RIGHTCUBE - margin){
    aTank(-50,50); // on over shoot, go back
  }else{
    aDrive(4); // stop
    toDo--;
  }
  */

}
