#include <math.h>
#include <stdio.h>


typedef struct{
    float x;
    float y;
}bod;
float pocitaniVzdalenosti(bod prvniB,bod druhyB){
    float vzdalenost = sqrt((prvniB.x -druhyB.x)* (prvniB.x - druhyB.x) + (prvniB.y - druhyB.y ) * (prvniB.y - druhyB.y));
    return vzdalenost;

}
float prumernaVzdalenost(int num,bod M[]){
    float celkovaVzdalenost = 0.0;
    int pocetScitani = 0;
    for(int i=0; i< num;i++){
        for(int j = i+ 1; j < num;j++){
            celkovaVzdalenost += pocitaniVzdalenosti(M[i],M[j]);
            pocetScitani ++;
        }

    }
 return celkovaVzdalenost / pocetScitani;
}
void stredMnoziny(int num,bod M[], bod *stred){
    float celkoveX = 0.0;
    float celkoveY = 0.0;
    for(int i =0; i < num; i++){
        celkoveX += M[i].x;
        celkoveY += M[i].y;
    }
    stred -> x = celkoveX / num;
    stred -> y = celkoveY / num;
}
bod *nejblizsiBod(int num, bod M[], bod stred){
    float porovnani = pocitaniVzdalenosti(stred, M[0]);
    bod * vysledek = &M[0];
    for(int i = 1; i < num; i++){
        float x = pocitaniVzdalenosti(stred, M[i]);
        if(x < porovnani){
            porovnani = x;
           vysledek = &M[i];
        }
    }
    return vysledek;

}
int main(){
    bod M[4]; // pole ctyr bodu "M" ( mnozina )
    for (int i = 0; i < 4; i++){ // pro vsechny prvky pole
        scanf("%f %f", &M[i].x, &M[i].y); // nacitame souradnice bodu
    }
    float d = prumernaVzdalenost (4, M); // pocitame vzdalenost
    printf (" Prumerna vzdalenost je %f\n", d);

    bod S; // bod "S" (stred)
    stredMnoziny (4, M, &S); // pocitame souradnice stredu
    printf (" souradnice stredu (%.2f, %.2f)\n", S.x, S.y);

    bod* N = nejblizsiBod (4, M, S); // zjistujeme neblizsi bod
    printf (" Nejblizsi prvek je (%.2f, %.2f)\n", N->x, N->y);
    return 0;


}
