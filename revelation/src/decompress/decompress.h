//
// Created by Raquel Lopes de Oliveira on 19/01/2016.
//

#ifndef REVELATIONN_DECOMPRESS_H
#define REVELATIONN_DECOMPRESS_H

#include "../arguments.h"
#include "../utils/utilBit.h"

typedef struct character {
    char value;
    char key;
    int sizeOfKey;
    struct Caractere *next;
} Character;

typedef struct {
    Character* elements; //Change this number to the number of first byte
    int size;
    int valueLastByte;
} Dictionary;

int createDictionary();
#endif //REVELATIONN_DECOMPRESS_H
