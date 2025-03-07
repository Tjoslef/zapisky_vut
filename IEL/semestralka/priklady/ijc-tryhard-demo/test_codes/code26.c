#include <stdio.h>
#include <string.h>

// startPrint
// Jakou hodnotu vrátí funkce f26()?

int f26() {
    // s je pole polí charů
    // s vypadá následovně:
    // s = { { '1', '2', '3', '4', '5', '\0' },
    //       { 'A', 'B', 'C', 'D', 'E', '\0' } }
    static const char s[][10] = { "12345", "ABCDE", };
    // strlen vrátí číselnou délku pole od daného ukazatele až po první '\0'
    // strlen tedy vrací délku "CDE", což je 3
    return strlen( s[1] + 2 );
}

// stopPrint

int main()
{
    printf("%d", f26());
    return 0;
}
