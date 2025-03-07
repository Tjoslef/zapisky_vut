#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí funkce f17()?

int f17() {
    // p je pole polí charů
    // p vypadá následovně:
    // p = { { 'A', 'B', 'C', '\0', '\0', '\0', '\0', '\0', '\0', '\0' },
    //       { 'D', 'E', 'F', '\0', '\0', '\0', '\0', '\0', '\0', '\0' } }
    char p[10][10] = { "ABC", "DEF", };
    // pole p[1] je ukazatel na 'D'
    // dereference ukazatele na 'D', dostaneme char 'D', což je správná odpověď
    return * p[1];
}

// stopPrint

int main()
{
    printf("'%c'", f17());
    return 0;
}
