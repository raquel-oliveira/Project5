#ifndef _REVEAL_H_
#define  _REVEAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <opencv/highgui.h>
#include "image.h"
#include "hiddenTxt.h"

void print3channels(const IplImage* img, CvScalar pixel );

void print1channel(const IplImage* img, CvScalar pixel );

#endif