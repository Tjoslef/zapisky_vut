#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí funkce main38()?

// static s je proměnná, která platí po celou dobu běžení programu
// to znamená, když se odečte s -= i, tak s zůstane se stejnou hodnotou i do dalšího zavolání funkce
static int f38(int i) {
    static int s = 10;
    int a = s + 3;
    s -= i;
    return a;
}

int main38() {
    f38(1);
    return f38(2);
}

// stopPrint

int main()
{
    printf("%d", main38());
    return 0;
}
