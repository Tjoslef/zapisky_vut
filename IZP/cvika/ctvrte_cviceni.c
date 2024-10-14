#include <stdio.h>
# include <stdbool.h>
bool jeVMnozina(int delka,int pole[],int prvek){
    for(int i =0; i < delka;i++){
    if(pole[i] == prvek){
        return true;
        }
    }
return false;
    }
bool jeMnozina(int delka,int pole[]){
    for(int i =0; i< delka;i++){
        for(int j =i+1; j < delka;j++){
            if(pole[j] == pole[i]){
                return false;
            }
        }
    }
  return  true;
}
void vypisPrunik(int delkaA,int poleA[],int delkaB,int poleB[]){
bool prunik = false;
for(int i = 0;i < delkaA; i++){
    for(int j = 0; j < (delkaB);j++){
    if(poleA[i] == poleB[j]){
    printf("%i ",poleA[i]);
    prunik = true;

    }
    }

    }

if(!prunik){
    printf("bez pruniku");

    }
}
void sjednoceniMn(int delkaA,int poleA[],int delkaB,int poleB[]){
bool duplicita = false;
for(int i = 0;i< delkaA;i++){
    printf(" %i ",poleA[i]);
    }
for(int j =0;j < delkaB;j++){
        duplicita = false;
        for(int i =0;i < delkaA;i++){
            if(poleA[i] == poleB[j]){
                duplicita = true;
                break;
            }
            }
        if(!duplicita){
            printf(" %i ",poleB[j]);
        }

}
printf("\n");
}
int main(){
int A[] = {1,2,3,4,5,6};
int B[] = {4,5,6,7,8,9,10};
int delkaA = sizeof(A) / sizeof(A[0]);
int delkaB = sizeof(B) / sizeof(B[0]);
if (jeMnozina(delkaA, A) == true && jeMnozina(delkaB, B) == true) {

    printf("prunik mnozin: \n");
    vypisPrunik(delkaA, A, delkaB, B);
    printf("\n");
    printf("sjednoceni  mnozin: \n");
    sjednoceniMn(delkaA, A, delkaB, B);
}
int x = 10;
if(jeVMnozina(delkaA,A,x) ==true){
    printf("%d je v mnozine \n",x );
    }else {
    printf("%d neni v mnozine \n",x);
    }


}
