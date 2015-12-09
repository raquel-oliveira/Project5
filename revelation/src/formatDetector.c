#include <stdio.h>
#include <stdlib.h>

unsigned short BMP=0x4D42,
PNG[4]={0x5089,0x474E,0x0A0D,0x0A1A},
PPM1=0x3350,
PPM2=0x3650,
PGM1=0x3250,
PGM2=0x3550;


int isimage(char *enter){
	FILE *file;
	unsigned short pis[5];
	int flag = 0; 
	if((file = fopen(enter,"r")) == NULL)
		printf("can't read%s\n", enter);
	fread(pis,8,1,file);

	if(pis[0]==PNG[0] && pis[1]==PNG[1] && pis[2]==PNG[2] && pis[3]==PNG[3]){
		flag = 1;
		printf("This is a PNG\n");
	}

	if(pis[0]==BMP){
		flag = 2;
		printf("This is a BMP\n");
	}

	if(pis[0]==PPM1 || pis[0]==PPM2){
		flag = 3;
		printf("This is a PPM\n");
	}

	if(pis[0]==PGM1 || pis[0]==PGM2){
		flag = 4;
		printf("This is a PGM\n");
	}

	return flag;

}


int main(int argc, char const *argv[])
{
	char *enter = "../resource/lena.pgm";
	int flag = isimage(enter);
	printf("%d\n",flag);
	return 0;
}