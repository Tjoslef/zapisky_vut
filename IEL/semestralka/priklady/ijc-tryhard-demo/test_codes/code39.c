#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí funkce main39()?

// static s je proměnná, která platí po celou dobu běžení programu
// to znamená, když se odečte s -= i, tak s zůstane se stejnou hodnotou i do dalšího zavolání funkce
static int f39(int i) {
    static int s = 4;
    int a = s + 3;
    s -= i;
    return a;
}

int main39() {
    f39(2);
    return f39(1);
}

// stopPrint

int main()
{
    printf("%d", main39());
    return 0;
}
