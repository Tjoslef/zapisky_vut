#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <time.h>
#include <sqlite3.h>
#include <stdbool.h>
#include <libgen.h>

char *getName(const char *song){
    char *path_cp = strdup(song);
    if(!path_cp){
        perror("failed malloc in getName");
        return NULL;
    }
    char *filename = basename(path_cp);
    char *name = strdup(filename);
    free(path_cp);
    if(!name){
        perror("failed malloc in getName");
        return NULL;
    }

    char *dot = strrchr(name, '.');
    if(dot != NULL){
        *dot = '\0';
    }

    return name;
}


int main(){
const char *adrres = "/home/tjoslef/skola/music_player/tests/crang.wav";
    char *name = getName(adrres);
printf("name of song is:   %c",*name);
}
