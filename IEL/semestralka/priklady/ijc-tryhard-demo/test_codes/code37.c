#include <stdio.h>

// startPrint
// Jakou hodnotu bude mít sum?

int f37_switch() {
    // DÁVAT VŽDY POZOR NA SUMU
    // u switche se skáče na case podle hodnoty i
    // jednotlivé casy jsou pouze návěští, na které se skáče s goto
    // když v tomto příkladu skočíme na case 4, 6 nebo 8, tak se sice odečte sum,
    // ale protože tam není break; tak to propadne dolů a znovu se sum přičte a pokračuje se na další iteraci cyklu
    // na tohle si dávat extrémní pozor, nespíš je to aji hlavní důvod,
    // proč u příkladů se switchem možná děláte chybu
    int sum = 0;
    for(int i=0; i<9; i++) {
        switch (i) {
            case 7: break;
            case 4: case 6: case 8: sum--;
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
    printf("%d", f37_switch());
    return 0;
}
