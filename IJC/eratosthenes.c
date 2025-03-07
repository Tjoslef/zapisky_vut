#include "bitset.h"
#include <time.h>
#include "error.h"
#include <stddef.h>
#include <stdio.h>
int main(){
// clock_t start_t, end_t;
  //  double total_t;
    //   start_t = clock();
    //I alloc a array of 000 where first index is number of them
    bitset_create(jmeno_pole, VELIKOST);
    //fill them with 1
    bitset_fill(jmeno_pole, 1);
    bitset_setbit(jmeno_pole, 0,0);
    bitset_setbit(jmeno_pole, 1,0);
    size_t size = bitset_size(jmeno_pole);
    /* go thought the pole and for every i we check if is not 0
    * if so we find all of number which a diveded by it and set there
    * bit 0 because they cannt be prime numbers
    */

   for (size_t i = 2; i * i <= size; i++) {
        if (bitset_getbit(jmeno_pole, i) == 1) {
            for (size_t j = i * i; j < size; j += i) {
                bitset_setbit(jmeno_pole, j, 0);

            }
        }
    }
    size_t count = 0;
    for (size_t i = ((VELIKOST - 1) / 64); i > 0; i--) {
        for (int j = (int)(sizeof(unsigned long) * 8 - 1); j >= 0; j--){
            if((jmeno_pole[i] & (1UL << j)) != 0){
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
        putchar('\n');
    }

/*
printf("\n");
       end_t = clock();
   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
       printf("Total time taken by CPU: %f\n", total_t  );
    */
}
