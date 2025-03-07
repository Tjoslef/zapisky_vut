#include <stdio.h>

// startPrint
// Jakou hodnotu má výraz a[2][1]

int f8() {
    // globální nebo částečně inicializované pole se nuluje
    // pole a tedy bude vypadat:
    // a = { { 0, 1, 0, 0 }, { 2, 0, 0, 0 }, { 3, 4, 5, 0 } }
    int a[3][4] = { { 0, 1 }, { 2, }, { 3, 4, 5, } };
    // podíváme se do třetí závorky na druhý prvek, který je 4 a to je správná odpověď
    return a[2][1];
}

// stopPrint

int main()
{
    printf("%d", f8());
    return 0;
}
