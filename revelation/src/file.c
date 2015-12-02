#include "file.h"

/**
 * ftell(FILE *stream)
 * @param stream - This is the pointer to a FILE object that identifies the stream.
 * @return - This function returns the current value of the position indicator.
 * If an error occurs, -1L is returned, and the global variable errno is set to a positive value.
 */

/**
 * int fseek(FILE *stream, long int offset, int whence)
 * @param stream − This is the pointer to a FILE object that identifies the stream.
 * @param offset − This is the number of bytes to offset from whence.
 * @param whence − This is the position from where offset is added. It is specified by one of the following constants −
 *      SEEK_SET	Beginning of file
        SEEK_CUR	Current position of the file pointer
        SEEK_END	End of file
 * @return This function returns zero if successful, or else it returns a non-zero value.
 */
/*int get_message_length(FILE *fp) {
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    return(size);
}*/

int get_bit(char the_byte,int which_bit) {
    return((the_byte>>(8-which_bit))&1);
}

char intToChar(int a){
    char c = a + '0';
    return c;
}

char intBToChar(int a){
    char c;
    if (a == 0){
        c = '0';
    }
    if (a == 1){
        c = '1';
    }
    return c;
}

/*
 * @param matrixColor
 * @param qtdbit number of bits the message was hidden
 * */
char* messageFromOneColor(int **matrixColor, int b, int height, int width ){
    int maxSize = 10000;
    char aux_message;
    char *messageHidden = malloc(maxSize);
    int charCount = 0;
    int cont = 0; // bit as 0 as the last significant bit and 7 as the most significant bit
    int row, col;
    for (row = 0; row < height; row ++){
        for (col = 0; col < width; col ++){
            while (cont < b){
                aux_message = intBToChar(get_bit(matrixColor[row][col], cont));
                messageHidden[charCount++] = aux_message;
                cont ++;
                if(charCount >= maxSize){
                    maxSize *= 2;
                    messageHidden = (char *) realloc(messageHidden, maxSize*sizeof(char));
                }
            }
            cont = 0;
        }
    }
    return messageHidden;
}

/*
 * @param firstColor
 * @param secondColor
 * @param qtdbit number of bits the message was hidden
 * */
char* messageFromTwoColor(int **firstColor, int **secondColor, int b, int height, int width ){
    int maxSize = 10000;
    char aux_message;
    char *messageHidden = malloc(maxSize);
    int charCount = 0;
    int cont = 0; // bit as 0 as the last significant bit and 7 as the most significant bit
    int row, col;
    for (row = 0; row < height; row ++){
        for (col = 0; col < width; col ++){
            while (cont < b){
                aux_message = intBToChar(get_bit(firstColor[row][col], cont));
                messageHidden[charCount++] = aux_message;
                cont ++;
                if(charCount >= maxSize){
                    maxSize *= 2;
                    messageHidden = (char *) realloc(messageHidden, maxSize*sizeof(char));
                }
            }
            cont = 0;
            while (cont < b){
                aux_message = intBToChar(get_bit(secondColor[row][col], cont));
                messageHidden[charCount++] = aux_message;
                cont ++;
                if(charCount >= maxSize){
                    maxSize *= 2;
                    messageHidden = (char *) realloc(messageHidden, maxSize*sizeof(char));
                }
            }
            cont = 0;
        }
    }
    return messageHidden;
}

/*
 * @param firstColor
 * @param secondColor
 * @param qtdbit number of bits the message was hidden
 * */
char* messageFromThreeColor(int **firstColor, int **secondColor, int **thirdColor, int b, int height, int width ){
    int maxSize = 10000;
    char aux_message;
    char *messageHidden = malloc(maxSize);
    int charCount = 0;
    int cont = 0; // bit as 0 as the last significant bit and 7 as the most significant bit
    int row, col;
    for (row = 0; row < height; row ++){
        for (col = 0; col < width; col ++){
            while (cont < b){
                aux_message = intBToChar(get_bit(firstColor[row][col], cont));
                messageHidden[charCount++] = aux_message;
                cont ++;
                if(charCount >= maxSize){
                    maxSize *= 2;
                    messageHidden = (char *) realloc(messageHidden, maxSize*sizeof(char));
                }
            }
            cont = 0;
            while (cont < b){
                aux_message = intBToChar(get_bit(secondColor[row][col], cont));
                messageHidden[charCount++] = aux_message;
                cont ++;
                if(charCount >= maxSize){
                    maxSize *= 2;
                    messageHidden = (char *) realloc(messageHidden, maxSize*sizeof(char));
                }
            }
            cont = 0;
            while (cont < b){
                aux_message = intBToChar(get_bit(thirdColor[row][col], cont));
                messageHidden[charCount++] = aux_message;
                cont ++;
                if(charCount >= maxSize){
                    maxSize *= 2;
                    messageHidden = (char *) realloc(messageHidden, maxSize*sizeof(char));
                }
            }
            cont = 0;
        }
    }
    return messageHidden;
}