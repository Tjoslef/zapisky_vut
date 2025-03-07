#include <stdio.h>

// startPrint
// Jaký je typ a výsledek výrazu:

char f10() {
    // POZOR! NA ČÁRKU VE VÝRAZU KVŮLI KTERÉ SE "ABC" A "DE" NESPOJÍ!
    // první část ("ABC") se zahodí a vyhodnotí se jenom "DE"[1]
    // char 'E' je správná odpověď
    return ( "ABC", "DE" )[1];
}

// stopPrint

int main()
{
    printf("char '%c'", f10());
    return 0;
}
