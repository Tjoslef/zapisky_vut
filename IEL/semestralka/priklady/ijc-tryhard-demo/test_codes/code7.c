#include <stdio.h>

// startPrint
// Jaký je typ a výsledek výrazu:

char *f7() {
    // při překladu se string literály spojí dohromady a stane se z nich ukazatel na '1'
    // k ukazateli na '1' přičteme 6, takže posuneme ukazatel na '\0'
    // správná odpověď je tedy ukazatel na char '\0'
    return ( "123" "456" + 6 );
}

// stopPrint

int main()
{
    printf("ukazatel na char null byte");
    return 0;
}
