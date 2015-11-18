#ifndef _REVEAL_H_
#define  _REVEAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <opencv/highgui.h>
#include "image.h"
#include "file.h"

void printMatrixChannels(const IplImage* img, CvScalar pixel, int channels );

void reveal(const IplImage* img, CvScalar pixel);

void revealrgb(const IplImage* img, CvScalar pixel);

#endif