//
// Created by Raquel Lopes de Oliveira on 19/01/2016.
//

#include "decompress.h"

typedef struct {
    Character* elements; //Change this number to the number of first byte
    int size;
    int valueLastByte;
} Dictionary;

int createDictionary() {
    fileOut = "Resources/exempleToDecompress"; // To Test
    output = fopen(fileOut, "r"); // To test
    if (!output){
        return -1;
        //exit(EXIT_FAILURE);
    }

    char c = getc(output);
    int numberElements = c; // First byte in a integer

    printf("The number of elements is: %d\n", (numberElements + 1));

    Dictionary *dictionary = malloc(sizeof(Dictionary));
    dictionary->size = numberElements;
    dictionary->elements = malloc((numberElements)* sizeof(Character));
    int i = 0; int aux_elem =0;
    for (; i < numberElements; ++i) {
        dictionary->elements[i].value = getc(output);;
        printf("Value of element: %d is : %c\n", i, dictionary->elements[i].value);
        dictionary->elements[i].sizeOfKey = getc(output);
        printf("The size of element: %d is : %d\n", i, dictionary->elements[i].sizeOfKey);
        dictionary->elements[i].key = getc(output);
        printf("The key of element: %d is %d\n", i, dictionary->elements[i].key);

    }
    dictionary->valueLastByte = getc(output);
    printf("The last byte will use %d number of bits\n", dictionary->valueLastByte );

}