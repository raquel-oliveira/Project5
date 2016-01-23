#include "utilBit.h"
#include "../arguments.h"

int get_bit(char the_byte,int which_bit)
{
    if (which_bit > 8 || which_bit < 1 ){
        return -1; //Error, out of range of a byte.
    }
    return((the_byte >> (8 - which_bit)) & 1);
}

uchar setBit(uchar ch, int pos, int bit)
{
    if (bit == 0) ch = ~(1 << pos)& ch;
    if (bit == 1) ch = (1<< pos)| ch;
    return ch;
}


void shift(char* message){
    int size = strlen(message);
    //printf("%s %d\n", message, message);
    for(int i = 0; i < size; i++){
        message[i] = message[i+1];
        //printf("coloquei o elemento %d da pos %d\n", message[i+1], i);
    }

   // return 1;
}