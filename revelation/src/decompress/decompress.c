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
    int aux =1; // Auxiliar to take the bit of the byte
    int max = 8;
    bool end = false;
    bool isEOF = false;

    buffer = setBit(buffer, count, get_bit(currentByte, aux)); //First buffer setted
    count++; //As the first bit was setted, the count is 1 because use one bit of the byte

    //TODO: Don't go to the whole message. Look the size of the number of bits used in the last byte
    while(!end){
        for(int i = 0; i < getSize(d); i++) { // Make a loop in the dictionary
           // printf("----------Loop in the dictionary value %d withe the buffer %d-------\n", getKey(d, i), buffer);
          //  printf("count is: %d\n", count);
            if ((count) == getSizeOfKey(d, i)) { // Checking if the caracter has the same size of the buffer
           //     printf("Has the same size\n");
                if(buffer == getKey(d, i)){ // If the key is the same of the buffer, write in the file
               //     printf("Its equal\n");
                    if (outputFinal!=NULL)
                    {
                        char bla = getValue(d, i);
                        fputs (&bla,outputFinal);
                        printf("----------------------Wrote the %d\n", buffer);
                    }
                    else{
                        printf("Problem with the file?\n");
                    }
                    count = 0;
                    buffer = 0;
                }
            }
        }
        printf("current byte is%d\n", currentByte);
        printf("Last byte is%d\n", lastByte);
        if((int)lastByte == 255){
            max = getQtdBitsOfLastByte(d);
            printf("MAAAX is%d and aux is %d\n", max, aux);
            if(feof(onlyMessage)){isEOF = true;}
        }
        else{
           // printf("Max is%d and aux is %d\n", max, aux);
            max = 8;
        }
        // printf("Not last byte, Last byte is: %d\n", lastByte);
        if(aux == max){ // if he setted the 8th element of the actual byte he will took a new byte
            printf("Max %d is equal aux %d\n", max, aux);
            aux = 0;
            currentByte = lastByte;
            printf("current byte is %d\n", currentByte);
            lastByte = getc(onlyMessage);
            aux++;
            // printf("take new byte %d in the lopp %d\n", lastByte, porra);
            //porra++;
            printf("Not last byte, Last byte is: %d\n", lastByte);
            if(isEOF){
                if(aux < max){
                    printf("is end\n");
                    fclose(outputFinal);
                    end = true;
                    break;
                }
            }
        }
        else{
            printf("Max %d is not equal aux %d", max, aux);
            aux++;
        }

        //aux++;
        printf("The aux is:  %d\n", aux);
        buffer = buffer << 1; //Decalage
        buffer = setBit(buffer, 0, get_bit(currentByte, aux)); // set the next element of the byte in the last bit of the buffer
        count++;
        printf("GO TRY with buffer: %d\n", buffer);
       // if ((feof(onlyMessage)) && (aux==2)){end= true;}

    }
   // while(!feof(onlyMessage));


    //TODO: Delete the variable file OnlyMessage
    return 0;
}
