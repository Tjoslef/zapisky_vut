// steg-decode.c
   // Řešení IJC-DU1, příklad b), 13.3.2025
   // Autor: Josef Pasek, FIT
   // Přeloženo: gcc 14.2.1
// decryptovani obrazku na vyslednou spravu
#include "ppm.h"
#include "bitset.h"
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define START_PRIME 101
int main(int argc,char *argv[]){
    if(argc < 2){
        error_exit("no enought input \n");
    }
    struct ppm *my_struct;
    my_struct = ppm_read(argv[1]);
    size_t size = my_struct->xsize *my_struct->ysize * 3;
    bitset_alloc(image_bit, size);
    image_bit[0] = size;
    Eratosthenes(image_bit);
    char c = 0;
    int index_bit = 0;
for (size_t i = START_PRIME; i < image_bit[0]; i++) {
    if (bitset_getbit(image_bit, i) == 1) {
            printf("%lu \n",i);
        c |= (my_struct->data[1+i] & 1) << index_bit++;

        if (index_bit == CHAR_BIT) {
            if (c == '\0') {
                break;
            }
          //  printf("%c",c);
            c = 0;
            index_bit = 0;
        }    }
}  //   printf(" number primes in there %d \n",count);

    bitset_free(image_bit);
    ppm_free(my_struct);
}
