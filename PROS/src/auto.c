#include "main.h"
#include "autoFunc.h"


//program includes
#include "straight.h"
#include "cube.h"
#include "star.h"
#include "skills.h"

void autonomous() {
  // autonmous selector
  if (digitalRead(12) == LOW){
    rCubeLong();
  }else if(digitalRead(11) == LOW){
    lCubeLong();
  }else if(digitalRead(10) == LOW){
    straight();
  }else{
    skills();
  }
}
