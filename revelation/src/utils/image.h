#ifndef _IMAGE_H_
#define  _IMAGE_H_

#include <stdio.h>
#include <stdlib.h>
#include <opencv/highgui.h>
#include <magic.h>
#include "../utils/formatDetector.h"


int getHeight(IplImage* img);

int getWidth(IplImage* img);

int getStep(IplImage* img);

int getChannels(IplImage* img);

void showImage(IplImage* img);

CvScalar* getIntensityPixel(IplImage* img);

double *redIntensity(IplImage* img);

double *bits(IplImage* img);

#endif