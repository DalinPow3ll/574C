#include "API.h"
#include "main.h"

void aLift(int direction){
  motorSet(lift1, direction); // set arm left 1
  motorSet(lift2, direction); // set arm left 2
  motorSet(lift3, direction); // set arm left 3
  motorSet(lift4, direction); // set arm left 4
}

void aTank(int right, int left){
  right = -right;
  motorSet(drive1, left);
  motorSet(drive2, left);
  motorSet(drive3, right);
  motorSet(drive4, right);
}

void aDrive (int direction) {
if (direction == 1 || direction == 3) {
    motorSet(drive1, 127);
    motorSet(drive2, 127);
  }else if (direction == 4){
    motorSet(drive1, 0);
    motorSet(drive2, 0);
  }else{
    motorSet(drive1, -127);
    motorSet(drive2, -127);
  }

  if (direction == 1 || direction == 2) {
    motorSet(drive4, -80);
    motorSet(drive3, -80);
  }else if (direction == 4){
    motorSet(drive4, 0);
    motorSet(drive3, 0);
  }else{
    motorSet(drive4, 80);
    motorSet(drive3, 80);
  }
}
