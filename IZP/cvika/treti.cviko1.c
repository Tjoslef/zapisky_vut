#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc,char* argv[10]){
    if (argc < 3) {
        printf("Chyba: Nedostatek argumentů. Zadejte příkaz a argument.\n");
        return 1;
    }
char *prikaz = argv[1];
char argument_2[11];
strncpy(argument_2, argv[2], 10);
argument_2[10] = '\0';
char prvni_Pr[] = "tolower";
char druhy_Pr[] = "notalnum";
char treti_Pr[] = "palindrom";
char pouzeZnak[100];
int index = 0;
int jetoPal = 0;
if(strcmp(prikaz,prvni_Pr ) == 0){
    for(int i = 0; argument_2[i] != '\0';i++){
        if(argument_2[i] >='A' &&  argument_2[i] <= 'Z'){
            argument_2[i] = argument_2[i] + 32;
            }

        }
printf("%s novy male pismena\n",argument_2);
    }else if (strcmp(prikaz, druhy_Pr) == 0) {
        for (int i = 0; argument_2[i] != '\0'; i++) {
            // Opravená podmínka
            if (!(isdigit(argument_2[i]) || isalpha(argument_2[i]))) {
                pouzeZnak[index] = argument_2[i];
                index++;
            }
        }
        pouzeZnak[index] = '\0';  // Ukončit řetězec
        printf("%s - pouze nealfanumerické znaky\n", pouzeZnak);
    }else if (strcmp(prikaz, treti_Pr) == 0) {
        int prvni_index = 0;
        int posledni_index = strlen(argument_2) - 1;
        while(prvni_index < posledni_index){
        if(!(argument_2[prvni_index] == argument_2[posledni_index])){
            jetoPal = 1;
            printf("%s neni palindrom\n",argument_2);
            break;

            }
        prvni_index++;
        posledni_index--;

        }
        if(jetoPal == 0){
        printf("%s je to palindrom\n",argument_2);
        }
    }
return 0;


}
