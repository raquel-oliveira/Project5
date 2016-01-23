#ifndef _UTIL_H_
#define  _UTIL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <opencv2/hal/defs.h>

int get_bit(char the_byte,int which_bit);

uchar setBit(uchar ch, int pos, int bit);

void shift(char* message);

#endif