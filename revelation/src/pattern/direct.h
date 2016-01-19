//
// Created by Raquel Lopes de Oliveira on 19/01/2016.
//

#ifndef REVELATIONN_DIRECT_H
#define REVELATIONN_DIRECT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <opencv/highgui.h>
#include "../image.h"
#include "../utils/utilBit.h"
#include "../arguments.h"

int revealDirect(IplImage *img, int nbBits, char *magic, int firstColor, int secondColor, int thirdColor);

#endif //REVELATIONN_DIRECT_H

