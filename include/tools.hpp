#ifndef TOOLS_H
#define TOOLS_H

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768
#define LIMIT_TOP 0
#define LIMIT_BOTTOM 768
#define LIMIT_LEFT 0
#define LIMIT_RIGHT 1024

#define INIT_ALPHA 0.
#define INIT_SPEED 0.
#define SPEED_COEF .99
#define SPEED_STEP .2
#define SPEED_MAX 5
#define ROTATION_STEP 5

#define PLAYER_POWER 1.5

#include <math.h>

double toRad(double degrees);
double toDegrees(double rad);

#endif