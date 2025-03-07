#include <stdio.h>

// startPrint
// Jakou hodnotu bude mít sum?

int f34_switch() {
    // DÁVAT VŽDY POZOR NA SUMU
    // u switche se skáče na case podle hodnoty i
    // jednotlivé casy jsou pouze návěští, na které se skáče s goto
    // když v tomto příkladu skočíme na case 1, 3, 5 nebo 7, tak se sice odečte sum,
    // ale switch propadne a znovu se sum přičte a pokračuje se v cyklu na další iteraci
    // na tohle si dávat extrémní pozor, nespíš je to aji hlavní důvod,
    // proč u příkladů se switchem možná děláte chybu
    int sum = 0;
    for(int i = 0; i < 8; i++) {
        switch(i) {
            case 1: case 3: case 5: case 7: sum--;
            default: sum++; continue;
            case 6: break;
        }
    }

    return sum;
}

// stopPrint

int main()
{
    printf("%d", f34_switch());
    return 0;
}
