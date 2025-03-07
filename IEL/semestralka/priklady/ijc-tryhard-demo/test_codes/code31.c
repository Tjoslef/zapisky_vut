#include <stdio.h>
#include <string.h>

// startPrint
// Jakou hodnotu vrátí funkce f31()?

int f31() {
    // str je pole charů
    // str vypadá následovně:
    // str = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', '\0' }
    char str[] = "ABCDEFGH";
    // s je pole 10 ukazatelů na char
    // s[0] je ukazatel na 'A'
    // sizeof se vyhodnotí na 9, takže str + sizeof bude ukazovat o prvek za pole str
    char *s[10] = { str, str + sizeof(str)};
    // POZOR NA FUNKCI, STRCPY NENÍ STEJNÉ JAKO STRCAT
    // dereferencí s získáme ukazatel na 'A', přičtením jedničky se ukazatel posune na 'B'
    // strcpy udělá, že od ukazatele nahradí sekvenci v druhém parametru
    // str tedy bude { 'A', '1', '2', '3', '4', '5', '6', 'H', '\0' }
    strcpy( *s + 1, "123456");
    // s[1] ukazuje o prvek za pole str, odečtením trojky posuneme ukazatel tak, že ukazuje na '6'
    // dereference ukazatele na '6' nám dá char '6'
    return * ( s[1] - 3 );
}

// stopPrint

int main()
{
    printf("'%c'", f31());
    return 0;
}
