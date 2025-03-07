#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí funkce f27(3)?

int f27(int x) {
    // s je ukazatel na char 'A'
    static char *s = "ABCDEFGHIJKL";
    // k ukazateli s přičteme 3, dostaneme ukazatel na 'D'
    // tento ukazatel přetypujeme na void pointer
    // p rozdělí od ukazatele na 'D' pole s po 4 prvcích
    // co tedy budeme mít je { { 'D', 'E', 'F', 'G' }, { 'H', 'I', 'J', 'K' }, { 'L', '\0' } }
    const char (*p)[4] = (void*)(s + x);
    // p je ukazatel na 'D', odečtením jedničky se dostaneme před pole, což je nedefinované chování
    // program se přeloží, protože se nekontroluje sahání mimo pole
    return * (const char*)(p - 1);
}

// stopPrint

int main()
{
    printf("undef");
    return 0;
}
