#include <stdio.h>

// startPrint
// Jakou hodnotu má výraz:

char f9() {
    // při překladu se string literály spojí dohromady a stane se z nich ukazatel na '0'
    // k ukazateli na '0' přičteme 5 - 1 = 4, takže posuneme ukazatel na '\0'
    // dereference nám z ukazatele na '\0' udělá jenom char '\0', což je správná odpověď
    return * ( "01" "23" + 5 - 1 );
}

// stopPrint

int main()
{
    printf("null byte");
    return 0;
}
