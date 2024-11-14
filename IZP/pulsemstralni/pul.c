#include <stdio.h>
#include <string.h>
int delkaretezce (char str [])
    {
    int delka = 0;
    for(int i =0;str[i] != '\0';i++){
     delka++;

    }
}
void vymenanZnaku(char *A,char *B){
   int temp = *A;
    *A = *B;
    *B = temp;
    }



}
int main(){
char buffer;
int cetnost[10] = {0};
while((buffer = fgetc(stdin)) != EOF){
if(buffer >= 48 && buffer <= 57){
        cetnost[buffer - 48] ++;
        }
}
FILE *ftpr;
ftpr = fopen("text.txt", "a");
for(int i =0; i < 10;i++){
    fprintf(ftpr,"%i",cetnost[i]);

        }
}
