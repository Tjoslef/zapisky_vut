#include <stdio.h>
#include <string.h>

// startPrint
// Jakou hodnotu vrátí funkce f14()?

int f14() {
    // str vypadá takto:
    // str = {'A', 'B', 'C', 'D', '\0', '\0', '\0', '\0', '\0', '\0'}
    static char str[10] = "ABCD";
    // s je pole ukazatelů na char
    // s[0] je ukazatel na 'A', s[1] je ukazatel na 'E'
    char *s[10] = { str, "EFGH" };
    // POZOR NA FUNKCI, STRCPY NENÍ STEJNÉ JAKO STRCAT
    // dereferencí s získáme ukazatel na 'A'
    // strcpy udělá, že od ukazatele nahradí sekvencí v druhém parametru
    // str tedy bude "AB1234"
    strcpy((*s) + 2, "1234");
    // opět dereference s dosaneme ukazatel na 'A', který posuneme o 5
    // správná odpověď je tedy '4'
    return ( (*s)++ )[5];
}

// stopPrint

int main()
{
    printf("'%c'", f14());
    return 0;
}
