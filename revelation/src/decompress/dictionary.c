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
    uchar c = getc(output);
    uchar zero = 0;
    int numberElements = c + 1; // First byte in a integer
    printf("Set number of elements in the dictionary: ");
    setSize(dictionary, (numberElements));
    printf("%d \n", getSize(dictionary));
    printf("Malloc the number of element in the dictionary: %d\n", numberElements);
    dictionary->elements = malloc((numberElements)* sizeof(Character));
    int qtdBits;
    for (int i = 0; i < getSize(dictionary); i++) {
        qtdBits = 0;
        printf("--------------- Creating the %d element in the dictionary----------------\n", i+1);
       // printf("Set value.");
        setValue(dictionary, i, getc(afterReveal)); //Set value of the caractere
       // printf("Value of the key is %c as char and %d as integer\n", getValue(dictionary, i), getValue(dictionary, i));
        //printf("Set size of the key.");
        setSizeOfKey(dictionary, i, getc(afterReveal)); // Set size of key
        printf("Size of the key is: %d\n", getSizeOfKey(dictionary, i));
        //printf("Starting get the number of bytes of this key: -----");
        int sizeofk=getSizeOfKey(dictionary, i);
        nbBytesKey = (sizeofk/8)+((sizeofk%8==0)?0:1); //Get Number of bytes used to the key
        //printf("The number byte of the key is %d\n", nbBytesKey);
        //printf("Doing malloc in the char* key of this element\n");
        (dictionary->elements)[i].key = malloc(nbBytesKey*(sizeof(char)));// Malloc the number of bytes
        if(dictionary->elements->key == NULL){
            printf("ERRO NO MALLOC\n");
        }
        else printf("Did the malloc\n");
        printf("----Start loop for %d times ( number of bytes)-----\n", nbBytesKey);

        for (int j = 0; j < nbBytesKey; j++) { //Loop to the number of bytes
          //  printf("---- Starting lopp in the %d byte-----\n", j+1);
            qtdBits = (getSizeOfKey(dictionary, i));  // Ex = 3
           // printf("The quantity of bits left is%d\n", qtdBits);
            int bitToSet = 0; //variable to take the bit from the byte
            printf("%d", nbBytesKey);
            uchar aux = 0;
            while (nbBytesKey != 0){ //1

            //    printf("Taking byte to set in the dictionary.");
                c = getc(afterReveal); //took first byte
            //    printf("The byte took was %c as char and %d as integer\n", c, c);
                int k = 1; //inicial to take from the byte
            //    printf("K is %d \n", k);
                while(qtdBits!=0){ // 3
                    bitToSet = get_bit(c, k);
            //        printf("The bit to set is %d, tooked from the byte in the position %d\n", bitToSet, k);
            //        printf("Try to set in the dictionary\n");
            //        printf("element in the dictionary i = %d,\n Set the bit = %d, in the position %d,",i, bitToSet, qtdBits-1);
            //        printf("Create AUX:.");
                    aux = setBit(aux, qtdBits-1, bitToSet);
            //        printf("Aux = %d as int or %c as char \n", aux, aux);
            //        printf("Putted in the dictionary\n");
                    qtdBits--;
            //        printf("aaaa The quantity of bits left is%d\n", qtdBits);
                    k++;
            //        printf("K is %d \n", k);
                }
                /*printf("setei");
                printf("de verdade %s \n", getKey(dictionary,i,0));*/
                printf("Botando o valor na estrutura %d\n",aux);
                (dictionary->elements)[i].key[j] = aux; //TODO: problema para acessar o elemento
                printf(" AAAAAAAAAAAAA %d\n", (dictionary->elements)[i].key[j] );

                //setKey(*dictionary, i, aux, 0);
                printf("botei\n");
                nbBytesKey--;
                printf("Final number of key is %d \n", nbBytesKey);
            }
        }
        printf("fim\n");
    }
    setQtdOfLastByte(dictionary, getc(output));
    printf("%d\n", getQtdBitsOfLastByte(dictionary));


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

void setKey(Dictionary d, int index, uchar keey, int indexKey){
    d.elements[index].key[indexKey] = keey;
}

int getSizeOfKey(Dictionary* d, int index){
    return d->elements[index].sizeOfKey;
}

void setSizeOfKey(Dictionary* d, int index, int size){
    d->elements[index].sizeOfKey = size;
}

void printDictionary(Dictionary* d){
    for (int i = 0; i < getSize(d); ++i) {
        printf("0x%x : ", getValue(d, i));
        int oo =getSizeOfKey(d, i);
       /* for(int j = 1; j < 9; j++){
            printf("%d", get_bit((uchar)getKey(&d,i, 0),j));
        }*/
        printf("EEEEEE %d:%d", oo,getKey(d,i)[0]);

        printf("\n");
    }
}