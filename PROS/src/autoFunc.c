#include "API.h"

void aLift(int direction){
  motorSet(4, direction); // set arm left 1
  motorSet(5, direction); // set arm left 2
  motorSet(6, direction); // set arm left 3
  motorSet(7, direction); // set arm left 4
}



void aDrive (int direction) {
if (direction == 0 || direction == 3) {
    motorSet(2, 127);
    motorSet(10, 127);
  }else if (direction == 4){
    motorSet(2, 0);
    motorSet(10, 0);
  }else{
    motorSet(2, -127);
    motorSet(10, -127);
  }

  if (direction == 0 || direction == 2) {
    motorSet(3, -127);
    motorSet(9, -127);
  }else if (direction == 4){
    motorSet(3, 0);
    motorSet(9, 0);
  }else{
    motorSet(3, 127);
    motorSet(9, 127);
  }
}
