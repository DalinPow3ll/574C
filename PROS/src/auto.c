#include "main.h"

//program includes
#include "straight.h"
#include "cube.h"
#include "star.h"
#include "sensor.h"

void autonomous() {


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
