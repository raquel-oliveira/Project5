#ifndef _FILE_H_
#define  _FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_bit(char the_byte,int which_bit);

char intToChar(int a);

char intBToChar(int a);

char* messageFromOneColor(int **matrixColor, int b, int height, int width );

char* messageFromTwoColor(int **firstColor, int **secondColor, int b, int height, int width );

char* messageFromThreeColor(int **firstColor, int **secondColor, int **thirdColor, int b, int height, int width );

#endif