#include "formatDetector.h"

unsigned short BMP=0x4D42,
PNG[4]={0x5089,0x474E,0x0A0D,0x0A1A},
PPM1=0x3350,
PPM2=0x3650,
PGM1=0x3250,
PGM2=0x3550;

int detect_format(char *path){
	FILE *file;
	unsigned short pis[5];
	int flag;
	if((file = fopen(path,"r")) == NULL)
		printf("can't read%s\n", path);
	fread(pis,8,1,file);

	//PNG
	if(pis[0]==PNG[0] && pis[1]==PNG[1] && pis[2]==PNG[2] && pis[3]==PNG[3]){
		flag = 1;
	}
	//BMP
	else if (pis[0]==BMP){
		flag = 2;
	}
	//PPM
	else if(pis[0]==PPM1 || pis[0]==PPM2){
		flag = 3;
	}
	//PGM
	else if(pis[0]==PGM1 || pis[0]==PGM2){
		flag = 4;
	}
	else{
		flag = -1;
	}

	return flag;

}