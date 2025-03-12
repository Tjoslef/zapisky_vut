#include "bitset.h"
int main(){
 clock_t start_t, end_t;
    double total_t;
       start_t = clock();
    //I alloc a array of 000 where first index is number of them
    size_t velikost = 1000;
    bitset_alloc(jmeno_pole, velikost);
    //fill them with 1
    bitset_fill(jmeno_pole, 1);
    bitset_setbit(jmeno_pole, 0,0);
    bitset_setbit(jmeno_pole, 1,0);
    /* go thought the pole and for every i we check if is not 0
    * if so we find all of number which a diveded by it and set there
    * bit 0 because they cannt be prime numbers
    */
    Eratosthenes(jmeno_pole);
    printf("\n");
       end_t = clock();
   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
       printf("Total time taken by CPU: %f\n", total_t  );


}
