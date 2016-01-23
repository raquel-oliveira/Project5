//
// Created by Raquel Lopes de Oliveira on 23/01/2016.
//

#include "file.h"

void printFile(FILE* file, char* path){
    file = fopen(path, "r");
    char c;
    if (file) {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
}

int containsMagicNumber(char* message, int messageSize, char* magic, int magicSize)
{

    if(messageSize<magicSize)  return -1;

    return memcmp(&(message[messageSize-magicSize]),magic,magicSize);

}