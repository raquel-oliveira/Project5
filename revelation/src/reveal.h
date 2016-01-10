#ifndef _REVEAL_H_
#define  _REVEAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <opencv/highgui.h>
#include "image.h"
#include "utils/utilBit.h"

int reveal(IplImage *img, int nbBits, char *help, uchar *message, int firstColor, int secondColor, int thirdColor);

#endif