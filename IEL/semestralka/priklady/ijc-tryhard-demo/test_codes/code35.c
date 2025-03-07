#include <stdio.h>

// startPrint
// Jakou hodnotu bude mít sum?

int f35_switch() {
    // DÁVAT VŽDY POZOR NA SUMU
    // u switche se skáče na case podle hodnoty i
    // jednotlivé casy jsou pouze návěští, na které se skáče s goto
    // když v tomto příkladu skočíme na case 4, 6 nebo 8, tak se sice přičte sum,
    // ale switch se breakne až na řádku s case 7: break;, protože to propadne dolů
    // na tohle si dávat extrémní pozor, nespíš je to aji hlavní důvod,
    // proč u příkladů se switchem možná děláte chybu
    int sum = 10;
    for(int i = 0; i < 9; i++) {
        switch(i) {
            case 4: case 6: case 8: sum++;
            case 7: break;
            default: sum--; continue;
        }
        break;
    }

    return sum;
}

// stopPrint

int main()
{
    printf("%d", f35_switch());
    return 0;
}
