//
// Created by Raquel Lopes de Oliveira on 18/01/2016.
//

#include "dictionary.h"

int createDictionary() {
    fileOut = "Resources/exempleToDecompress"; // To Test
    output = fopen(fileOut, "r"); // To test
    if (!output){ //to test
        return -1; //to test
        //exit(EXIT_FAILURE);
    }

    char c = getc(output);
    int numberElements = c; // First byte in a integer

    printf("The number of elements is: %d\n", (numberElements + 1));

    Dictionary *dictionary = malloc(sizeof(Dictionary));
    setSize(dictionary, (numberElements+1));
    printf("The number of elements is: %d\n", dictionary->size);
    dictionary->elements = malloc((numberElements)* sizeof(Character));
    int i = 0; int aux_elem =0;
    for (; i < getSize(dictionary); ++i) {
        setValue(dictionary, i, getc(output));
       // dictionary->elements[i].value = getc(output);;
        setSizeOfKey(dictionary, i, getc(output));
        //dictionary->elements[i].sizeOfKey = getc(output);
        int pos = (getSizeOfKey(dictionary, i)) -1;
        //int pos = dictionary->elements[i].sizeOfKey -1;
        int bitSet;
        c = getc(output);
        for(int k = 1; k <= getSizeOfKey(dictionary, i); k++){
            bitSet = get_bit(c, k);
            setKey(dictionary, i, setBit(getKey(dictionary, i),pos, bitSet));
            pos--;
        }
        printf("---------The key of element: %c is %d with size %d----------\n", getValue(dictionary, i), getKey(dictionary, i), getSizeOfKey(dictionary, i));

    }
    setQtdOfLastByte(dictionary, getc(output));
    printf("The last byte will use %d number of bits\n", getQtdBitsOfLastByte(dictionary) );

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