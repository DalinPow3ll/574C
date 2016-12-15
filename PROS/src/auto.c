

#include "main.h"
#include "programs.h"



void autonomous() {

  /*drive key
  0 = backward
  1 = forward
  2 = left
  3 = right
  4 = stop
  */

  // autonmous selector
  // all programs are contained inside of the "programs.c" file
  if (digitalRead(rightCubePin) == LOW){
    rCube();
  }else if(digitalRead(leftCubePin) == LOW){
    lCube();
  }else if(digitalRead(rightStarPin) == LOW){
    rStar();
  }else{
    straight();
  }

}
