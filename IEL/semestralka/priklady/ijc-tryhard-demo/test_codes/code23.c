#include <stdio.h>
#include <string.h>

// startPrint
// Jakou hodnotu vrátí funkce f23()?

char f23() {
    // p je pole 10 charů
    // p vypadá následovně:
    // p = { 'A', 'B', 'C', '\0', '\0', '\0', '\0', '\0', '\0', '\0' }
    char p[10] = "ABC";
    // s je pole 5 ukazatelů na char
    // s[0] je ukazatel na 'A'
    // s[1] je ukazatel na 'C'
    char *s[5] = {p, "CDEF"};
    // POZOR NA FUNKCI, STRCPY NENÍ STEJNÉ JAKO STRCAT
    // dereferencí s získáme ukazatel na 'A', přičtením dvojky se ukazatel posune na 'C'
    // strcpy udělá, že od ukazatele nahradí sekvenci v druhém parametru
    // p tedy bude "AB123"
    strcpy(*s + 2, "123");
    // to všechno je nám ale jedno, protože s je pole ukazatelů, takže s++ je nelegální operace
    // pole se totiž nedá přičítat jako ukazatel, takže se toto ani nepřeloží
    return *(*s++);
}

// stopPrint

int main()
{
    printf("compile");
    return 0;
}
