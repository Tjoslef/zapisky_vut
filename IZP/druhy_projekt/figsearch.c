#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
typedef struct{
int cols;
int rows;
int **bitmap;
}obrazek;
size_t number_of_col(char array[]){
size_t cols_num = 0;
for(int i = 0;array[i] != '\n';i++){
cols_num++;
}
return  cols_num;

}
void saving_image(char array[],obrazek *image,int numberOf_row,int cols){
int **temp_matrix = realloc(image->bitmap,(numberOf_row + 1) * sizeof(int));
if(temp_matrix == NULL){
    perror("wrong realloc in saving_image");
    return;
    }
image->bitmap = temp_matrix;
image->bitmap[numberOf_row] = malloc(cols * sizeof(int));
if(image->bitmap[numberOf_row] == NULL){
    perror("wrong malloc in temp_matrix");
    return;
    }
for (int i =0; i < cols; i++) {
if(!isdigit(array[i])){
fprintf(stderr,"wrong symbols in image");
        }
image->bitmap[numberOf_row][i] = array[i] - '0';
    }
}
void free_image(obrazek *image){
for(int i = 0;i < image->rows;i++){
    for(int j = 0; j < image->cols;j++){
        free(image->bitmap[i]);

    }
        free(image->bitmap);
        free(image);
    }
}
void readingFile(FILE *file,obrazek *image){
char buffer[256];
int numberOf_row = 0;
int cols = 0;
while(fgets(buffer,sizeof(buffer),file) != NULL){
    if(numberOf_row == 0){
        buffer[strcspn(buffer, "\n")] = '\0';
        if(atoi(buffer)){
            image->rows = buffer[0];
            image -> cols = buffer[1];
        }else{
            fprintf(stderr,"wrong symbols in image");
            return;
                }
        }
    else {
        buffer[strcspn(buffer, "\n")] = '\0';
        int cols = number_of_col(buffer);
        saving_image(buffer,image,numberOf_row,cols);
}
numberOf_row++;

    }
if(numberOf_row != image->rows || cols != image->rows){
    fprintf(stderr, "wrong number of dimension of matrix to real matrix");
    return;
    }

}

int main(int argc, char *argv[]){
if(argc != 2){
    fprintf(stderr, "wrong number of arguments");
    return 1;
    }
FILE *fileopen = fopen(argv[2],"r");
if(fileopen == NULL){
    perror("wrong file");
    }

obrazek *image = malloc(sizeof(obrazek));
readingFile(fileopen,image);
for(int i = 0; i < image->rows;i++){
    for(int j = 0; j < image->cols;j++){
    printf("%d ",image->bitmap[i][j]);
        }
    printf("\n");
    }
free_image(image);
}
