//
// Created by Raquel Lopes de Oliveira on 19/01/2016.
//

#include "direct.h"

#define SIZE_MESSAGE 100
#define RED 2
#define GREEN 1
#define BLUE 0


int revealDirect(IplImage *img, int nbBits, char *magic, int firstColor, int secondColor, int thirdColor)
{
    int lbit, channel, count = 7, i = 0, nbOccurences = 0, color;
    char letter = 1;
    char* end = NULL;
    int sizeMagic = strlen(magic);
    char* message = malloc(sizeMagic * sizeof(uchar));

    output = fopen(fileOut, "w+");
    while(end == NULL)
    {
        if(nbOccurences == 0) color = firstColor;
        else if(nbOccurences == 1 && secondColor != -1) color = secondColor;
        else if(nbOccurences == 2 && thirdColor != -1) color = thirdColor;
        else return -3;

        for (int row = 0; row < img->height; row++) {
            for (int col = 0; col < img->width; col++) {
                channel = cvGet2D(img, row, col).val[color]; // Gets the red channel

                lbit = get_bit(channel, (9 - nbBits)); // Access to the last bit in ascending order
                if (lbit == -1) {
                    return -2;
                }
                letter = setBit(letter, count, lbit);
                count--;

                if (count < 0) {
                    count = 7;
                    message[i] = letter;
                    i++;
                    if(i > sizeMagic-1){
                        i = 0;

                        end = strstr(message, magic); // Check if magic number is found --> when the message ends

                        if (end != NULL) { //Magic Number was found
                            *end = '\0';
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
        fclose (output);
    }
    //TODO: Make condition to distroy file if the magic number wasn't found
    return -1;
}