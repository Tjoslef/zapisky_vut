#include <stdio.h>

// startPrint
// Co vrátí funkce f5()?

size_t f5(int pole [2][6]) {
    // když je parametr pole, tak se "první pole" přetypuje na ukazatel
    // jelikož je pole nyní ukazatel, tak je legální pole++ v sizeofu
    // parametr funkce je tedy ve skutečnosti int (*pole)[6]
    // dereference nám z toho udělá int *(*pole)[6]
    // velikost intu není pevně daná, je daná implementací
    // jedině char má vždy velikost 1 byte
    // správná odpověď je tedy "sizeof(int *)"
    return sizeof(pole++);
}

// stopPrint

int main()
{
    printf("sizeof(int *)");
    return 0;
}
