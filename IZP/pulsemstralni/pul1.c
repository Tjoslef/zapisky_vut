#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main(){
char buffer[256];
while (fgets(buffer, sizeof(buffer), stdin) != NULL){
    buffer[strcspn(buffer, "\n")] = '\0';
    for(int i = 0; buffer[i] != '\0';i++){
        if(isspace(buffer[i])){
            buffer[i] = ' ';

            }

        }
    }
char *arr[10];
for (int i = 1; i < 10; i++) {
        if (arr[i][0] == '-') {
            printf("%c\n", *arr[i] + 1); // Print each argument starting from the second character
        }
    }


}
