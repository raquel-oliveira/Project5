//
// Created by Raquel Lopes de Oliveira on 10/01/2016.
//

#include "validateChannels.h"

void setChannels(){
    const char delimiter[2] = ",";
    int i = 0;
    char *aux;

    while(channels[i])
    {
        channels[i] = toupper(channels[i]);
        i++;
    }

    aux = strtok(channels, delimiter);
    if (aux != NULL) {
        firstChannel = numberColors(aux);
        aux = strtok(NULL, delimiter);
    } else{
        firstChannel = -1;
    }

    if (aux != NULL) {
        secondChannel = numberColors(aux);
        aux = strtok(NULL, delimiter);
    } else{
        secondChannel = -1;
    }

    if (aux != NULL) {
        thirdChannel = numberColors(aux);
    } else{
        thirdChannel = -1;
    }

}

int numberColors(char *aux){
    if (!strcmp(aux, "RED")){
        return 2;
    }
    else if (!strcmp(aux, "GREEN" )){
        return 1;
    }
    else  if (!strcmp(aux, "BLUE" )){
        return 0;
    }
    else {
        return -1;
    }
}