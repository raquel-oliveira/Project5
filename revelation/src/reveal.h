#ifndef _REVEAL_H_
#define  _REVEAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <opencv/highgui.h>
#include "image.h"

uchar* revealDirect(IplImage *img, int b, char* help, uchar* message);
uchar* revealReverse(IplImage *img, int b, char* help, uchar* message);


#endif