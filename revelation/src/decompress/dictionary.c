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

   // while(afterReveal!=EOF){
        uchar byteM = getc(afterReveal);
        uchar toCheck;
        int contador = 0;
        int aux =1;

        toCheck = setBit(toCheck, contador, get_bit(byteM, aux)); //check if here is actually contador+1;
    printf("Took the %d element of the byte\n", aux);
        contador++;
    int endOfFile;
    //for(int j = 0; j < 30; j++) {
    while(!feof(afterReveal)){
        int oi = 1;
        printf("----------NEW LOOP ON THE DICTIONARY---------------\n");
        printf("*****----------This is the %d loop in in the dictionary to check the value %d\n-------------", oi++, toCheck);
        for(int i = 0; i < getSize(dictionary); i++) {
            printf("--------Testing with the value: %c----------\n", getValue(dictionary, i));
            if ((contador) == getSizeOfKey(dictionary, i)) {
                printf("Contador == %d\n", contador);
                printf("Same size \n");
                if(toCheck == getKey(dictionary, i)){
                    printf("Equal with %c\n", getValue(dictionary, i));
                    contador = 0;
                    toCheck = 0;
                    if (outputFinal!=NULL)
                    {
                        char bla = getValue(dictionary, i);
                        fputs (&bla,outputFinal);
                        printf("Wrote in the file the letter %c\n", bla);
                    }
                    printf("Contador == %d\n", contador);
                }
                else{
                    printf("Not is the same\n");
                    printf("Contador == %d\n", contador);
                }
            }
            else {
                printf("Not match with the size\n");
            }
        }

        if(aux == 8){
            printf("Take a new byte");
            aux = 0;
            byteM = getc(afterReveal);
            printf("NEW BYTE\n");
        }
    toCheck = toCheck << 1;
    printf("toCheck after the decalage as int : %d\n", toCheck);
        aux++;
        printf("Took the %d element of the byte\n", aux);
        printf("Set the bit %d in the last bit:\n", get_bit(byteM, aux));
    toCheck = setBit(toCheck, 0, get_bit(byteM, aux));
    printf("toCheck after set the new bit s as int : %d\n", toCheck);
    contador++;
    printf("Contador == %d\n", contador);

    }



  //  }
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