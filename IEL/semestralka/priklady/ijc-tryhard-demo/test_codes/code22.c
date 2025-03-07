#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí funkce f22()?

char f22() {
    // s je pole 7 ukazatelů na const char
    // s vypadá následovně:
    // s = { { '0', '1', '2', '3', '4', '5', '6', '\0' }, 
    //       { 'A', 'B', 'C', 'D', 'E', 'F', '\0' }, 
    //       { '6', '5', '4', '3', '2', '1', '0', '\0' } }
    const char *s[7] = { "0123456", "ABCDEF", "6543210", };
    // s[1] je ukazatel na 'A', který přičteme o 2, to je ukazatel na 'C'
    // dereference ukazatele na 'C' nám dá char 'C'
    return * (s[1]++ + 2);
}

// stopPrint

int main()
{
    printf("'%c'", f22());
    return 0;
}
