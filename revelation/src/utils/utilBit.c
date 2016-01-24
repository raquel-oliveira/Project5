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
