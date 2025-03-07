#include <stdio.h>

// startPrint
// Jaký je výsledek výrazu:

char f3() {
    // při překladu se string literály spojí dohromady a stane se z nich ukazatel na 'A'
    // k ukazateli na 'A' přičteme 4, takže posuneme ukazatel na 'E'
    // dereference ukazatele na 'E' nás dostane k charu 'E'
    return * ("ABCD" "EFGH" + 4);
}

// stopPrint

int main()
{
    printf("'%c'", f3());
    return 0;
}
