#include <stdio.h>
#include <string.h>

// startPrint
// Jakou hodnotu vrátí funkce f1()

int f1(void) {
    // str je typu char[9]
    char str[] = "ABCDEFGH";
    // s je pole 10 ukazatelů na char, s[0] drží ukazatel na 'A'
    // sizeof se vyhodnotí na 9 (počítá se aji '\0')
    // s[1] ukazuje o jeden prvek za '\0' (mimo pole)
    char *s[10] = { str, str + sizeof(str) };
    // první se vyhodnotí *s, takže ukazatel na 'A', který se přičte o jedna, takže ukazatel na 'B'
    // strcpy vloží od 'B' včetně znaky "123456"
    // str bude { 'A', '1', '2', '3', '4', '5', '6', '\0', '\0', '\0' }
    strcpy( *s + 1, "123456" );
    // s[1] ukazuje na poslední '\0' v poli str, tedy nás zajímá hodnota na kterou ukazuje - 3, což je ukazatel na '6'
    // provede se dereference, díky které dostaneme samostatný char '6'
    return * ( s[1] - 3 );
}

// stopPrint

int main()
{
    printf("'%c'", f1());
    return 0;
}
