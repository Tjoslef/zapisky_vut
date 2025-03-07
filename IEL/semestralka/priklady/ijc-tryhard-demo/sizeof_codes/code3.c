#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí funkce f3()?

int f3(int *p[2][3][4]) {
    // když je parametr pole, tak se "první pole" přetypuje na ukazatel
    // parametr funkce je tedy ve skutečnosti int *(*p)[3][4]
    // dereference nám z toho udělá int *[3][4]
    // velikost intu není pevně daná, je daná implementací
    // jedině char má vždy velikost 1 byte
    // správná odpověď je tedy "sizeof(int *[3][4])", mohl by uznat i "3 * 4 * sizeof(int *)"
    return sizeof(*p);
}

// stopPrint

int main()
{
    printf("sizeof(int *[3][4]);\
3 * 4 * sizeof(int *);\
4 * 3 * sizeof(int *);\
sizeof(int *) * 3 * 4;\
sizeof(int *) * 4 * 3");
    return 0;
}
