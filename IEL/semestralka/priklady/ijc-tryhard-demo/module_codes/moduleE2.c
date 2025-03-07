// startPrint
// extern znamená, že proměnná x je někde definovaná, tak ať si pro ni udělá místo
extern int x;
// static znamená něco jako private, tzn. že proměnná x je viditelná jen v tomto modulu
// ještě k tomu je globální, takže je nulovaná
static int y;

int mainE() {
    // x je definované někde jinde, a našli jsme ji v druhém modulu, její hodnota je 34
    // y je definované v tomto modulu jako 0, je private pro tento modul, takže hodnota y z prvního nás nezajímá
    // vrátí se hodnota 34 + 0 = 34
    return x + y;
}
// stopPrint

int main()
{
    printf("%d", mainE());
    return 0;
}
