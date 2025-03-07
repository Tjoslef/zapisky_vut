#include <stdio.h>

// startPrint
// Jakou hodnotu vrátí funkce f()?

// static s je proměnná, která platí po celou dobu běžení programu
// to znamená, když se přičte s += i, tak s zůstane se stejnou hodnotou i do dalšího zavolání funkce
static int f40(int i) {
    static int s = 5;
    int a = s + 5;
    s += i;
    return a;
}

int main40() {
    return f40(2), f40(1);
}

// stopPrint

int main()
{
    printf("%d", main40());
    return 0;
}
