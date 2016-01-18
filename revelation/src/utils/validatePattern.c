#include "validatePattern.h"

int validatePattern() {
    int i = 0;
    while(pattern[i])
    {
        pattern[i] = toupper(pattern[i]);
        i++;
    }
    if (strcmp(pattern,"DIRECT") == 0) {
        return 1;
    }
    else if (strcmp(pattern,"INVERSE") == 0) {
        return 2;
    }
    if (strcmp(pattern,"EXTERNAL_SPIRAL") == 0) {
        return 3;
    }
    if (strcmp(pattern,"INTERNAL_SPIRAL") == 0) {
        return 4;
    }
    else
        return -1;
}