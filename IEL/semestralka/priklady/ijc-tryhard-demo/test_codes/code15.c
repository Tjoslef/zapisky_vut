#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí funkce f15(4)?

char f15(int x) {
    // s je ukazatel na char 'A'
    static char *s = "ABCDEFGH";
    // k ukazateli s přičteme 4, dostaneme ukazatel na 'E'
    // tento ukazatel přetypujeme na void pointer
    // p rozdělí od ukazatele na 'E' pole s po 3 prvcích
    // co tedy budeme mít je { { 'E', 'F', 'G' }, { 'H', '\0' } }
    const char (*p)[3] = (void *)(s + x);
    // p + 1 začne ukazovat na podpole { 'H', '\0' }
    // přetypování na const char, nám udělá ukazatel na const char 'H'
    // dereference tohoto ukazatele nám dá char 'H', což je správná odpověď
    return * (const char *)(p + 1);
}

// stopPrint

int main()
{
    printf("'%c'", f15(4));
    return 0;
}
