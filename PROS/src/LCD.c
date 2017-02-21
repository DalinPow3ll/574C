#include "API.h"
#include "main.h"

void LCDInit(){
  lcdInit(uart1);
  lcdSetBacklight(uart1, true);
}

void LCDBattery(){
  lcdClear(uart1);
  int power = powerLevelMain();
  char str[16];
  sprintf(str, "Main: %d", power);
  lcdSetText(uart1, 1, str);
  int backUp = powerLevelBackup();
  sprintf(str, "9V: %d", backUp);
  lcdSetText(uart1, 2, str);
}

void LCDPot(){
  lcdClear(uart1);
  int value = analogRead(clawPot);
  char str[16];
  sprintf(str, "%d", value);
  lcdSetText(uart1, 1,"Potentiometer:");
  lcdSetText(uart1, 2, str);
}

void LCDEnc(){
  lcdClear(uart1);
  int ticks = encoderGet(driveEnc);
  char str[16];
  sprintf(str, "%d", ticks);
  lcdSetText(uart1, 1,"Ticks:");
  lcdSetText(uart1, 2, str);
}

void LCDTasker(){
  if(lcdReadButtons(uart1) == 1){
    LCDBattery();
  }else if(lcdReadButtons(uart1) == 2){
    LCDPot();
  }else if(lcdReadButtons(uart1) == 4){
    LCDEnc();
  }
}
