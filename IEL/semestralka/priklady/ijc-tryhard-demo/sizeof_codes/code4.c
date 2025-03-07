#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí funkce f4()?

size_t f4(void * pole[4][5][6]) {
    // když je parametr pole, tak se "první pole" přetypuje na ukazatel
    // parametr funkce je tedy ve skutečnosti void *(*pole)[5][6]
    // dereference nám z toho udělá void *[5][6]
    // (void *[5][6])[4] nám v prvním poli velikost 5 ukáže na poslední pole, ve kterém je 6 prvků typu void *
    // velikost voidu není pevně daná, je daná implementací
    // jedině char má vždy velikost 1 byte
    // správná odpověď je tedy "6 * sizeof(void *)"
    return sizeof( (*pole)[4] );
}

// stopPrint

int main()
{
    printf("6 * sizeof(void *);\
sizeof(void *) * 6");
    return 0;
}
