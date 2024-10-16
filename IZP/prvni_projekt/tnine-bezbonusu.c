#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    char jmeno[50];
    char telefon[15];
} seznamSave;
int main(int argc, char *argv[]) {
    bool findMatch = false;
    if(argc < 2){
    findMatch = true;
     char namePrint[100];
     char numberPrint[100];
        while(fgets(namePrint,sizeof(namePrint),stdin) != NULL){
            namePrint[strcspn(namePrint,"\n")] = '\0';
            if(fgets(numberPrint,sizeof(numberPrint),stdin) != NULL){
            numberPrint[strcspn(numberPrint,"\n")] = '\0';
            printf("%s, %s\n",namePrint,numberPrint);
            }


        }
    return 0;
    }
    char *ifItNumber = argv[1];
    if (argc > 2) {
    fprintf(stderr, "Your argument contains\n");
    return 1;
}
    if (strlen(ifItNumber) > 9) {
        fprintf(stderr,"Too many numbers\n");
        return 0;
    }

    for (int i = 0; ifItNumber[i] != '\0'; i++) {
        if (!isdigit(ifItNumber[i])) {
            fprintf(stderr,"Your argument is not a number\n");
            return 1;
        }
    }
    int delkacisla = strlen(ifItNumber);
    int ZadaneCislo[delkacisla];
    for (int i = 0; ifItNumber[i] != '\0'; i++) {
        ZadaneCislo[i] = ifItNumber[i] - '0';
    }

    char *keys[] = {
        "+",        // 0
        "",         // 1
        "abc",      // 2
        "def",      // 3
        "ghi",      // 4
        "jkl",      // 5
        "mno",      // 6
        "pqrs",     // 7
        "tuv",      // 8
        "wxyz"      // 9
    };

    char seznam[256];
    int radiciCIslo = 0;

    while (fgets(seznam, sizeof(seznam), stdin) != NULL) {
        seznamSave list;
        seznam[strcspn(seznam, "\n")] = '\0';

        if (strlen(seznam) == 0) {
            printf("Your seznam file is empty\n");
            return 0;
        }

        if (radiciCIslo % 2 == 0) {
            strcpy(list.jmeno, seznam);
        } else {
            strcpy(list.telefon, seznam);
            bool matchCislo = false;
            bool matchJmeno = false;
           int telefon_len = strlen(list.telefon);
            for(int start = 0; start <= telefon_len - delkacisla;start++){
            int i;
                for(i = 0; i < delkacisla; i++){
                    if(ZadaneCislo[i] == 0){
                    continue;
                    }
                if(ZadaneCislo[i] != (list.telefon[start + i] - '0')){
                        break;

                    }


                }
            if(i == delkacisla){
                    matchCislo = true;
                    break;
                    }


            }
            int jmeno_len = strlen(list.jmeno);
            for (int start = 0; start <= jmeno_len - delkacisla; start++) {
            int i;
                for (i = 0; i < delkacisla; i++) {
                    if (i == 0) {
                        continue;
                        }
                    char *tlacitko = keys[ZadaneCislo[i]];
                    if (!strchr(tlacitko, tolower(list.jmeno[start + i]))) {
                        break;
                    }
                }

                if (i == delkacisla) {
                matchJmeno = true;
                break;
                }
            }

            if (matchCislo == true || matchJmeno == true) {
                findMatch = true;
                printf("%s, %s\n", list.jmeno, list.telefon);
            }
        }
        radiciCIslo++;
    }
    if(!(findMatch)){
        printf("Not found\n");
    }
    return 0;
}

