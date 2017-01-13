#include "API.h"
#include "main.h"

int page = 1;
int pressed = 0;

void LCDInit(){
  lcdInit(uart1);
  lcdSetBacklight(uart1, true);
}

void LCDSlap(){
  lcdClear(uart1);
  lcdSetText(uart1, 1, "SLAP SLAP SLAP");
  lcdSetText(uart1, 2, "CLAP CLAP CLAP");
}
void LCDScreen(){
  lcdClear(uart1);
  lcdSetText(uart1, 1, "I am....");
  lcdSetText(uart1, 2, "Double Zipper!");
}
void LCDZip(){
  lcdClear(uart1);
  lcdSetText(uart1, 1, "ZIIIIIIIIIIP");
  lcdSetText(uart1, 2, "ZIIIIIIIIIIP");
}


void LCDBattery(){
  lcdClear(uart1);
  int power = powerLevelMain();
  char str[16];
  sprintf(str, "%d", power);
  lcdSetText(uart1, 1,"Power:");
  lcdSetText(uart1, 2, str);
}
void pageReset(){
  page = 1;
}
void LCDPot(){
  lcdClear(uart1);
  int power = analogRead(clawPot);
  char str[16];
  sprintf(str, "%d", power);
  lcdSetText(uart1, 1,"Potentiometer:");
  lcdSetText(uart1, 2, str);
}

void LCDTasker(){
  if(lcdReadButtons(uart1) == 4 && pressed == 0){
    pressed = 1;
    page += 1;
  }else if(lcdReadButtons(uart1) == 1 && pressed == 0){
    page -= 1;
    pressed = 1;
  }else if(lcdReadButtons(uart1) == 0){
    pressed = 0;
  }


  switch(page){
    case 1:
      LCDBattery();
      break;

    case 2:
      LCDPot();
      break;

    case 3:
      LCDSlap();
      break;

    case 4:
      LCDZip();
      break;

    case 5:
      pageReset();
      break;

    default:
      LCDScreen();
  }

}
