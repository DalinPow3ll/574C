#include "main.h"
//program includes
#include "prog/straight.h"
#include "prog/cube.h"
#include "prog/star.h"
#include "prog/sensor.h"

void autonomous() {

  if(isOnline() == false && BootLoader == true){

    // autonmous selector
    // all programs are contained inside of the "programs.c" file
    if (digitalRead(rightCubePin) == LOW){
      rCube();
    }else if(digitalRead(leftCubePin) == LOW){
      lCube();
    }else if(digitalRead(rightStarPin) == LOW){
      rStar();
    }else if(digitalRead(leftStarPin) == LOW){
      lStar();
    }else if(digitalRead(rSensorPin) == LOW){
      rSensor();
    }else{
      straight();
    }
  }
}
