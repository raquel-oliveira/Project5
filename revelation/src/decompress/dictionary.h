//
// Created by Raquel Lopes de Oliveira on 20/01/2016.
//

#ifndef REVELATIONN_DICTIONARY_H
#define REVELATIONN_DICTIONARY_H

#include "../arguments.h"
#include "../utils/utilBit.h"
#include <stdio.h>

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

char getSize(Dictionary* d);

void setSize(Dictionary* d, char sizee);

int getQtdBitsOfLastByte(Dictionary* d);

void setQtdOfLastByte(Dictionary* d, int qtd);

char getValue(Dictionary* d, int index);

void setValue(Dictionary* d, int index, char valuee);

char getKey(Dictionary* d, int index);

void setKey(Dictionary* d, int index, char keey);

int getSizeOfKey(Dictionary* d, int index);

void setSizeOfKey(Dictionary* d, int index, int size);

int createDictionary(FILE* afterReveal, Dictionary* dictionary);

void printDictionary(Dictionary d);

#endif //REVELATIONN_DICTIONARY_H
