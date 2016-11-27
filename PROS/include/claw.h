#ifndef _claw_H_
#define _claw_H_

#include "main.h"

// Sets the speeds of the left and right wheels of the claw
void clawMove(int clawDirection);
int clawGetDirection();
void clawStop();
void clawStart(int direction);

#endif // _claw_H_
