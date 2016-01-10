//
// Created by Raquel Lopes de Oliveira on 10/01/2016.
//

#include "checkChannels.h"

void setChannels(){
    while(channels[i])
    {
        channels[i] = toupper(channels[i]);
        i++;
    }

    if (channels == NULL){
        firstChannel = 2;
        secondChannel = 1;
        thirdChannel = 0;
    }else {
        char *aux;
        aux = strtok(channels, delimiter);
        //TODO: reuse the code.
        if (aux != NULL) {
            firstChannel = numberColors(aux);
            aux = strtok(NULL, s);
        } else{
            firstChannel = -1;
        }
        if (aux != NULL) {
            secondChannel = numberColors(aux);
            aux = strtok(NULL, s);
        } else{
            secondChannel = -1;
        }
        if (aux != NULL) {
            thirdChannel = numberColors(aux);
            aux = strtok(NULL, s);
        } else{
            thirdChannel = -1;
        }

    }

}

int numberColors(char *aux){
    if (strcmp(aux, "RED" )){
        return 2;
    }
    else if (strcmp(aux, "GREEN" )){
        return 1;
    }
    else  if (strcmp(aux, "BLUE" )){
        return 0;
    }
    else {
        return -1;
    }
}