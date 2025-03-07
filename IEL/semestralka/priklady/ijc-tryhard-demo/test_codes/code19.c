#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí funkce f19()?

char f19() {
    // s je pole ukazatelů na const char
    // s vypadá následovně:
    // s = { { '0', '1', '2', '\0' }, 
    //       { '3', '4', '5', '\0'}, 
    //       { '6', '7', '8', '\0' } }
    const char *s[] = { "012", "345", "678", };
    // provede se dereference s, což je ukazatel na '0'
    // přičtení 1 se dostaneme na ukazatel na '1'
    // dereference ukazatele na '1', nám dá char '1'
    return * ++ (*s);
}

// stopPrint

int main()
{
    printf("'%c'", f19());
    return 0;
}
