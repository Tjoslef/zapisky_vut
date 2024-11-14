#include <stdio.h>
#include <stdlib.h>
typedef struct Svektor //deklarujeme datovy typ pro strukturu
{ //jmenem "Svektor" se dvema polozkami
int delka; //pocet polozek
int* pole; //dynamicky alokovane pole
} vektor; //jmeno tohoto typu je "vektor"
void vypisVektor (vektor * A){
for(int i = 0;i < A->delka;i++){
    printf("%i ",A->pole[i]);
    }
}
void pridejPosledni (vektor * A, int cislo){
int *temp = realloc(A->pole, (A->delka + 1) * sizeof(int));
if(temp == NULL){
    perror("realloc fail in pridejPosledni");
    return;
    }
A->pole = temp;
A->pole[A->delka] = cislo;
A->delka += 1;
}
void odeberPosledni(vektor *A){
if(A->delka == 0){
    return;

    }
A->delka -= 1;
A->pole = realloc(A->pole, A->delka * sizeof(int));
if(A->pole ==NULL && A->delka > 0){
    perror("fail of realloc in odeberPosledni");
    }

}
void odeberVsechny(vektor *A){
A->delka = 0;
free(A->pole);
A->pole = NULL;

}
void pridejPrvni(vektor *A,int cislo){
int *temp = realloc(A->pole, (A->delka + 1)* sizeof(int));
if(temp ==NULL){
    perror("fail of realloc in pridejPrvni");
    }
for(int i = A->delka - 1; i >= 0;i--){
    temp[i+1] = temp[i];

    }
temp[0] = cislo;
A->pole = temp;
A->delka +=1;


}
void odeberIndex(vektor *A,int index){
if(index < 0 || index >= A->delka){
    perror("wrong index");
    return;

    }
for(int i =0;i< A->delka -1;i++){
    A->pole[i] = A->pole[i+1];
    }
int *temp = realloc(A->pole,(A->delka - 1)*sizeof(int));
if(temp == NULL && A->delka -1 > 0){
    perror("fail of realloc in odeberPosledni");
    return;
    }

A-> pole =temp;
A-> delka -=1;
}
int main() //zacatek programu
{ //"A" je automaticky alokovany vektor obsahujici dynamicky alokovane pole
vektor A = {0, NULL}; vypisVektor(&A); //vytvarime vektor
pridejPosledni(&A, 10); vypisVektor(&A); //pridavame posledni prvek
pridejPosledni(&A, 20); vypisVektor(&A); //pridavame posledni prvek
pridejPosledni(&A, 30); vypisVektor(&A); //pridavame posledni prvek
odeberPosledni(&A); vypisVektor(&A); //odebirame posledni prvek
odeberVsechny(&A); vypisVektor(&A); //odebirame vsechny prvky
odeberPosledni(&A); vypisVektor(&A); //odebirame neexistujici prvek
pridejPrvni(&A, 40); vypisVektor(&A); //pridavame prvni prvek
pridejPrvni(&A, 50); vypisVektor(&A); //pridavame prvni prvek
pridejPrvni(&A, 60); vypisVektor(&A); //pridavame prvni prvek
odeberIndex(&A, -1); vypisVektor(&A); //odebirame neexistujici prvek
odeberIndex(&A, 3); vypisVektor(&A); //odebirame neexistujici prvek
odeberIndex(&A, 1); vypisVektor(&A); //odebirame konkretni prvek
odeberVsechny(&A); vypisVektor(&A); //odebirame vsechny prvky
return 0; //konec programu
}
