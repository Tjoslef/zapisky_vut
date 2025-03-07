// startPrint
// extern znamená, že proměnná x je někde definovaná, tak ať si pro ni udělá místo
extern int x;

int mainB() {
    // vracíme proměnnou y, ale o ní nevíme nic
    // není deklarovaná ani není extern do jiného modulu
    // tento program tedy nelze zkompilovat
    return y;
}
// stopPrint

int main()
{
    printf("%d", mainB());
    return 0;
}
