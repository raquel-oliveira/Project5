//
// Created by Raquel Lopes de Oliveira on 18/01/2016.
//

#include "dictionary.h"

Dictionary* createDictionary(FILE* afterReveal) {
    if (!afterReveal){ //to test
        return -1; //to test
    }

    char c = getc(output);
    int numberElements = c; // First byte in a integer
    Dictionary *dictionary = malloc(sizeof(Dictionary));
    setSize(dictionary, (numberElements+1));
    printf("The number of elements is: %d\n", dictionary->size);
    dictionary->elements = malloc((numberElements)* sizeof(Character));
    int i = 0; int aux_elem =0;
    for (; i < getSize(dictionary); ++i) {
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
        printf("---------The key of element: %c is %d with size %d----------\n", getValue(dictionary, i), getKey(dictionary, i), getSizeOfKey(dictionary, i));

    }
    setQtdOfLastByte(dictionary, getc(output));
    printf("The last byte will use %d number of bits\n", getQtdBitsOfLastByte(dictionary) );
    //Create a temp file to save only the message
    /*FILE *temp = fopen("tempMessageNotDecode.txt", "a");
    char mes;
    for (int i = 0; i < 1; i++){ //to test
        mes = getc(afterReveal);
        if (afterReveal!=NULL)
        {
            fputs (&mes,temp);
        }
    }*/

    printf("TRYIND DECOMPRESSION TO TEST INSIDE \n");
    FILE *outputFinal;
    outputFinal = fopen("realfinal.txt", "w+");

    uchar AII = getc(afterReveal);
    printf("The first byte tooken as char is: %c\n", AII);
    printf("The first byte tooken was int is: %d\n", AII);

    int contador = 0;
    printf("First bit is %d\n", get_bit(AII, 1));
    uchar toCheck = setBit(toCheck, 0, get_bit(AII, 1));
    contador++;
    printf("toCheck is as int : %d\n\n", toCheck);

    toCheck = setBit(toCheck, 1, get_bit(AII, 2));
    contador++;
    printf("Second bit is %d\n", get_bit(AII, 2));
    printf("toCheck is as int : %d\n\n", toCheck);


    printf("toCheck is in char: %c\n", toCheck);
    printf("toCheck is as int : %d\n", toCheck);
    for(int i = 0; i < getSize(dictionary); i++){
        printf("----- Loop for %c \n", getValue(dictionary, i));
        if(contador == getSizeOfKey(dictionary, i)){
            printf("Same size \n");
            char aa = getKey(dictionary, i);
            printf("KEY OF THIS CARACTER IS: %d\n", aa);
            if(toCheck == aa){
                printf("Equal with %c\n", getValue(dictionary, i));
                printf("Because tocheck: %d is equal to %d\n", toCheck, aa);
                if (outputFinal!=NULL)
                {
                    char bla = getValue(dictionary, i);
                    fputs (&bla,outputFinal);
                }
            }
            else{
                printf("Nor equal\n");
            }
        }
        else{
            printf("Not the same size\n");
        }
    }
    return dictionary;

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