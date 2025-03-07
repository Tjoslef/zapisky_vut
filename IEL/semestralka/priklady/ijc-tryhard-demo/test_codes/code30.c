#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí funkce f30(3)?

char f30(int x) {
    // s je ukazatel na char 'A'
    static char *s = "ABCDEFGHIJKL";
    // u ukazateli s přičteme 3, dostaneme ukazatel na 'D'
    // tento ukazatel přetypujeme na void pointer
    // p rozdělí od ukazatele na 'D' pole s po 2 prvcích
    // co tedy budeme mít je { { 'D', 'E' }, { 'F', 'G' }, { 'H', 'I' }, { 'J', 'K' }, { 'L', '\0' } }
    const char (*p)[2] = (void*)(s + x);
    // p je ukazatel na 'D', přičtením dvojky se posuneme o dvě pole dál, což je ukazatel na pole { 'H', 'I' }
    // první dereference udělá z ukazatele na pole -> ukazatel na const char 'H'
    // dereference ukazatel na const char 'H', nám dá jen char 'H'
    return * (const char *)(p+2);
}

// stopPrint

int main()
{
    printf("'%c'", f30(3));
    return 0;
}
