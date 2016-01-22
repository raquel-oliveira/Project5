//
// Created by Raquel Lopes de Oliveira on 19/01/2016.
//

#include "decompress.h"

int decompress(FILE* afterReveal, char* fileOut, Dictionary *d){ //put file in the assignature
    printf("---- Starting create dictionary-----\n");
    int flagDictionary = createDictionary(afterReveal, d);
    if (flagDictionary < 0 ){
        fprintf(stderr, "Dictionary not created or Could not open the file \n");
        return flagDictionary;
        //exit(EXIT_FAILURE);
    }
    printf("---- Starting to decompres-----\n");
    //Create output file
    FILE *outputFinal;
    printf("Create file\n");
    outputFinal = fopen(fileOut, "w+");

    uchar lastByte = getc(afterReveal); //Taking the first byte
    uchar currentByte = lastByte; //Update the current byte to the first one
    lastByte = getc(afterReveal); // Taking the second byte

    uchar buffer = 0; //Buffer to check with the keys in the dictionary
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
                if(buffer == (int)getKey(d, i)[0]){ // If the key is the same of the buffer, write in the file
                    if (outputFinal!=NULL)
                    {
                        char caract = getValue(d, i);
                        fputs (&caract,outputFinal);
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
        if(feof(afterReveal)){
            max = getQtdBitsOfLastByte(d);
            isEOF = true;
        }

        if(aux == max){ // check if he try to set in a position not allowed (two cases: or it already thought to the whole byte or want to acess the bit not allowed in the last byte)
            aux = 0; //
            currentByte = lastByte; //Update currentByte
            lastByte = getc(afterReveal); //taking new byte
            aux++; //TODO: change the aux=0;aux++; TO aux=1; ?
            if(isEOF){
                if(aux < (max+1)){ //max or max+1? TODO: Use test to check. Exemple: QtdOfLastByte = 1;
                    fclose(outputFinal);
                    fclose(afterReveal);
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
