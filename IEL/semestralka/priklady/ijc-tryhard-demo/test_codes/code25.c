#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí funkce f25()?

char f25() {
    // s je pole ukazatelů na const char
    // s vypadá následovně:
    // s = { { '0', '1', '2', '3', '\0' }, 
    //       { '4', '5', '6', '7', '\0'}, 
    //       { '8', '9', 'A', 'B', '\0' } }
    const char *s[] = { "0123", "4567", "89AB", };
    // s[1] nás dostane na ukazatel na '4', který přičteme o 1, čím dostaneme ukazatel na '5'
    // *(s+1) je stejné jako s[1], což nás dostane na ukazatel na '5', přičteme 2, což nás dostane na ukazatel na '7'
    // dereferencí ukazatele na '7', dostaneme char '7'
    // JE POTŘEBA DÁVÁT POZOR, ŽE PŘI RETURNU SE VRÁTÍ AŽ POSLEDNÍ VÝRAZ
    return s[1]++, * ( *(s+1) + 2 );
}

// stopPrint

int main()
{
    printf("'%c'", f25());
    return 0;
}
