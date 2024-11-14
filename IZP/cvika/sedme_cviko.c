#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Smnozina{
    int delka;
    int *pole;


}mnozina;
mnozina * alokujMnozinu(int delka){
    mnozina *m = malloc(sizeof(mnozina));
    if(m == NULL){
        return NULL;
    }
    m->delka = delka;
    m-> pole = malloc(delka * sizeof(int));
    if(m->pole == NULL){
        free(m);
        return NULL;

    }
    return m;
}
void nactiMnozinu(mnozina *A){
for(int i =0;i < A->delka;i++){
    scanf("%d",&A->pole[i]);
    }

}
void vypisMnozinu(mnozina *A){
for (int i = 0; i < A->delka; i++) {
    printf(" %d ",A->pole[i]);
}
}
bool jeMnozina(mnozina *A){
    for(int i = 0;i < A->delka;i++){
        for(int j = i + 1; j < A->delka;j++){
            if(A->pole[i] == A-> pole[j]){
                return false;
                }

            }

        }
    return true;
    }
mnozina *konkatenaceMnozin(mnozina *A, mnozina *B){
    mnozina *vysledek = malloc(sizeof(mnozina));
    if(vysledek == NULL){
        return NULL;
    }
    vysledek->delka = A->delka + B->delka;
    vysledek->pole = malloc(vysledek->delka * sizeof(int));
    if(vysledek->pole == NULL){
        free(vysledek);
        return NULL;
        }
    for(int i = 0;i < A->delka;i++){
        vysledek->pole[i] = A->pole[i];

        }
    for(int i = 0;i < B->delka;i++){
        vysledek->pole[A->delka +i] = B->pole[i];
        }
    return vysledek;
}
mnozina *prunikMnozin(mnozina *A, mnozina *B){
    mnozina *prunik = malloc(sizeof(mnozina));
    if(prunik ==NULL){
        return NULL;
    }
    prunik->delka = A->delka;
    prunik->pole = malloc(prunik->delka * sizeof(int));
    if(prunik-> pole == NULL){
        free(prunik);
        return NULL;
    }
    int index = 0;
    for(int i = 0; i < A->delka; i++){
        for (int j = 0; j < B->delka;j++) {
            if(A->pole[i] == B->pole[j]){
                prunik->pole[index] = A->pole[i];
                index++;
                break;
            }
        }
    }
    prunik->delka = index;
    prunik->pole = realloc(prunik->pole, prunik->delka * sizeof(int));
    return prunik;
}
void uvolniMnozinu(mnozina *A){
    free(A->pole);
    free(A);
}
int main() { // ve VSCode formatovani spravime zkratkou "Shift + Alt + F"
mnozina *A =alokujMnozinu(4); // alokujeme mnozinu A (a jeji pole)
mnozina *B =alokujMnozinu(3); // alokujeme mnozinu B (a jeji pole)
if (A == NULL ||A->pole ==NULL ||B ==NULL ||B->pole ==NULL) {// osetreni alokace
printf ("Alokace selhala\n"); return 1;}
nactiMnozinu(A); // do mnoziny A nacitame vstup
nactiMnozinu(B); // do mnoziny B nacitame vstup
printf ("Mnozina A:\n"); vypisMnozinu(A); // vypisujeme mnozinu A
printf ("Mnozina B:\n"); vypisMnozinu(B); // vypisujeme mnozinu A
if (!jeMnozina(A) ||!jeMnozina(B)) { // osetreni vstupu
printf ("Zadana pole nejsou mnozinami\n"); return 2;}
printf ("Zadana pole jsou mnozinami\n");
mnozina *C =konkatenaceMnozin(A, B); // C je konkatenaci A a B
if (C == NULL ||C->pole ==NULL) { // osetreni alokace
printf ("Alokace konkatenace selhala\n"); return 3;}
printf ("Konkatenace:\n"); vypisMnozinu(C); // vypisujeme mnozinu C
uvolniMnozinu(C); // uvolnujeme mnozinu C
C = prunikMnozin(A, B); // C je prunikem A a B
if (C == NULL ||C->pole ==NULL) { // osetreni alokace
printf ("Alokace pruniku selhala\n"); return 4;}
printf ("Prunik:\n"); vypisMnozinu(C); // vypisujeme mnozinu C
uvolniMnozinu(C); uvolniMnozinu(B); uvolniMnozinu(A); // uvolnujeme mnoziny
return 0;
}
