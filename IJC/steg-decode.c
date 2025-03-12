#include "ppm.h"
#include "bitset.h"
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
     bitset_fill(image_bit, 1);

    bitset_setbit(image_bit, 0,0);
    bitset_setbit(image_bit, 1,0);
   for (size_t i = 2; i * i <= size; i++) {
        if (bitset_getbit(image_bit, i) == 1) {
            for (size_t j = i * i; j < size; j += i) {
                bitset_setbit(image_bit, j, 0);

            }
        }
    }
    int index_bit = 0;
    size_t index_byte = 0;
    int count = 0;
char *message = calloc(size, sizeof(char));
    if(message == NULL){
        error_exit("wrong malloc");
    }
 for(size_t i = START_PRIME;i < image_bit[0];i++){
        if((bitset_getbit(image_bit, i)) == 1){
            printf(" %lu ",i);
            int extracted_bit = my_struct->data[i] & 1;
            if (extracted_bit) {
                       message[index_byte] |= (1U << index_bit);
                   } else {
                       message[index_byte] &= ~(1U << index_bit);
            }
            count++;
            if(count % 8 == 0){
                index_byte++;
                printf("%c \n",message[index_byte]);
            }
        }
    }
    if(index_byte > 0){
        index_byte++;
    }
    printf(" number primes in there %c",index_bit);
    char *new_message = realloc(message, index_byte);
    if(new_message == NULL){
        error_exit("wrong realloc");
    }else {
        message = new_message;
    }
size_t p;
   printf("used bytes %lu",index_byte);
    for(p = 0;message[p] != '\0';p++){
        printf("%c ",message[p]);
    }
printf("number of character in message %lu",p);
    free(message);
    bitset_free(image_bit);
    ppm_free(my_struct);
}
