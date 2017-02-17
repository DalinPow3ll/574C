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
  if (digitalRead(12) == LOW){
    rCube();
  }else if(digitalRead(11) == LOW){
    lCube();
  }else if(digitalRead(10) == LOW){
    rStar();
  }else if(digitalRead(9) == LOW){
    lStar();
  }else if(digitalRead(8) == LOW){
    rSensor();
  }else if(digitalRead(7) == LOW){
    rCubeLong();
  }else if(digitalRead(6) == LOW){
    lCubeLong();
  }else if(digitalRead(5) == LOW){
    straight();
  }else{
    //dont run
    aTank(127,127);
  }
}
