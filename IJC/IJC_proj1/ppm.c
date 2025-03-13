// ppm.c
   // Řešení IJC-DU1, příklad b), 13.3.2025
   // Autor: Josef Pasek, FIT
   // Přeloženo: gcc 14.2.1
// nacitani souboru typ ppm
#include "ppm.h"
#include <stdio.h>
#include <stdlib.h>
FILE * func_open(const char * filename){
    FILE *image_open = fopen(filename,"rb");
    if(image_open == NULL){
        error_exit("wrong name file %c ",filename);
        return NULL;
    }
    return image_open;
}
struct ppm * ppm_read(const char * filename){
    FILE * image_open = func_open(filename);
    char magic[3];
    if (fscanf(image_open, "%2s", magic) != 1 || strcmp(magic, "P6") != 0) {
        fclose(image_open);
        error_exit("wrong file format. Only P6 is supported");
    }
    int width_temp, height_temp, maxColorValue;
    if (fscanf(image_open, "%d %d %d", &width_temp, &height_temp, &maxColorValue) != 3) {
        fclose(image_open);
        error_exit("failed to read image");
    }
    if (maxColorValue < 0 || maxColorValue > 255) {
            fclose(image_open);
            error_exit("wrong max color value");
        }
    size_t size = width_temp * height_temp * 3;
    struct ppm *my_struct;
    my_struct = malloc(sizeof(struct ppm) + 3 * width_temp * height_temp);
    if(my_struct == NULL){
        fclose(image_open);
        error_exit("wrong malloc \n");
    }
    my_struct->xsize = width_temp;
    my_struct->ysize = height_temp;
    size_t size_bit = fread(my_struct->data,1,size,image_open);
    if(size_bit != size){
        fprintf(stderr," %lu : %lu \n",size_bit,size);
        fclose(image_open);
        error_exit("something goes wrong in reading \n");
    }
    fclose(image_open);
    return my_struct;
    }
    void ppm_free(struct ppm *p){
        free(p);

    }
