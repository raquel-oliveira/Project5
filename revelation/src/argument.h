#ifndef _ARGUMENT_
#define _ARGUMENT_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *formatIn, *fileIn, *fileOut, *nbBits, *channels, *pattern;

void argument(int argc, char *argv[]);
char * getArg(char *what);

#endif