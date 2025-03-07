#include <stdio.h>

// startPrint
// Jakou hodnotu má výraz:

long long int f12() {
    // a je pole dvou doublů
    static double a[] = { 1, 2, };
    // snažíme se odčítat dva void pointery, což je nelegální ve standardu jazyka C
    // gcc má extension, který to umožňuje, díky tomu, že převede void pointer na char pointer
    // ale toto chování není ve standardu, takže odpověď je tu nedefinované chování
    return ( (void*)(a+2) - (void*)a );
}

// stopPrint

int main()
{
    printf("undef");
    return 0;
}
