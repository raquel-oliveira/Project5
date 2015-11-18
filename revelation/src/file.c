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
    char c = a+ '0';
    return c;
}