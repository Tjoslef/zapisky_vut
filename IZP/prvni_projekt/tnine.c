#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char jmeno[100];
    char telefon[100];
} seznamSave;
int main(int argc, char *argv[]) {
    bool specialSearch = false;
    bool findMatch = false;
    if(argc < 2){
        seznamSave list;
    //checking if there isnt any argument and printing it all
        while(fgets(list.jmeno,sizeof(list.jmeno),stdin) != NULL){
            list.jmeno[strcspn(list.jmeno,"\n")] = '\0';
            if(fgets(list.telefon,sizeof(list.telefon),stdin) != NULL){
                list.telefon[strcspn(list.telefon,"\n")] = '\0';
                printf("%s, %s\n",list.jmeno,list.telefon);
            }


        }
    return 0;
    }

    int input_lenght_B = 0;
    //the input that we will match
    char *ifItNumber = argv[1];
    char *bonus = NULL;
    //checking for -s for bonus if so we take the second argv
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
    //preparing arrays
    int lenght_number = strlen(ifItNumber);
    int inputNumber[lenght_number];
    int input_bonus[input_lenght_B];
    //bonus error handling and converting to integer
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
        //error handling for normal cases and converting to integer
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
    int radiciCIslo = 0;
    //Because first is always coming the name so
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
            // We don't need to loop through the entire phone number,
            // because we know the length of the sequence we're looking for from input.
                for(int start = 0; start <= telefon_len - lenght_number;start++){
                    int i;
                        for(i = 0; i < lenght_number; i++){
                            if(inputNumber[i] == 0){
                        //because 0 is + so we can skip it
                            continue;
                        }
            // Sliding window  if the current digits don't match,
            // break and try again with the next starting position.

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
                        // Use strchr to check if the character matches any key for the current digit.
                        if (!strchr(button, tolower(list.jmeno[start + i]))) {
                            break;
                        }
                    }
                    // If we found a matching name sequence, set matchName to true.
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
                //Moving window with watching position so every another number in sequence is bigger
                //and counting the matches
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
            //Moving window so every another window from the match is smaller window from left side
            //and counting the matches
            for(int number = 0; number < input_lenght_B;number ++){
                bool found_M_N = false;
                for(int i = sequence_number; i < telefon_len; i++){
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
                //counting every match number if is the same length size like
                //input we have find the contact
            if(matchSpecialN == input_lenght_B){
                matchNumber = true;
                }
            }
            //printing the contact that we match
            if (matchNumber == true || matchName == true) {
                findMatch = true;
                printf("%s, %s\n", list.jmeno, list.telefon);
            }
        }
        radiciCIslo++;
    }
    //printing if we didnt match anything
    if(!(findMatch)){
        printf("Not found\n");
    }

    return 0;
}
