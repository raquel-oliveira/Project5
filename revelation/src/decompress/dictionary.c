//
// Created by Raquel Lopes de Oliveira on 18/01/2016.
//

#include "dictionary.h"

int createDictionary(FILE* afterReveal, Dictionary* dictionary) {
    printf("aaaa\n");
    if (!afterReveal) /*printf("---- can not open the file-----\n"); */return -1;

    int qtdBits;
    int qtdBitsLeft;
    printf("a\n");
    uchar c = getc(output); //Taking the first byte
    printf("b\n");
    int numberElements = c + 1; // First byte in a integer
    printf("Number of elements : %d\n", numberElements);
    setSize(dictionary, (numberElements));
    dictionary->maxByte = 1;
    dictionary->elements = malloc((numberElements)* sizeof(Character)); //Malloc to the number necessaries of elements

    for (int i = 0; i < getSize(dictionary); i++) {

        setValue(dictionary, i, getc(afterReveal)); //Set value of the caractere

        setSizeOfKey(dictionary, i, getc(afterReveal)); // Set size of key
        int sizeOfKey = getSizeOfKey(dictionary, i); //Variable auxiliar to number of bits used in the key

        setQtdByte(dictionary,i, (sizeOfKey/8)+((sizeOfKey%8==0)?0:1)); // Set the numbers of bytes takin into account the number of bits
        int nbBytesKey = getQtdByte(dictionary, i); //Variable auxiliar no number of bytes
        if(nbBytesKey > (dictionary->maxByte)) dictionary->maxByte = nbBytesKey;

        //printf("0x%x : ", getValue(dictionary, i));
        //printf("--------Qtd bytes: %d\n", nbBytesKey);
        (dictionary->elements)[i].key = malloc(nbBytesKey*(sizeof(uchar)));// Malloc the number of bytes needed
        if(dictionary->elements[i].key == NULL) /*printf("ERRO NO MALLOC\n");*/ return -2;

        qtdBits = (getSizeOfKey(dictionary, i));
        //printf("Qtd bits: %d\n", qtdBits);
        qtdBitsLeft = qtdBits;
        int f = 0;
        while (nbBytesKey != 0){
         //   printf("Qtd bytes in the ? loop %d.\n", getQtdByte(dictionary, i));
            if(nbBytesKey > 1) {
           //     printf("Nb maior que 1\n");
                qtdBitsLeft = qtdBits - 8;
                qtdBits = 8;
             //   printf("Qtd bits using now %d in the ? loop, qtd of bits left: %d.\n", qtdBits, qtdBitsLeft);
            }
            else{
                qtdBits = qtdBitsLeft;
            }

            int bitToSet = 0; //variable to take the bit from the byte
            uchar aux = 0;
            c = getc(afterReveal); //took first byte

            int k = 1; //inicial to take from the byte

            while(qtdBits!=0){ //While inside of the x byte of the key
                bitToSet = get_bit(c, k);
                aux = setBit(aux, qtdBits-1, bitToSet);
                qtdBits--;
                k++;
            }

            setKey(dictionary,i, aux,f);
            //printf("set key %d in the byte %d\n",getKey(dictionary, i)[f], f+1);
            nbBytesKey--;
            f++;
            //printf("%d\n", getKey(dictionary,i)[f]);

        }
        //printf("\n\n");
    }
    setQtdOfLastByte(dictionary, getc(output));

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

