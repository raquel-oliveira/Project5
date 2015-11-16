#include <stdio.h>
#include <stdlib.h>

typedef unsigned short WORD;
typedef unsigned long DWORD;

typedef struct BMP_FILE_HEADER
{
	WORD bType;
	DWORD bSize;
	WORD bReserved1;
	WORD bReserved2;
	DWORD bOffset;
}BMPFILEHEADER;

typedef struct BMP_INFO
{
	DWORD bInfoSize; 
    DWORD bWidth; 
    DWORD bHeight; 
    WORD bPlanes; 
    WORD bBitCount; 
    DWORD bCompression; /*type of compression*/
    DWORD bmpImageSize; 
    DWORD bXPelsPerMeter; 
    DWORD bYPelsPerMeter;     
    DWORD bClrUsed; 
    DWORD bClrImportant; 
}BMPINF; 

typedef struct RGB_QUAD
{
    WORD rgbBlue; 
    WORD rgbGreen; 
    WORD rgbRed; 
    WORD rgbReversed; 
} RGBQUAD;

int main(int argc, char const *argv[])
{
	FILE *fp;
	BMPFILEHEADER fileHeader;
	BMPINF infoHeader;
    long offset, bmpImageSize, width, height, bytesPerPixel, size, bitCount;
	WORD c;

    if((fp = fopen("../resource/image.bmp", "rb")) == NULL){
    	printf("Cannot open the file\n");
    	exit(0);
    }

    fseek(fp,0,0);
    fread(&fileHeader,sizeof(fileHeader),1,fp);
    fread(&infoHeader,sizeof(infoHeader),1,fp);

    size = fileHeader.bSize;
    offset = fileHeader.bOffset;
    bmpImageSize = infoHeader.bmpImageSize;
    width = infoHeader.bWidth;
    height = infoHeader.bHeight;
    bitCount = infoHeader.bBitCount;
    bytesPerPixel = infoHeader.bBitCount/8;

    printf("%ld,%ld,%ld,%ld,%ld,%ld,%ld\n", size, offset, bmpImageSize, width, height, bitCount, bytesPerPixel);

    c = fgetc(fp);
    while(!feof(fp)){
    	printf("%x ",c);
    	c = fgetc(fp);
    }

    printf("\n");


    fclose(fp);
	return 0;
}