#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(int argc,char* argv[10]){
char *prikaz = argv[1];
char argument_2[11];
strncpy(argument_2, argv[2], 10);
argument_2[10] = '\0';
char prvni_Pr[] = "tolower";
char druhy_Pr[] = "notalnum";
char treti_Pr[] = "palindrom";
char pouzeZnak[100];
int index = 0;
if(strcmp(prikaz,prvni_Pr ) == 0){
    for(int i = 0; i < 10;i++){
        if(argument_2[i] >='A' &&  argument_2[i] <= 'Z'){
            argument_2[i] = argument_2[i] + 32;
            }

        }

    }
    else if(strcmp(prikaz, druhy_Pr) == 0){
    for(int i = 0; i< 10; i++){
       if(!(isdigit(argument_2[i]|| isalpha(argument_2[i])))){
        pouzeZnak[index] = argument_2[i];
        index++;
        }
        }
    pouzeZnak[index];

    }
    else if (strcmp(prikaz, treti_Pr)) {
        for(int i =
    }



}
