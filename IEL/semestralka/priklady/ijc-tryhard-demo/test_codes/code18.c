#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí funkce f18()?

char f18() {
    // s je pole ukazatelů na char
    // s vypadá následovně:
    // s = { { '1', '2', '3', '4', '\0' }, 
    //       { '5', '6', '7', '8', '\0'}, 
    //       { 'A', 'B', 'C', 'D', '\0' } }
    char *s[] = { "1234", "5678", "ABCD", };
    // s[2] nás dostane na ukazatel na 'A', který přičteme o 1, čím dostaneme ukazatel na 'B'
    // s[2] nás dostane na ukazatel na 'B', přičteme 1, což nás dostane na ukazatel na 'C'
    // dereferencí ukazatele na 'C', dostaneme char 'C'
    // JE POTŘEBA DÁVÁT POZOR, ŽE PŘI RETURNU SE VRÁTÍ AŽ POSLEDNÍ VÝRAZ
    return s[2]++, * ( ++ s[2] );
}

// stopPrint

int main()
{
    printf("'%c'", f18());
    return 0;
}
