// startPrint
// static znamená něco jako private, tzn. že proměnná x je viditelná jen v tomto modulu
// ještě k tomu je globální, takže je nulovaná
// bohužel je tu static, takže ta v druhém modulu není vidět
static int x;
// extern znamená, že proměnná y je někde definovaná, tak ať si pro ni udělá místo
extern int y;
// stopPrint
