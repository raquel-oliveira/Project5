//
// Created by Raquel Lopes de Oliveira on 19/01/2016.
//

#include "decompress.h"

int decompress(char* pathFile, Dictionary *d){ //put file in the assignature
    FILE* afterReveal = fopen(pathFile, "r");
    //printf("---- Starting create dictionary-----\n");
    int flagDictionary = createDictionary(afterReveal, d);
    if (flagDictionary < 0 ){
        //fprintf(stderr, "Dictionary not created or Could not open the file \n");
        return flagDictionary;
        //exit(EXIT_FAILURE);
    }
    //printf("---- Starting to decompres-----\n");
    //Create output file
    FILE *outputFinal;
    //printf("Create file %s\n", fileOut);
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
   // printf("Count is %d \n", count);
    int aux = 1; // Auxiliar to take the bit of the byte (postition)
   // printf("aux is %d \n", aux);
    int max = 8; //default max of a byte
    //printf("Max qtd bits is %d \n", max);

    //printf("Get max bytes: %d\n", getMaxByte(d));
    uchar* buffer = malloc(getMaxByte(d)* (sizeof(uchar))); //Buffer to check with the keys in the dictionary
    //printf("made the malloc to the buffer\n");
    if(buffer==NULL){
        printf("problem in malloc??\n");
    }
    int pos = 0; // Variable to say in what position of the buffer it is.
    //Iniciatialization of buffer
    buffer[pos] = setBit(buffer[pos], count, get_bit(currentByte, aux)); //First buffer setted
    //printf("The buffer in position %d is: %d\n", pos, buffer[pos]);
    count++; //As the first bit was setted, the count is 1 because use one bit of the byte
    //printf("Count is %d \n", count);

    //printf("\n\n\n");

    while(!end){
      //  printf("\n\n\n\n\n\n OLAR aux: %d  count: %d qtd char used %d\n", aux, count, pos+1);
        for(int i = 0; i < getSize(d); i++) { // Make a loop in the dictionary
            //printf("\n\n Loop %d in the dictionary\n", i+1);
            if ((count) == getSizeOfKey(d, i)) { // Checking if the caracter has the same size of the buffer
        //        printf("Has the same size %d \n", count);
                //if(buffer == (int)getKey(d, i)[0]){ // If the key is the same of the buffer, write in the file
          //      printf("buffer is: %d\n", buffer[pos]);
                if(memcmp(buffer, getKey(d,i), getMaxByte(d))==0){
                  //  printf("Buffer is %d and the key is %d . It's saying its the same\n", buffer[pos], getKey(d,i));
                //if((int)buffer == (int)getKey(d,i)){
            //        printf("same value\n");
                    if (outputFinal!=NULL)
                    {
                        /*char caract = getValue(d, i);
                        fputs (&caract,outputFinal); //TODO: THE PROBLEM IS HERE*/
                        int caract = getValue(d, i);
                        putc (caract,outputFinal);
                        //fputs(getValue(d, i),outputFinal);
                      //  printf("Put in the file the caracter %c \n", caract);
                        //fclose(outputFinal);
                    }
                    else{
              //          fprintf(stderr, "Probl em with the file?\n");
                        exit(-1);
                    }
                    count = 0;
                    //buffer = 0;
                    memset(buffer, 0, getMaxByte(d));
                    pos = 0;
                }
                else{
                //    printf("Not the same value");
                }
            }
            else{
             //   printf("Its not the same size because %d its different of the siz of this key %d\n", count, getSizeOfKey(d,i));
            }
        }
        if(feof(afterReveal)){
            max = getQtdBitsOfLastByte(d);
          //  printf("The max final is %d\n", max);
            isEOF = true;
        }
        else{
           // printf("Not end of file \n");
        }
        if(count>0){
            //printf("Count>0\n");
            if(count%8==0){
              //  printf("Pos = %d", pos);
                //printf("Multiplo \n");
                pos++;
                //printf("Pos = %d", pos);

            }
        }


        if(aux == max){ // check if he try to set in a position not allowed (two cases: or it already thought to the whole byte or want to acess the bit not allowed in the last byte)
          //  printf("The aux %d is the same as the max %d \n", aux, max);
            /*aux = 0; //
            printf("After default, aux is: %d \n", aux);*/
            //pos++; //go to next char*
           //printf("pos == %d\n", pos);
            currentByte = lastByte; //Update currentByte
            lastByte = getc(afterReveal); //taking new byte
            //aux++; //TODO: change the aux=0;aux++; TO aux=1; ?
            aux = 1; //
           // printf("After default, aux is: %d \n", aux);
            if(isEOF){
             //   printf("Is end of file\n");
                if(aux < (max+1)){ //max or max+1? TODO: Use test to check. Exemple: QtdOfLastByte = 1;
                    //fclose(outputFinal);
                    //fclose(afterReveal);
                    end = true;
                    break; //This break its necessary?
                }
            }
        }
        else{
         //   printf("Aux ainda nao ta no max\n");
            aux++;
            //printf("Aux is %d \n", aux);
        }
        //printf("a The max is %d and the aux is %d\n", max, aux);

        buffer[pos] = buffer[pos] << 1; //Decalage to set the new last bit
        //printf("decalage The buffer in position %d is: %d\n", pos, buffer[pos]);
        buffer[pos] = setBit(buffer[pos], 0, get_bit(currentByte, aux)); // set the next element of the byte in the last bit of the buffer
       // printf("set .The buffer in position %d is: %d after put %d in the last position \n", pos, buffer[pos], get_bit(currentByte, aux));
        count++;
        //printf("Count is %d \n", count);


    }
    if(isStandard){
        fputc(EOF,outputFinal);
        fclose(outputFinal);
    }

    return 0;
}
