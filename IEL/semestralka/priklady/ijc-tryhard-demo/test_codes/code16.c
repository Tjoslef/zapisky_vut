#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí funkce f16(4)?

static int f16(int i) {
    // pole vypadá následovně:
    // pole = { 'A', 'B', 'C', 'D', 'E', 'F', '\0' }
    static char pole[] = "ABCDEF";
    // sizeof se vyhodnotí na 7 (počítá se aji '\0')
    // p1 je ukazatel na char, bude ukazovat o prvek za pole
    char *p1 = pole + sizeof(pole);
    // p2 je ukazatel na ukazatel na char, který ukazuje na char, který ukazuje o prvek za pole
    char **p2 = &p1;
    // dereference ukazatele p2 nás dostane k p1, který ukazuje o prvek za pole
    // od p1 odečteme 4, takže p1 začíná ukazovat na char 'D'
    (*p2) -= i;
    // dvojitá dereference ukazatele p2 nás dostane přímo k charu 'D'
    return **p2;
}

// stopPrint

int main()
{
    printf("'%c'", f16(4));
    return 0;
}
