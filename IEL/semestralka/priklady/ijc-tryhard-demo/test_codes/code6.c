#include <stdio.h>

// startPrint
// Jaký je výsledek výrazu:

void *f6() {
    long double i;
    // p je ukazatel na long double, který drží adresu i
    long double *p = &i;
    // snažíme se odčítat dva void pointery, což je nelegální ve standardu jazyka C
    // gcc má extension, který to umožňuje, díky tomu, že převede void pointer na char pointer
    // ale toto chování není ve standardu, takže odpověď je tu nedefinované chování
    return ((void*)(p+1)) - ((void*)p);
}

// stopPrint

int main()
{
    printf("undef");
    return 0;
}
