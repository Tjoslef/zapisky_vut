#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí funkce f20()?

char f20() {
    // s je pole ukazatelů na const char
    // s vypadá následovně:
    // s = { { '0', '1', '2', '3', '\0' }, 
    //       { '4', '5', '6', '7', '\0'}, 
    //       { '8', '9', 'A', 'B', '\0' } }
    const char *s[] = { "0123", "4567", "89AB", };
    // s[2] nás dostane na ukazatel na '8', který přičteme o 1, čím dostaneme ukazatel na '9'
    // *(s+2) je stejné jako s[2], což nás dostane na ukazatel na '9', přičteme 1, což nás dostane na ukazatel na 'A'
    // dereferencí ukazatele na 'A', dostaneme char 'A'
    // JE POTŘEBA DÁVÁT POZOR, ŽE PŘI RETURNU SE VRÁTÍ AŽ POSLEDNÍ VÝRAZ
    return s[2]++ , * ( * (s+2) + 1 );
}

// stopPrint

int main()
{
    printf("'%c'", f20());
    return 0;
}
