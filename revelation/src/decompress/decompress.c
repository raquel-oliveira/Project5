//
// Created by Raquel Lopes de Oliveira on 19/01/2016.
//

#include "decompress.h"

int decompress(Dictionary* d, FILE* onlyMessage){ //put file in the assignature
    //Create output file
    FILE *outputFinal;
    outputFinal = fopen("messageDecode.txt", "w+");

    uchar lastByte = getc(onlyMessage); //Taking the first byte
    uchar currentByte = lastByte;
    lastByte = getc(onlyMessage); // Taking the second byte
    uchar buffer;
    int count = 0; // Count of number of bits used
    int aux = 1; // Auxiliar to take the bit of the byte
    int max = 8;
    bool end = false;
    bool isEOF = false;

    buffer = setBit(buffer, count, get_bit(currentByte, aux)); //First buffer setted
    count++; //As the first bit was setted, the count is 1 because use one bit of the byte

    //TODO: Don't go to the whole message. Look the size of the number of bits used in the last byte
    while(!end){
        for(int i = 0; i < getSize(d); i++) { // Make a loop in the dictionary
            if ((count) == getSizeOfKey(d, i)) { // Checking if the caracter has the same size of the buffer
                if(buffer == getKey(d, i)){ // If the key is the same of the buffer, write in the file
                    if (outputFinal!=NULL)
                    {
                        char bla = getValue(d, i);
                        fputs (&bla,outputFinal);
                    }
                    else{
                        fprintf(stderr, "Problem with the file?\n");
                        exit(-1);
                    }
                    count = 0;
                    buffer = 0;
                }
            }
        }
        if((int)lastByte == 255){ // change this to: feof(onlyMessage)
            max = getQtdBitsOfLastByte(d);
            if(feof(onlyMessage)){isEOF = true;}
        }

        if(aux == max){ // check if he try to set in a position not allowed
            aux = 0;
            currentByte = lastByte;
            lastByte = getc(onlyMessage); //taking new byte
            aux++;
            if(isEOF){
                if(aux < (max+1)){ //max or max+1?
                    printf("is end\n");
                    fclose(outputFinal);
                    end = true;

                    break; //This break its necessary?
                }
            }
        }
        else{
            aux++;
        }

        buffer = buffer << 1; //Decalage
        buffer = setBit(buffer, 0, get_bit(currentByte, aux)); // set the next element of the byte in the last bit of the buffer
        count++;

    }

    return 0;
}
