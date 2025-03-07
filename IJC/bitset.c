#include "bitset.h"
#include <stddef.h>
#include <stdio.h>
int main(){
    bitset_alloc(jmeno_pole,VELIKOST);
    size_t size = bitset_size(jmeno_pole);
    bitset_fill(jmeno_pole,1);
    printf("number of for loops is: %lu  \n",size);
    for (size_t i = 1; i < ((VELIKOST - 1) / 64) + 2; i++) {
        for(int j = sizeof(unsigned long) * 8 - 1;j >= 0;j--){
            putchar((jmeno_pole[i] & (1UL <<j))? '1' : '0');
            }
        putchar('\n');
    }
    bitset_setbit(jmeno_pole,333,0);
     printf("number of for loops is: %lu  \n",size);
    for (size_t i = 1; i < ((VELIKOST - 1) / 64) + 2; i++) {
        for(int j = sizeof(unsigned long) * 8 - 1;j >= 0;j--){
            putchar((jmeno_pole[i] & (1UL <<j))? '1' : '0');
            }
        putchar('\n');
    }

    printf("\n");
    return 0;

}
