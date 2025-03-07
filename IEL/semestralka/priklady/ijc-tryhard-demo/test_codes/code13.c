#include <stdio.h>
#include <string.h>

// startPrint
// Jakou hodnotu vrátí funkce f13()?

int f13() {
    // str vypadá takto:
    // str = {'A', 'B', 'C', 'D', '\0', '\0', '\0', '\0', '\0', '\0'}
    char str[10] = "ABCD";
    // s je pole ukazatelů na char
    // s[0] je ukazatel na 'A', s[1] je ukazatel na 'E'
    char *s[] = { str, "EFGH" };
    // POZOR NA FUNKCI, STRCAT NENÍ STEJNÉ JAKO STRCPY
    // dereferencí s získáme ukazatel na 'A'
    // strcat udělá, že najde první '\0' a nahradí od ní sekvenci v druhém parametru
    // str tedy bude "ABCD1234"
    strcat( *s + 2, "1234" );
    // opět dereference s dosaneme ukazatel na 'A', který posuneme o 3
    // správná odpověď je tedy 'D'
    return (*s)[3];
}

// stopPrint

int main()
{
    printf("'%c'", f13());
    return 0;
}
