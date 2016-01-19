//
// Created by Raquel Lopes de Oliveira on 19/01/2016.
//

#include "decompress.h"

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
    for (; i <= numberElements; ++i) {
        dictionary->elements[i].value = getc(output);;
        dictionary->elements[i].sizeOfKey = getc(output);
        int pos = dictionary->elements[i].sizeOfKey -1;
        int bitSet;
        c = getc(output);
        for(int k = 1; k <= dictionary->elements[i].sizeOfKey; k++){
            bitSet = get_bit(c, k);
            dictionary->elements[i].key = setBit(dictionary->elements[i].key,pos, bitSet);
            pos--;
        }
        printf("---------The key of element: %c is %d with size %d----------\n", dictionary->elements[i].value, dictionary->elements[i].key, dictionary->elements[i].sizeOfKey);

    }
    dictionary->valueLastByte = getc(output);
    printf("The last byte will use %d number of bits\n", dictionary->valueLastByte );

}