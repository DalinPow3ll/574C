#include "autoFunc.h"
#include "API.h"
#include "main.h"

//right cube function
void rCube (){
  // right cube
  aDrive(1); // forward
  motorSet(claw, 127); // close claw
  delay(1350);
  aDrive(4); //stop
  delay(1600);
  motorSet(claw, 40); //low power
  delay(300);
  aLift(-127); //lift the cube
  delay(500);
  aLift(-20); //hold the cube
  aDrive(3); //turn
  delay(520);
  aDrive(4); //stop
  delay(300);
  aDrive(0); //reverse
  delay(300);
  aLift(-127);
  delay(500);
  motorSet(claw, -127);
  delay(300);
  aLift(0); // stop lift
  delay(600);
  motorSet(claw, 0);
  aDrive(4); // stop
  motorStopAll(); //end routine
}


void lCube(){
  // left cube
  aDrive(1); // forward
  motorSet(claw, 127); // close claw
  delay(1350);
  aDrive(4); //stop
  delay(1600);
  motorSet(claw, 40); //low power
  delay(300);
  aLift(-127); //lift the cube
  delay(500);
  aLift(-20); //hold the cube
  aDrive(2); //turn
  delay(600); // left is slower for some reason
  aDrive(4); //stop
  delay(300);
  aDrive(0); //reverse
  delay(300);
  aLift(-127);
  delay(500);
  motorSet(claw, -127);
  delay(300);
  aLift(0); // stop lift
  delay(600);
  motorSet(claw, 0);
  aDrive(4); // stop
  motorStopAll(); //end routine
}

void rStar(){
  motorSet(tipBar, 127); // bring out tip bar
  motorSet(claw, 127); // open claw
  delay(1500);
  motorSet(tipBar, 0); // stop tipbar
  delay(500);
  aDrive(3); //turn left
  delay(300);
  motorSet(claw, 0);
  aDrive(4); //stop bot
  delay(200);
  aDrive(1); // drive forward
  delay(800);
  motorSet(claw, 127); //close claw
  delay(600);
  motorStopAll();
  motorSet(claw, 40); // hold stars
  aLift(-127); //lift stars up
  delay(550);
  aLift(-30); //hold the stars up
  aDrive(0); // reverse
  delay(1800);
  aDrive(4); // pause
  delay(300);
  aDrive(3); // turn left
  delay(330);
  aDrive(4);
  delay(300);
  aDrive(0); // reverse
  delay(1200);
  aLift(-127);
  delay(200);
  motorSet(claw, -127);
  delay(500);
  aLift(0);
  motorStopAll();
}


void lStar(){
  motorSet(tipBar, 127); // bring out tip bar
  motorSet(claw, 127); // open claw
  delay(1500);
  motorSet(tipBar, 0); // stop tipbar
  delay(500);
  aDrive(2); //turn right
  delay(300);
  motorSet(claw, 0);
  aDrive(4); //stop bot
  delay(200);
  aDrive(1); // drive forward
  delay(800);
  motorSet(claw, 127); //close claw
  delay(600);
  motorStopAll();
  motorSet(claw, 40); // hold stars
  aLift(-127); //lift stars up
  delay(550);
  aLift(-30); //hold the stars up
  aDrive(0); // reverse
  delay(1800);
  aDrive(4); // pause
  delay(300);
  aDrive(2); // turn right
  delay(330);
  aDrive(4);
  delay(300);
  aDrive(0); // reverse
  delay(1200);
  aLift(-127);
  delay(200);
  motorSet(claw, -127);
  delay(500);
  aLift(0);
  motorStopAll();
}

void rSensor(){
  int toDo; // variable to tell how many tasks in a loop have finished
  int loopClock; // for controlling delays inside of loops

  motorSet(tipBar, 127); // open the tip bar, will need a loop delay bc there is no sensor



  loopClock = 0; //reset loop clock for next loop

  //simultaneous loop for claw, arm, and drive
  while(1){
    //loop will go until it sees a break

    toDo = 2; // there are 2 tasks to do in this loop

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


    if(toDo == 0){break;} //end loop if all tasks are complete

    delay(20); //wait an interval to allow tip bar to complete
    loopClock += 20; //add to the total amount of time this loop has been running
  }
}

void straight(){
  motorSet(tipBar, 127); //bring out tip
  aDrive(1); // drive forward
  motorSet(claw, 127); // open claw
  aLift(-127); //start lifting arm
  delay(800);
  aLift(0);
  delay(800);
  motorSet(tipBar, 0); //stop the tip bars
  motorSet(claw, 0); // stop claw at half way
  aDrive(4); // stop driving
  delay(500);
  aDrive(0); // drive backward
  delay(500);
  motorSet(claw, 127);
  delay(500);
  motorStopAll(); //end routine
}
