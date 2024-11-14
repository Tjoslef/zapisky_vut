#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char jmeno[50];
    char telefon[15];
} seznamSave;
int main(int argc, char *argv[]) {
    bool specialSearch = false;
    bool findMatch = false;
    if(argc < 2){
    //checking if there isnt any argument and printing it all
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
    int input_lenght_B = 0;
    char *ifItNumber = argv[1];
    char *bonus = NULL;
    //checking for -s for bonus
    if (argc >= 2 && ifItNumber[0] == '-' && ifItNumber[1] == 's') {
        bonus = argv[2];
        input_lenght_B = strlen(bonus);
        specialSearch = true;
    }
    //checking if there is correct amount of numbers
    if (strlen(ifItNumber) > 9 || input_lenght_B > 9) {
        fprintf(stderr,"Too many numbers\n");
        return 0;
    }
    //error handling for too many argument
     if (argc > 2 && !specialSearch) {
    fprintf(stderr, "Your argument contains spaces\n");
    return 1;
    }
    int lenght_number = strlen(ifItNumber);
    int inputNumber[lenght_number];
    int input_bonus[input_lenght_B];
    //bonus error handling and converting to integer(maybe not nessecery needed)
   if (specialSearch) {
    if (bonus == NULL) {
        fprintf(stderr, "No number provided after '-s'\n");
        return 1;
    }

    input_lenght_B = strlen(bonus);
    for (int i = 0; i < input_lenght_B; i++) {
        if (!isdigit(bonus[i])) {
            fprintf(stderr, "Your argument is not a number\n");
            return 1;
        } else {
            input_bonus[i] = bonus[i] - '0';
        }
    }

}else{
        //normal cases
        for (int i = 0; i < lenght_number; i++) {
        if (!isdigit(ifItNumber[i])) {
            fprintf(stderr,"Your argument is not a number\n");
            return 1;
        }else{
            inputNumber[i] = ifItNumber[i] - '0';
            }

    }

       }
    //"keybinding"
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
    int radiciCIslo = 0; //because first is always coming the name so
    //even numbers are for name and even are for number
    //start of reading from input
    while (fgets(seznam, sizeof(seznam), stdin) != NULL) {
        //my struct
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
            bool matchNumber = false;
            bool matchName = false;
           int telefon_len = strlen(list.telefon);
           int jmeno_len = strlen(list.jmeno);
            if(!specialSearch){
                //we dont have to loop thought whole list.telefon becasue we know the
                //the lenght of sequence that we are looking for
                for(int start = 0; start <= telefon_len - lenght_number;start++){
                int i;
                    for(i = 0; i < lenght_number; i++){
                        //looping thougth argument number
                        if(inputNumber[i] == 0){
                        //because 0 is "+" so we can skip it
                        continue;
                        }
                        //the "moving window" if is not THE character it will break
                        //and i value reset and the out side loop moved forward
                        //and the start + 1

                        if(inputNumber[i] != (list.telefon[start + i] - '0')){
                        break;

                        }
                    }
                //and if we find that i = lenght_number which mean that we found
                    //sequence of numbers that matched
                if(i == lenght_number){

                    matchNumber = true;
                    break;
                    }
            }
                for (int start = 0; start <= jmeno_len - lenght_number; start++) {
                    int i;
                    for (i = 0; i < lenght_number; i++) {
                        if (i == 0) {
                        continue;
                        }
                        char *button = keys[inputNumber[i]];
                        //moving window with strchr command which return true
                        //for first match in string(keybinding)
                        if (!strchr(button, tolower(list.jmeno[start + i]))) {
                            break;
                        }
                    }
                    if (i == lenght_number) {
                    matchName = true;
                    break;
                    }
                }
            }
            //bonus
            if(specialSearch){
                int matchSpecialL = 0;
                int leftSortL = 0;
                //moving window with watching position so every another
                //number in sequence is bigger
                for(int number = 0; number < input_lenght_B; number ++){
                    for(int i = 0; i < jmeno_len;i++){
                        char *button = keys[input_bonus[number]];
                        if(strchr(button, tolower(list.jmeno[i])) && i > leftSortL){
                            leftSortL = i;
                            matchSpecialL++;
                            break;

                        }
                    }
                }
            if(matchSpecialL == input_lenght_B){
                matchName = true;

                }
            int matchSpecialN = 0;
            int sequence_number = 0;
            //moving window so every another window from the match is smaller
                //window from left side
            for(int number = 0; number < input_lenght_B;number ++){
                    bool found_M_N = false;
                for(int i = sequence_number; i < telefon_len; i++){
                    printf("%i compare %i \n",input_bonus[number],list.telefon[i] - '0');
                   if(input_bonus[number] == list.telefon[i] - '0'){
                            found_M_N = true;
                            sequence_number = i + 1;
                            matchSpecialN ++;
                            break;
                        }
                    }
                     if(!found_M_N){
                            break;
                        }

                }
            if(matchSpecialN == input_lenght_B){
                matchNumber = true;
                }
            }
            if (matchNumber == true || matchName == true) {
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
