//
// Created by Raquel Lopes de Oliveira on 23/01/2016.
//

#ifndef REVELATIONN_FILE_H
#define REVELATIONN_FILE_H

#include "stdio.h"
#include <string.h>
#include <opencv2/hal/defs.h>

void printFile(FILE* file, char* path);

int containsMagicNumber(char* message,int messageSize,char* magic,int magicSize);

#endif //REVELATIONN_FILE_H