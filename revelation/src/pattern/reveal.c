#include "reveal.h"

#define SIZE_MESSAGE 100


int reveal(int initialRow, int finalRow, int initialWidth, int finalWidth){
    int lbit, channel, count = 7, i = 0, nbOccurences = 0, color;
    uchar letter = 1;
    char* end = NULL;
    int size = SIZE_MESSAGE; // Size of the allocated memory for message
    int sizeMagic = strlen(magic);
    char* message = malloc(SIZE_MESSAGE * sizeof(char));
    if(!isCompress){
        output = fopen(fileOut, "w+");
    }
    else{
        output = fopen("afterReveal.txt", "w=");
    }

    while(end == NULL)
    {
        if(nbOccurences == 0) color = firstChannel;
        else if(nbOccurences == 1 && secondChannel != -1) color = secondChannel;
        else if(nbOccurences == 2 && thirdChannel != -1) color = thirdChannel;
        else {
            fclose(output);
            return -3;
        }

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
                    if (i >= size - 1) // Reallocating when the text become larger than message
                    {
                        size *=1.5;
                        message = realloc(message, size);
                        if (message == NULL) return -1; // The reallocation went wrong --> return an error code
                    }
                    count = 7;
                    message[i] = letter;
                    i++;

                }

                end = strstr((char*)message, magic); // Check when "HELP" is found --> when the message ends

                if (end != NULL) { //Help was found
                    *end = '\0';
                    fputs (message,output); //or fputc, depend.
                    fclose(output);
                    return 0;
                }
            }
        }
        nbOccurences++;
    }
}