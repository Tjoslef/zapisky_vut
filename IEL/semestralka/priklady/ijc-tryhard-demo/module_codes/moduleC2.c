// startPrint
// extern znamená, že proměnná x je někde definovaná, tak ať si pro ni udělá místo
extern int x;

int mainC() {
    // víme, že x je definovaná v jiném modulu, takže ji můžeme použít
    // vrátíme hodnotu x z modulu C1, tedy 55
    return x;
}
// stopPrint

int main()
{
    printf("%d", mainC());
    return 0;
}
