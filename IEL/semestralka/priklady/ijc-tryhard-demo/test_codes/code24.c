#include <stdio.h>
#include <string.h>

// startPrint
// Jakou hodnotu vrátí funkce f24()?

int f24() {
    // str je pole 10 charů
    // str vypadá následovně:
    // str = { 'A', 'B', 'C', 'D', '\0', '\0', '\0', '\0', '\0', '\0' }
    char str[10] = "ABCD";
    // s je pole 10 ukazatelů na char
    // s[0] je ukazatel na 'A'
    // s[1] je ukazatel na 'E'
    char *s[10] = { str, "EFGH" };
    // POZOR NA FUNKCI, STRCPY NENÍ STEJNÉ JAKO STRCAT
    // dereferencí s získáme ukazatel na 'A', přičtením dvojky se ukazatel posune na '\0'
    // strcpy udělá, že od ukazatele nahradí sekvenci v druhém parametru
    // str tedy bude "ABCDIJKL"
    strcpy( *s + 4, "IJKL" );
    // to všechno je nám ale jedno, protože s je pole ukazatelů, takže s++ je nelegální operace
    // pole se totiž nedá přičítat jako ukazatel, takže se toto ani nepřeloží
    return * ( * s++ );
}

// stopPrint

int main()
{
    printf("compile");
    return 0;
}
