//
// Created by Raquel Lopes de Oliveira on 18/01/2016.
//

#include "dictionary.h"

int createDictionary(FILE* afterReveal, Dictionary* dictionary) {
    if (!afterReveal){
        return -1;
    }

    char c = getc(output);
    int numberElements = c; // First byte in a integer
    setSize(dictionary, (numberElements+1));
    dictionary->elements = malloc((numberElements)* sizeof(Character));
    for (int i = 0; i < getSize(dictionary); ++i) {
        setValue(dictionary, i, getc(afterReveal));
        setSizeOfKey(dictionary, i, getc(afterReveal));
        int pos = (getSizeOfKey(dictionary, i)) -1;
        int bitSet;
        c = getc(afterReveal);
        for(int k = 1; k <= getSizeOfKey(dictionary, i); k++){
            bitSet = get_bit(c, k);
            setKey(dictionary, i, setBit(getKey(dictionary, i),pos, bitSet));
            pos--;
        }
    }
    setQtdOfLastByte(dictionary, getc(output));
    return 0;

}

char getSize(Dictionary* d){
    return d->size;
}

void setSize(Dictionary* d, char sizee){
    d->size = sizee;
}

int getQtdBitsOfLastByte(Dictionary* d){
    return d->valueLastByte;
}

void setQtdOfLastByte(Dictionary* d, int qtd){
    d->valueLastByte = qtd;
}
char getValue(Dictionary* d, int index){
    return d->elements[index].value;
}

void setValue(Dictionary* d, int index, char valuee){
    d->elements[index].value = valuee;
}

char getKey(Dictionary* d, int index){
    return d->elements[index].key;
}

void setKey(Dictionary* d, int index, char keey){
    d->elements[index].key = keey;
}

int getSizeOfKey(Dictionary* d, int index){
    return d->elements[index].sizeOfKey;
}

void setSizeOfKey(Dictionary* d, int index, int size){
    d->elements[index].sizeOfKey = size;
}

void printDictionary(Dictionary d){
    for (int i = 0; i < getSize(&d); ++i) {
        printf("0x%x : ", getValue(&d, i));
        for(int siz = getSizeOfKey(&d, i); siz > 0; siz--){
            printf("%d", get_bit(getKey(&d,i),(9-siz)));
        }
        printf("\n");
    }
}