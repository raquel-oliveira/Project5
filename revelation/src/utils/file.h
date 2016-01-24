//
// Created by Raquel Lopes de Oliveira on 23/01/2016.
//

#ifndef REVELATIONN_FILE_H
#define REVELATIONN_FILE_H

#include "stdio.h"
#include <string.h>
#include "utilBit.h"
#include <opencv2/hal/defs.h>

void printFile(char* path);

int containsMagicNumber(char* message,int messageSize,char* magic,int magicSize);

void printFileBinary(char* path);

#endif //REVELATIONN_FILE_H