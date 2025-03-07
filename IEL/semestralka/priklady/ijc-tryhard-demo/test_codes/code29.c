#include <stdio.h>
#include <string.h>

// startPrint
// Jakou hodnotu vrátí funkce f29()?

int f29() {
    // s je pole polí charů
    // s vypadá následovně:
    // s = { { '1', '2', '3', '4', '5', '\0', '\0', '\0', '\0', '\0' },
    //       { '5', '4', '3', '2', '1', '\0', '\0', '\0', '\0', '\0' },
    //       { 'a', 'b', 'c', '\0', '\0', '\0', '\0', '\0', '\0', '\0'} }
    const char s[10][10] = { "12345", "54321", "abc" };
    // strlen vrátí číselnou délku pole od daného ukazatele až po první '\0'
    // *(s+1) je to stejné co s[1]
    // s[1] je ukazatel na '5', přičtením trojky dostaneme ukazatel na '2'
    // strlen tedy vrací délku "21", což je 2
    return strlen( *(s+1)+3 );
}

// stopPrint

int main()
{
    printf("%d", f29());
    return 0;
}
