//
// Created by Raquel Lopes de Oliveira on 19/01/2016.
//

#include "decompress.h"

int decompress(Dictionary* d, FILE* onlymessage){ //put file in the assignature

    printf("Inicial decompress\n");
    FILE *outputFinal;
    outputFinal = fopen("realfinal.txt", "w+");
    if (!onlymessage){ //to test
        printf("No message to decode \n");
        return -1; //to test
        //exit(EXIT_FAILURE);
    }
    else{
        char c = getc(onlymessage);
        printf("The first byte tooken was: %c\n", c);
        printf("The first byte tooken was: %d\n", c);

        c = getc(onlymessage);
        printf("The Second byte tooken was: %c\n", c);
        printf("The Second byte tooken was: %d\n", c);

        int contador = 0;
        printf("First bit is %d\n", get_bit(c, 1));
        char toCheck = setBit(toCheck, 7, get_bit(c, 1));
        contador++;


        toCheck = setBit(toCheck, 6, get_bit(c, 2));
        contador++;
        printf("Second bit is %d\n", get_bit(c, 2));

        toCheck = setBit(toCheck, 5, get_bit(c, 3));
        contador++;
        printf("Third bit is %d\n", get_bit(c, 3));

        toCheck = setBit(toCheck, 4, get_bit(c, 4));
        contador++;
        printf("4th bit is %d\n", get_bit(c, 4));

        toCheck = setBit(toCheck, 3, get_bit(c, 5));
        contador++;
        printf("5th bit is %d\n", get_bit(c, 5));

        toCheck = setBit(toCheck, 2, get_bit(c, 6));
        contador++;
        printf("6th bit is %d\n", get_bit(c, 6));

        toCheck = setBit(toCheck, 1, get_bit(c, 7));
        contador++;
        printf("7h bit is %d\n", get_bit(c, 7));

        toCheck = setBit(toCheck,0 , get_bit(c, 8));
        contador++;
        printf("8th bit is %d\n", get_bit(c, 8));

        printf("toCheck is: %c\n", toCheck);
        for(int i = 0; i < getSize(d); i++){
            printf("----- Loop for %c \n", getValue(d, i));
            if(contador == getSizeOfKey(d, i)){
                printf("Same size \n");
                char aa = getKey(d, i);
                if(strcmp(&toCheck, &aa)){
                    printf("Equal with %c\n", getValue(d, i));
                    if (outputFinal!=NULL)
                    {
                        char bla = getValue(d, i);
                        fputs (&bla,outputFinal);
                    }
                }
                else{
                    printf("Nor equal\n");
                }
            }
            else{
                printf("Not the same size\n");
            }
        }

    }
}
