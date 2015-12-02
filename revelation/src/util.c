#include "util.h"

int get_bit(char the_byte,int which_bit) {
    return((the_byte>>(8-which_bit))&1);
}

char intToChar(int a){
    char c = a + '0';
    return c;
}

char intBToChar(int bin){
    char c;
    if (bin == 0){
        c = '0';
    }
    if (bin == 1){
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