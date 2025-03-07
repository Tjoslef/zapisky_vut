#include <stdio.h>

// startPrint
// Jakou hodnotu bude mít sum?

int f36_switch() {
    // DÁVAT VŽDY POZOR NA SUMU
    // u switche se skáče na case podle hodnoty i
    // jednotlivé casy jsou pouze návěští, na které se skáče s goto
    // když v tomto příkladu skočíme na case 4, 5 nebo 6, tak se sice odečte sum,
    // ale switch se breakne až na řádku s case 7: break;, protože to propadne dolů
    // na tohle si dávat extrémní pozor, nespíš je to aji hlavní důvod,
    // proč u příkladů se switchem možná děláte chybu
    int sum = 0;
    for(int i=0; i<9; i++) {
        switch(i) {
            case 4: case 5: case 6: sum--;
            case 7: break;
            default: sum++;
                     continue;
        }
        break;
    }

    return sum;
}

// stopPrint

int main()
{
    printf("%d", f36_switch());
    return 0;
}
