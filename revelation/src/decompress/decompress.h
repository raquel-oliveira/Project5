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

int createDictionary();
#endif //REVELATIONN_DECOMPRESS_H
