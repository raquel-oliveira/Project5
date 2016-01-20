//
// Created by Raquel Lopes de Oliveira on 19/01/2016.
//

#include "decompress.h"

int decompress(Dictionary* d, FILE* onlyMessage){ //put file in the assignature
    //Create output file
    FILE *outputFinal;
    outputFinal = fopen("messageDecode.txt", "w+");

    uchar byteM = getc(onlyMessage); //Taking the first byte
    uchar buffer;
    int count = 0; // Count of number of bits used
    int aux =1; // Auxiliar to take the bit of the byte

    buffer = setBit(buffer, count, get_bit(byteM, aux)); //First buffer setted
    count++; //As the firt bit was setted, the count is 1 because use one bit of the byte

    //TODO: Don't go to the whole message. Look the size of the number of bits used in the last byte
    while(!feof(onlyMessage)){
        for(int i = 0; i < getSize(d); i++) { // Make a loop in the dictionary
            if ((count) == getSizeOfKey(d, i)) { // Checking if the caracter has the same size of the buffer
                if(buffer == getKey(d, i)){ // If the key is the same of the buffer, write in the file
                    if (outputFinal!=NULL)
                    {
                        char bla = getValue(d, i);
                        fputs (&bla,outputFinal);
                    }
                    count = 0;
                    buffer = 0;
                }
            }
        }

        if(aux == 8){ // if he setted the 8th element of the actual byte he will took a new byte
            aux = 0;
            byteM = getc(onlyMessage);
        }
        buffer = buffer << 1; //Decalage
        aux++;
        buffer = setBit(buffer, 0, get_bit(byteM, aux)); // set the next element of the byte in the last bit of the buffer
        count++;
    }
    //TODO: Delete the variable file OnlyMessage
    return 0;

}
