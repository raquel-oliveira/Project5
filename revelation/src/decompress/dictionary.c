//
// Created by Raquel Lopes de Oliveira on 18/01/2016.
//

#include "dictionary.h"

int createDictionary(FILE* afterReveal, Dictionary* dictionary) {
    printf("---- Starting Creating dictionary-----\n");
    if (!afterReveal){
        printf("---- can not open the file-----\n");
        return -1;
    }
    else{
        printf("---- Could open the file-----\n");
    }
    printf("---- Inicitialization of variables-----\n");
    int nbBytesKey = 0;
    printf("Taking first byte\n");
    char c = getc(output);
    int numberElements = c; // First byte in a integer
    printf("Set number of elements in the dictionary:\n");
    setSize(dictionary, (numberElements+1));
    printf("Malloc the number of element in the dictionary:\n");
    dictionary->elements = malloc((numberElements)* sizeof(Character));

    for (int i = 0; i < getSize(dictionary); ++i) {
        printf("---- Creating the %d element in the dictionary-----\n", i+1);
        printf("Set value.");
        setValue(dictionary, i, getc(afterReveal)); //Set value of the caractere
        printf("Value of the key is %c as char and %d as integer\n", getValue(dictionary, i), getValue(dictionary, i));
        printf("Set size of the key.");
        setSizeOfKey(dictionary, i, getc(afterReveal)); // Set size of key
        printf("Size of the key is: %d\n", getSizeOfKey(dictionary, i));
        printf("Starting get the number of bytes of this key: -----");
        nbBytesKey = (getSizeOfKey(dictionary, i)/8)+1; //Get Number of bytes used to the key
        printf("The number byte of the key is %d\n", nbBytesKey);
        printf("Doing malloc in the char* key of this element\n");
        dictionary->elements->key = malloc(nbBytesKey*(sizeof(char)));// Malloc the number of bytes
        printf("Did the malloc\n");
        printf("----Start loop in the number of bytes-----\n");
        for (int j = 0; j < nbBytesKey; ++j) { //Loop to the number of bytes
            printf("---- Starting lopp in the %d byte-----\n", j+1);
            int qtdBits = (getSizeOfKey(dictionary, i));  // Ex = 3
            printf("The quantity of bits left is%d\n", qtdBits);
            int bitToSet = 0; //variable to take the bit from the byte
            while (nbBytesKey != 0){ //1
                printf("Taking byte to set in the dictionary.");
                c = getc(afterReveal); //took first byte
                printf("The byte took was %c as char and %d as integer\n", c, c);
                int k = 1; //inicial to take from the byte
                printf("K is %d \n", k);
                while(qtdBits!=0){ // 3
                    bitToSet = get_bit(c, k);
                    printf("The bit to set is %d, tooked from the byte in the position %d", bitToSet, k);
                    printf("Try to set in the dictionary\n");
                    setKey(dictionary, i, setBit((uchar)getKey(dictionary, i, 0),qtdBits-1, bitToSet), 0);
                    printf("Putted in the dictionary\n");
                    qtdBits--;
                    printf("The quantity of bits left is%d\n", qtdBits);
                    k++;
                    printf("K is %d \n", k);
                }
                nbBytesKey--;
            }
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

char* getKey(Dictionary* d, int index, int indexKey){
    return d->elements[index].key;
}

void setKey(Dictionary* d, int index, char keey, int indexKey){
    d->elements[index].key[indexKey] = keey;
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
            printf("%d", get_bit((uchar)getKey(&d,i, 0),(9-siz)));
        }
        printf("\n");
    }
}