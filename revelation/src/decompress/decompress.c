//
// Created by Raquel Lopes de Oliveira on 19/01/2016.
//

#include "decompress.h"

int decompress(Dictionary* d, FILE* onlyMessage){ //put file in the assignature
    //Create output file
    FILE *outputFinal;
    outputFinal = fopen("messageDecode.txt", "w+");

    uchar lastByte = getc(onlyMessage); //Taking the first byte
    uchar currentByte = lastByte; //Uodate the current byte to the first one
    lastByte = getc(onlyMessage); // Taking the second byte
    uchar buffer; //Buffer to check with the keys in the dictionary
    int count = 0; // Count of number of bits used in the buffer
    int aux = 1; // Auxiliar to take the bit of the byte (postition)
    int max = 8; //default max of a byte
    bool end = false; //If I should stop the loop
    bool isEOF = false; //If its end of file

    //Iniciatialization of buffer
    buffer = setBit(buffer, count, get_bit(currentByte, aux)); //First buffer setted
    count++; //As the first bit was setted, the count is 1 because use one bit of the byte

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
        if(feof(onlyMessage)){
            max = getQtdBitsOfLastByte(d);
            isEOF = true;
        }

        if(aux == max){ // check if he try to set in a position not allowed (two cases: or it already thought to the whole byte or want to acess the bit not allowed in the last byte)
            aux = 0; //
            currentByte = lastByte; //Update currentByte
            lastByte = getc(onlyMessage); //taking new byte
            aux++; //TODO: change the aux=0;aux++; TO aux=1; ?
            if(isEOF){
                if(aux < (max+1)){ //max or max+1? TODO: Use test to check. Exemple: QtdOfLastByte = 1;
                    fclose(outputFinal);
                    end = true;
                    break; //This break its necessary?
                }
            }
        }
        else{
            aux++;
        }

        buffer = buffer << 1; //Decalage to set the new last bit
        buffer = setBit(buffer, 0, get_bit(currentByte, aux)); // set the next element of the byte in the last bit of the buffer
        count++;

    }

    return 0;
}
