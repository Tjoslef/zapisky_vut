#include <stdio.h>

// startPrint
// Jakou hodnotu má výraz a[3][1]?

// globální nebo částečně inicializované pole se nuluje
// pole a tedy bude vypadat:
// a = { { 1, 2, 0 }, { 3, 0, 0 }, { 4, 5, 6 } }
const int a[3][3] = { { 1, 2, }, { 3, }, { 4, 5, 6 } };
int f5() {
    // třetí index je ale mimo pole což je nedefinované chování
    // program se přeloží, protože překladač nekouká na sahání mimo meze pole
    return a[3][1];
}

// stopPrint

int main()
{
    printf("undef");
    return 0;
}
