#include <stdio.h>
int main(){
int list_roku[100] = {0};
int clen = 0;
int pocet_mladiskych = 0;
while (clen < 100){
    printf("zadej rok:");
    scanf("%d",&list_roku[clen]);
        if(list_roku[clen] == 0){
            break;
        }
    clen ++;
    }
for(int i = 0;i  < clen; i++){
    if((2024 - list_roku[i]) < 18){
        pocet_mladiskych ++;
        }
    }
printf("pocet mladiskych %d \n",pocet_mladiskych);
}
