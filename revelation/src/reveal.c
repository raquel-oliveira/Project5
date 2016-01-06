#include "reveal.h"

#define SIZE_MESSAGE 100
#define RED 2
#define GREEN 1
#define BLUE 0



int reveal(IplImage *img, int nbBits, char *help, uchar *message)
{
    int lbit, channel, count = 7, i = 0;
    uchar letter = 1;
    char* end = NULL;
    int size = SIZE_MESSAGE; // Size of the allocated memory for message

    for (int row = 0; row < img->height; row++) {
        for (int col = 0; col < img->width; col++) {
            channel = cvGet2D(img, row, col).val[2]; // Gets the red channel

            lbit = get_bit(channel, (9 - nbBits)); // Access to the last bit in ascending order
            if (lbit == -1) {
                return -2;
            }
            letter = setBit(letter, count, lbit);
            count--;

            if (count < 0) {
                if (i >= size - 1) // Reallocating when the text become larger than message
                {
                    size += SIZE_MESSAGE;
                    message = realloc(message, size);
                    if (message == NULL) return -1; // The reallocation went wrong --> return an error code
                }
                count = 7;
                message[i] = letter;
                i++;

            }

            end = strstr((char*)message, help); // Check when "HELP" is found --> when the message ends

            if (end != NULL) { //Help was found
                *end = '\0';
                return 0;
            }
        }
    }

    return -3; // Case where "HELP" wasn't found in the hidden message
}
