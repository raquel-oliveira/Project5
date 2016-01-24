//
// Created by Raquel Lopes de Oliveira on 19/01/2016.
//

#include "decompress.h"
/**
 * The decompress start trying to create a dictionary
 * @return 0 if the decompression was made
 *
 */
int decompress(char* pathFile, Dictionary *d){

    FILE* afterReveal = fopen(pathFile, "r");

    int flagDictionary = createDictionary(afterReveal, d);
    if (flagDictionary < 0 ){
        //fprintf(stderr, "Dictionary not created or Could not open the file \n");
        return flagDictionary;
    }

    //Create output file
    FILE *outputFinal;
    if(isStandard){
        outputFinal = fopen("output.txt", "w+");
    }
    else{
        outputFinal = fopen(fileOut, "w+");
    }


    bool end = false; //If I should stop the loop
    bool isEOF = false; //If its end of file
    uchar lastByte = getc(afterReveal); //Taking the first byte
    //printf("first byte is %d \n", lastByte);
    uchar currentByte = lastByte; //Update the current byte to the first one
    lastByte = getc(afterReveal); // Taking the second byte

    int count = 0; // Count of number of bits used in the buffer
    int aux = 1; // Auxiliar to take the bit of the byte (postition)
    int max = 8; //default max of a byte

    uchar* buffer = malloc(getMaxByte(d)* (sizeof(uchar))); //Buffer to check with the keys in the dictionary

    if(buffer == NULL){
        return -6; //printf(stderr, "Problem when try to malloc the buffer\n");
    }
    int pos = 0; // Variable to say in what position of the buffer it is.

    buffer[pos] = setBit(buffer[pos], count, get_bit(currentByte, aux)); //First buffer setted
    count++; //As the first bit was setted, the count is 1 because use one bit of the byte

    while(!end){
        for(int i = 0; i < getSize(d); i++) { // Make a loop in the dictionary
            if ((count) == getSizeOfKey(d, i)) { // Checking if the caracter has the same size of the buffer
                if(memcmp(buffer, getKey(d,i), getMaxByte(d))==0){ // If the key is the same of the buffer, write in the file
                    if (outputFinal!=NULL)
                    {
                        int caract = getValue(d, i);
                        putc (caract,outputFinal);
                    }
                    else{
                        return  -1;
                    }
                    count = 0;
                    memset(buffer, 0, getMaxByte(d));
                    pos = 0;
                }
            }
        }
        if(feof(afterReveal)){
            max = getNbBitsOfLastByte(d);
            isEOF = true;
        }
        if(count>0){
            if(count%8==0){
                pos++;
            }
        }


        if(aux == max){ // check if he try to set in a position not allowed (two cases: or it already thought to the whole byte or want to acess the bit not allowed in the last byte)
            currentByte = lastByte; //Update currentByte
            lastByte = getc(afterReveal); //taking new byte
            aux = 1; //
            if(isEOF){
                if(aux < (max+1)){ //max or max+1? TODO: Use test to check. Exemple: QtdOfLastByte = 1;
                    //fclose(outputFinal);
                    //fclose(afterReveal);
                    end = true;
                    break;
                }
            }
        }
        else{
            aux++;
        }

        buffer[pos] = buffer[pos] << 1; //Shift to set the new last bit
        buffer[pos] = setBit(buffer[pos], 0, get_bit(currentByte, aux)); // set the next element of the byte in the last bit of the buffer
        count++;


    }
    if(isStandard){
        fputc(EOF,outputFinal);
        fclose(outputFinal);
    }

    return 0;
}
