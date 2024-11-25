#include <string.h>
#include <stdio.h>
typedef struct Sosoba { //struktura "Sosoba"
char jmeno[10]; //pole znaku "jmeno"
int vek; //cele cislo "vek"
} osoba; //datovy typ "osoba"
void vypis(int delka, osoba pole[]);
int porovnej (osoba A, osoba B){
    int copm_jmeno = strcmp(A.jmeno, B.jmeno);
   if(copm_jmeno < 0){
        return -1;
    }else if (copm_jmeno > 0) {
        return 1;
    }else {
        if(A.vek < B.vek){
            return -1;
        }else if(A.vek > B.vek){
            return 1;
        }else{
            return 0;
        }
    }
}
void vymen(osoba* A, osoba* B){
    osoba temp;
    temp = *A;
    *A = *B;
    *B = temp;
}
int nejmensi (int delka, osoba pole[]){
    osoba nejmensiO;
    nejmensiO = pole[0];
    int nej_index = 0;
    for(int i = 1;i < delka;i++){
        if(porovnej(pole[i],nejmensiO) < 0){
            nejmensiO = pole[i];
            nej_index = i;
        }
    }
    return nej_index;
}
void serad(int delka, osoba pole[]){
    int i,j,minimum;
    for(i = 0; i < delka - 1;i++){
        minimum = i;
        for(j = i + 1;j< delka;j++){
            if(porovnej(pole[j], pole[minimum]) < 0){
                minimum = j;
            }
        }

    if(minimum != i){
    vymen(&pole[i],&pole[minimum]);
    }
}
}

int main()
{ //neserazene pole sosob
osoba pole[5] ={{"Bob", 23},{"Cecil", 23},{"Bob", 22},{"Alice", 24},{"Daniela",21}};
vypis(5, pole); //vypis pole
if (porovnej(pole[0], pole[1])<0) printf("Ruzna jmena (0,1) OK\n"); //test funkce porovnej
if (porovnej(pole[0], pole[2])>0) printf("Ruzny vek (0,2) OK\n"); //test funkce porovnej
vymen(&pole[0], &pole[4]); //vymena dvou osob
vypis(5, pole); //vypis pole
if (porovnej(pole[0], pole[4])>0) printf("Vymena osob (0,4) OK\n"); //test funkce vymen
if (nejmensi(5, pole) ==3) printf ("Nejmensi osoba (3) OK\n"); //test funkce nejmensi
serad(5, pole); //test funkce serad
vypis(5, pole); //vypis pole
return 0;
}
void vypis(int delka, osoba pole[]) //definice funkce "vypis"
{
for(int i =0; i < delka; i++) //pro vsechny prvky pole
    printf ("(%s %i) ", pole[i].jmeno, pole[i].vek); //vypis jmeno a vek
printf ("\n"); //vypis konec radku
}
