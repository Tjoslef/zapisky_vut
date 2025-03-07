#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí funkce f32(4)?

int f32(int x) {
    // s ukazuje na 1
    static const int s[] = { 1, 2, 3, 4, };
    // p1 je ukazatel na int, bude ukazovat o prvek za pole s
    const int * p1 = s + x;
    // p2 je ukazatel na ukazatel na int, který ukazuje na int, který ukazuje o prvek za pole
    const int ** p2 = &p1;
    // dereference ukazatele p2 nás dostane k p1, který ukazuje o prvek za pole
    // od p1 odečteme 2, takže p1 začíná ukazovat na 3
    (*p2) -= 2;
    // dvojitá dereference ukazatele p2 nás dostane přímo k intu 3
    return **p2;
}

// stopPrint

int main()
{
    printf("%d", f32(4));
    return 0;
}
