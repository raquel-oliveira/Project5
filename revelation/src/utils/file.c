//
// Created by Raquel Lopes de Oliveira on 23/01/2016.
//

#include "file.h"

void printFile(char* path){
    FILE* filePrint =  fopen(path, "r");
    char c;
    fputc(EOF, filePrint);
    if (filePrint) {
        while ((c = getc(filePrint)) != EOF)
            putchar(c);
        fclose(filePrint);
        printf("\n\n");
    }
}

void printFileBinary(char* path){
    FILE* filePrint =  fopen(path, "r");
    char c;
    fputc(EOF, filePrint);
    if (filePrint) {
        while ((c = getc(filePrint)) != EOF){
            for(int i = 1; i <= 8; i++){
                printf("%d", get_bit(c, i));
            }
        }

        fclose(filePrint);
        printf("\n\n");
    }
}

int containsMagicNumber(char* message, int messageSize, char* magic, int magicSize)
{
    if(messageSize<magicSize)  return -1;

    return memcmp(&(message[messageSize-magicSize]),magic,magicSize);

}