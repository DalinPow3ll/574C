#include "API.h"
#include "main.h"

void aLift(int direction){
  motorSet(lift1, direction); // set arm left 1
  motorSet(lift2, direction); // set arm left 2
  motorSet(lift3, direction); // set arm left 3
  motorSet(lift4, direction); // set arm left 4
}

void aTank(int left, int right){
  left = -left;
  motorSet(drive1, left);
  motorSet(drive4, left);
  motorSet(drive2, right);
  motorSet(drive3, right);
}

void aDrive (int direction) {
if (direction == 0 || direction == 3) {
    motorSet(drive1, 127);
    motorSet(drive4, 127);
  }else if (direction == 4){
    motorSet(drive1, 0);
    motorSet(drive4, 0);
  }else{
    motorSet(drive1, -127);
    motorSet(drive4, -127);
  }

  if (direction == 0 || direction == 2) {
    motorSet(drive2, -127);
    motorSet(drive3, -127);
  }else if (direction == 4){
    motorSet(drive2, 0);
    motorSet(drive3, 0);
  }else{
    motorSet(drive2, 127);
    motorSet(drive3, 127);
  }
}
