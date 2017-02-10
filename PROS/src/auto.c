#include "main.h"
#include "autoFunc.h"

//program includes
#include "straight.h"
#include "cube.h"
#include "star.h"
#include "sensor.h"
#include "skills.h"

void autonomous() {
  // autonmous selector
  // all programs are contained inside of the "programs.c" file
  if (digitalRead(12) == LOW){
    rCube();
  }else if(digitalRead(11) == LOW){
    lCube();
  }else if(digitalRead(10) == LOW){
    rStar();
  }else if(digitalRead(9) == LOW){
    lStar();
  }else if(digitalRead(8) == LOW){
    skills();
  }else{
    //dont run
  }
}
