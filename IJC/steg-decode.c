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
//    printf("width : %d height %d",my_struct->xsize,my_struct->ysize);
    size_t size = my_struct->xsize *my_struct->ysize * 3;
    /* for(size_t i = 0;i < size;i++){
        printf(" %c ",my_struct->data[i]);
    }
    */

    bitset_alloc(image_bit, size);
    /*
    *for(size_t i = 0;i <= size;i++){
        for(int j = 8;j >=0;j++){
            if((my_struct->data[i] & (1U << j)) == '0'){
                bitset_setbit(image_bit,i, 0);
            }else {
                bitset_setbit(image_bit,i,1);
            }
        }
        }
    */
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
/*    int index_bit = 0;
    size_t index_byte = 0;
    char *message = malloc(size);
    if(message == NULL){
        error_exit("wrong malloc");
    }
    */
    int count = 0;
    for (size_t i = ((image_bit[0] - 1) / 64); i > 0; i--) {
            for (int j = (int)(sizeof(unsigned long) * 8 - 1); j >= 0; j--){
                if((image_bit[i] & (1U << j)) != 0){
                    size_t index = (i - 1) * 64 + j;
                    printf(" %lu \n", index);
                    count++;
                    if (count == 10) {
                        break; // Break inner loop
                    }
                }
            }
            if (count == 10) {
                break; // Break outer loop
            }
    }
  /*  for(size_t i = START_PRIME;i < image_bit[0];i++){
        if((bitset_getbit(image_bit, i)) == 0){
            int extracted_bit = my_struct->data[i] & 1;
            if (extracted_bit) {
                       message[index_byte] |= (1U << index_bit);
                   } else {
                       message[index_byte] &= ~(1U << index_bit);
            }
            index_bit++;
            if(index_bit == 8){
                index_bit = 0;
                index_byte++;
            }
        }
    }
    if(index_byte > 0){
        index_byte++;
    }
    */
  /*  char *new_message = realloc(message, index_byte);
    if(new_message == NULL){
        error_exit("wrong realloc");
    }else {
        message = new_message;
    }
    */
  //  printf("used bytes %lu",index_byte);
    /*
    for(int i = 0;i < index_byte;i++){
        printf("%c",message[i]);
    }
*/
    bitset_free(image_bit);
    ppm_free(my_struct);
}
