#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí f2(4)?

int f2(int x) {
    // s je typu static const int[4]
    static const int s[] = { 1, 2, 3, 4, };
    // p1 je ukazatel na const int (POZOR! NENÍ TO CONST POINTER) s + 4, takže o prvek za pole
    const int * p1 = s + x;
    // p2 je ukazatel na ukazatel na const int, který ukazuje na p1, který ukazuje o prvek za pole
    const int ** p2 = &p1;
    // dereference ukazatele p2 nás dostane k p1, který ukazuje na prvek za pole
    // od p1 odečteme dvojku, takže p1 začíná ukazovat na int 3
    (*p2) -= 2;
    // dvojitá dereference ukazatele p2 nás dostane přímo k hodnotě 3
    return **p2;
}

// stopPrint

int main()
{
    printf("%d", f2(4));
    return 0;
}
