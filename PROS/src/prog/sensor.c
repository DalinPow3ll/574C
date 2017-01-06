#include "progInc.h"

//program includes
#include "prog/straight.h"

int RIGHT90 = -260;
int LEFT90 = 260;

int RIGHT45 = -120;
int LEFT45 = 120;


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
      motorSet(claw, 0); //stop claw
      toDo--; // task complete
    }

    //tip bar stop
    if (loopClock > 1300) { //if loop has been runnning for 1.3 seconds
      motorSet(tipBar, 0); // stop the tip bar
      toDo--; // task complete
    }

    if(analogRead(clawPot) > cClose){
      //turn left
      if (encoderGet(driveEnc) < LEFT45 - margin){
        aTank(-90, 90);
      }else if(encoderGet(driveEnc) > LEFT45 + margin){
        aTank(50, -50);
      }else{
        aDrive(4); // stop
        toDo--;
      }
    }


    if(toDo == 0){break;} //end loop if all tasks are complete

    delay(20); //wait an interval to allow tip bar to complete
    loopClock += 20; //add to the total amount of time this loop has been running
  }


  loopClock = 0; //reset loop clock for next loop

  encoderReset(driveEnc); // encoder reset

  //drive and grab loop
  while(1){
    toDo = 2; //tasks in this loop

    //claw logic
    if(loopClock < 1500 && loopClock > 500){
      motorSet(claw, 100); //squeeze
    }else{
      motorSet(claw, 30); //low power
      toDo--; // task complete
    }

    //drive forward
    if (encoderGet(driveEnc) < 1200){
      aDrive(1);
    }else{
      aDrive(4); // stop
      toDo--;
    }

    if(toDo == 0){break;} //end loop if all tasks are complete

    delay(20); //wait an interval to allow tip bar to complete
    loopClock += 20; //add to the total amount of time this loop has been running
  }

  //lift arm
  aLift(-127); //lift stars up
  delay(600);
  aLift(-30); //hold the stars up

  //reverse
  while (encoderGet(driveEnc) > 700){
    aDrive(0);
  }


  encoderReset(driveEnc); // encoder reset

  //slant reverse and throw
  while (encoderGet(driveEnc) > -1400){
    aTank(-127,-40); //slant reverse
  }

  aDrive(0); //reverse
  aLift(-127); //lift
  motorSet(claw, -127);// throw
  delay(500);
  aDrive(4); //stop bot
  
  motorStopAll(); //pause



  //dummy loop
  while(1){
    toDo = 0; //tasks in this loop

    loopClock = 0; //reset loop clock for next loop
    encoderReset(driveEnc); // encoder reset

    if(toDo == 0){break;} //end loop if all tasks are complete

    delay(20); //wait an interval to allow tip bar to complete
    loopClock += 20; //add to the total amount of time this loop has been running
  }

}
