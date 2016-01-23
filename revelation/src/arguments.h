//
// Created by Raquel Lopes de Oliveira on 10/01/2016.
//

#ifndef REVELATIONN_ARGUMENTS_H
#define REVELATIONN_ARGUMENTS_H

#include <string.h>
#include <stdio.h>
#include "getopt.h"
#include <opencv2/hal/defs.h>
#include <opencv2/core/types_c.h>
#include <stdbool.h>
#include <ctype.h>

extern char *formatIn, *fileIn, *fileOut, *channels, *pattern, *magic, *magicHexa;
extern bool isCompress, isStandard, isShow;
extern IplImage *img;
extern int flag;
extern int firstChannel, secondChannel, thirdChannel, nbBits, patternInt;
#endif //REVELATIONN_ARGUMENTS_H
