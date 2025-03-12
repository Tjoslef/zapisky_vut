#include "bitset.h"
#include "error.h"
void Eratosthenes(bitset_t jmeno_pole){
   size_t size = bitset_size(jmeno_pole);
   for (size_t i = 2; i * i <= size; i++) {
        if (bitset_getbit(jmeno_pole, i) == 1) {
            for (size_t j = i * i; j < size; j += i) {
                bitset_setbit(jmeno_pole, j, 0);

            }
        }
    }
    size_t count = 0;
    for (size_t i = ((jmeno_pole[0] - 1) / 64); i > 0; i--) {
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

}
