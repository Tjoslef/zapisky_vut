#include <stdio.h>

// startPrint
// Co vrátí funkce f2()?

size_t f2(float p[9][10]) {
    // když je parametr pole, tak se "první pole" přetypuje na ukazatel
    // parametr funkce je tedy ve skutečnosti float (*p)[10]
    // velikost floatu není pevně daná, je daná implementací
    // jedině char má vždy velikost 1 byte
    // správná odpověď je tedy "sizeof(float (*)[10])", mohl by uznat i "sizeof(float *)"
    return sizeof(p);
}

// stopPrint

int main()
{
    printf("sizeof(float (*)[10]);\
sizeof(float *)");
    return 0;
}
