//
// Created by Raquel Lopes de Oliveira on 19/01/2016.
//

#include "reveal.h"

int reveal(int initialRow, int finalRow, int initialWidth, int finalWidth) {
    int lbit, channel, count = 7, i = 0, nbOccurences = 0, color;
    char letter = 1;
    char* end = NULL;
    int sizeMagic = strlen(magic);
    char* message = malloc(sizeMagic * sizeof(uchar));
    char* m;
    FILE * temp;
    output = fopen(fileOut, "w+");
    while(end == NULL)
    {
        if(nbOccurences == 0) color = firstChannel;
        else if(nbOccurences == 1 && secondChannel != -1) color = secondChannel;
        else if(nbOccurences == 2 && thirdChannel != -1) color = thirdChannel;
        else {
            fclose(output);
            return -3; // magic Number not found
        }

        for (int row = initialRow; row < finalRow; row++) {
            for (int col = initialWidth; col < finalWidth; col++) {
                channel = cvGet2D(img, row, col).val[color]; // Gets the red channel

                lbit = get_bit(channel, (9 - nbBits)); // Access to the last bit in ascending order
                if (lbit == -1) {
                    fclose(output);
                    return -2;
                }
                letter = setBit(letter, count, lbit);
                count--;

                if (count < 0) {
                    count = 7;
                    message[i] = letter;
                    i++;
                    if(i > sizeMagic-1){
                        //TODO: It's jumping fot multiples of size of magicNumber. Change this!!!!!!!
                        i = 0;

                        m = message
                        end = strstr(m, magic); // Check if magic number is found --> when the message ends

                        if (end != NULL) { //Magic Number was found
                            *end = '\0';
                            fclose(output);
                            return 0;
                        }

                        if (output!=NULL)
                        {
                            fputs (message,output);
                        }
                    }

                }

            }
        }
        nbOccurences++;
    }
    return 1;
}