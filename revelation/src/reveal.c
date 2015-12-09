#include "reveal.h"

#define SIZE_MESSAGE 100

uchar* revealDirect(IplImage *img, int nbBits, char help[], uchar *message)
{
    int lbit, channel, count = 7, i = 0;
    uchar letter = 1;
    char* end;
    int size = SIZE_MESSAGE;
    
    for (int row = 0; row < img->height; row++)
    {
        for (int col = 0; col < img->width; col++)
        {
            channel = cvGet2D(img, row, col).val[2]; //channel red
            
            lbit = get_bit(channel, (9 - nbBits)); //access to the bit in ascending order
            letter = setBit(letter, count, lbit);
            count--;
            if (count < 0)
            {
                if(i >= size - 1)
                {
                    size += SIZE_MESSAGE;
                    message = realloc(message, size);
                    if(message == NULL) exit(0);
                }
                count = 7;
                message[i] = letter;
                i++;
            }

            end = strstr(message, help);
            
            if (end != 0)
            {
                *end = '\0';
                return message;
            }
        }
    }
    
    free(end);
    
    return message;
}