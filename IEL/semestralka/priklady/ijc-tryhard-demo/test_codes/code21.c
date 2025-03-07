#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí funkce f21()?

char f21() {
    // s je pole ukazatelů na const char
    // s vypadá následovně:
    // s = { { '0', '1', '2', '3', '\0' }, 
    //       { '4', '5', '6', '7', '\0'}, 
    //       { '8', '9', 'x', 'y', '\0' } }
    const char *s[] = { "0123", "4567", "89xy", };
    // provede se dereference s, což je ukazatel na '8'
    // přičtení 1 se dostaneme na ukazatel na '9'
    // dereference ukazatele na '9', nám dá char '9'
    return * ++ (s[2]);
}

// stopPrint

int main()
{
    printf("'%c'", f21());
    return 0;
}
