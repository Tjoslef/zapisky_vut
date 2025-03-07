#include <stdio.h>

// startPrint
// Jakou hodnotu má výraz a[1][1]?

// globální nebo částečně inicializované pole se nuluje
// pole a tedy bude vypadat:
// a = { { 1, 2, 0, 0 }, { 3, 0, 0, 0 }, { 4, 5, 6, 0 } }
const int a[3][4] = { { 1, 2, }, { 3, }, { 4, 5, 6, } };
int f4() {
    // pole se indexuje od 0 indexu, takže a[1][1] je 0 za 3, takže se vrací 0
    return a[1][1];
}

// stopPrint

int main()
{
    printf("%d", f4());
    return 0;
}
