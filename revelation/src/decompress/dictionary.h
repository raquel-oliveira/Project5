//
// Created by Raquel Lopes de Oliveira on 20/01/2016.
//

#ifndef REVELATIONN_DICTIONARY_H
#define REVELATIONN_DICTIONARY_H

#include "../arguments.h"
#include "../utils/utilBit.h"
#include <stdio.h>

typedef struct character {
    uchar value;
    uchar* key;
    int sizeOfKey;
} Character;

typedef struct {
    Character* elements; //Change this number to the number of first byte
    int size;
    int valueLastByte;
} Dictionary;

char getSize(Dictionary* d);

void setSize(Dictionary* d, uchar sizee);

int getQtdBitsOfLastByte(Dictionary* d);

void setQtdOfLastByte(Dictionary* d, int qtd);

uchar getValue(Dictionary* d, int index);

void setValue(Dictionary* d, int index, char valuee);

uchar* getKey(Dictionary* d, int index);

void setKey(Dictionary d, int index, uchar keey, int indexKey);

int getSizeOfKey(Dictionary* d, int index);

void setSizeOfKey(Dictionary* d, int index, int size);

int createDictionary(FILE* afterReveal, Dictionary* dictionary);

void printDictionary(Dictionary* d);

#endif //REVELATIONN_DICTIONARY_H
