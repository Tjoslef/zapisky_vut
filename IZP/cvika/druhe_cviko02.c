#include <stdio.h>
int main(){
float pole[5];
float pomocC = 0.0;
float pomocC2 = 0.0;
int vysledek2 = 0;
for(int i = 0; i < 5;i++){
    printf("dej mi cislo:");
    scanf("%f",&pole[i]);
    }
for(int i = 4; i >= 0; i--){
    printf("pozadu: %0.1f: \n",pole[i]);
    }
for(int i = 0;i < 5; i++){
   if(pole[i] >= pomocC){
        pomocC = pole[i];
        }
    if(i == 0){
        pomocC2 = pole[i];
        vysledek2 = i;
    }else if (pole[i] >= pomocC2) {
        pomocC2 = pole[i];
        vysledek2 = i;
    }
    }
printf("Hodnota maxima je: %0.1f \n",pomocC);
printf("Index minima je: %d \n",vysledek2 );




}
