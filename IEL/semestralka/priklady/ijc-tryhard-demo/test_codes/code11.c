#include <stdio.h>

// startPrint
// Jaký je výsledek výrazu:

char f11() {
    // "1234" + 1 se vyhodnotí jako ukazatel na '2'
    // sčítání ukazatele s ukazatelem je ale chyba při překladu
    return ( "1234" + 1 + "5678" )[4];
}

// stopPrint

int main()
{
    printf("compile");
    return 0;
}
