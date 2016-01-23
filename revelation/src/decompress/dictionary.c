//
// Created by Raquel Lopes de Oliveira on 18/01/2016.
//

#include "dictionary.h"

int createDictionary(FILE* afterReveal, Dictionary* dictionary) {
    if (!afterReveal) return -1;


    //Inicializing variables
    int nbBits;
    int nbBitsLeft;
    dictionary->maxByte = 1;

    uchar c = getc(output); //Taking the first byte
    int numberElements = c + 1; // First byte in a integer
    setSize(dictionary, (numberElements));
    if(numberElements < 0 && numberElements > 256) return -5;

    dictionary->elements = malloc((numberElements)* sizeof(Character)); //Malloc to the number necessaries of elements

    for (int i = 0; i < getSize(dictionary); i++) {

        setValue(dictionary, i, getc(afterReveal)); //Set value of the caractere

        setSizeOfKey(dictionary, i, getc(afterReveal)); // Set size of key
        int sizeOfKey = getSizeOfKey(dictionary, i); //Variable auxiliar to number of bits used in the key

        setQtdByte(dictionary,i, (sizeOfKey/8)+((sizeOfKey%8==0)?0:1)); // Set the numbers of bytes takin into account the number of bits
        int nbBytesKey = getQtdByte(dictionary, i); //Variable auxiliar no number of bytes
        if(nbBytesKey > (dictionary->maxByte)) dictionary->maxByte = nbBytesKey;

        (dictionary->elements)[i].key = malloc(nbBytesKey*(sizeof(uchar)));// Malloc the number of bytes needed to the key
        if(dictionary->elements[i].key == NULL) return -2;

        nbBits = (getSizeOfKey(dictionary, i));
        nbBitsLeft = nbBits; //Inicializing the number of bits left.

        int posKeyByte = 0; //Position (byte) of the key
        while (nbBytesKey != 0){ //Loop to the complete quantity of bytes needed of the key

            if(nbBytesKey > 1) { //If its >1, that means the key of this element uses more than one byte
                nbBitsLeft = nbBits - 8;
                nbBits = 8;
            }
            else nbBits = nbBitsLeft;

            int bitToSet = 0; //variable to take the bit from the byte
            uchar aux = 0; //Varible auxiliar to fill the byte before insert in the Key
            c = getc(afterReveal); //took first byte

            int k = 1; //inicial to take from the byte

            while(nbBits != 0){ //While inside of the x byte of the key
                bitToSet = get_bit(c, k);
                aux = setBit(aux, nbBits - 1, bitToSet);
                nbBits--;
                k++;
            }

            setKey(dictionary, i, aux, posKeyByte); //Set the byte in the key.
            nbBytesKey--;
            posKeyByte++;
        }
    }
    setQtdOfLastByte(dictionary, getc(output));
    int nbBitsLastByte = getQtdBitsOfLastByte(dictionary);
    if(nbBitsLastByte > 8 && nbBitsLastByte <0 ){
        return -4;
    }

    return 0;

}

char getSize(Dictionary* d){
    return d->size;
}

void setSize(Dictionary* d, uchar sizee){
    d->size = sizee;
}

int getQtdBitsOfLastByte(Dictionary* d){
    return d->valueLastByte;
}

void setQtdOfLastByte(Dictionary* d, int qtd){
    d->valueLastByte = qtd;
}
uchar getValue(Dictionary* d, int index){
    return d->elements[index].value;
}

void setValue(Dictionary* d, int index, char valuee){
    d->elements[index].value = valuee;
}

uchar* getKey(Dictionary* d, int index){
    return (d->elements[index].key);
}

void setKey(Dictionary* d, int index, uchar keey, int indexKey){
    d->elements[index].key[indexKey] = keey;
}

int getSizeOfKey(Dictionary* d, int index){
    return d->elements[index].sizeOfKey;
}

void setSizeOfKey(Dictionary* d, int index, int size){
    d->elements[index].sizeOfKey = size;
}

int getQtdByte(Dictionary* d, int index){
    return d->elements[index].nbBytesKey;
}

void setQtdByte(Dictionary* d, int index, int qtd){
    d->elements[index].nbBytesKey = qtd;
}

int getMaxByte(Dictionary* d){
    return  d->maxByte;
}

void printDictionary(Dictionary* d){
    for (int i = 0; i < getSize(d); i++) {
        printf("0x%x : ", getValue(d, i));
        int nbBytesKey = getQtdByte(d, i);
        int qtdBits = getSizeOfKey(d,i); int qtdBitsLeft = getSizeOfKey(d,i);
            for (int k = 0; k < nbBytesKey; k++) {
                if(k != nbBytesKey-1){
                    qtdBitsLeft = qtdBits - 8; qtdBits = 8;
                }
                else  qtdBits = qtdBitsLeft;

                for (int j = qtdBits; j > 0; j--) {
                    printf("%d", get_bit((char) getKey(d, i)[k], (9 - j)));
                }
            }
        printf("\n");

    }

}

