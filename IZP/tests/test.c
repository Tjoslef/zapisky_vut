
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
const char* ActivityOpt[] = {
"--help",
"test",
"hline",
"vline",
"square"
};
void removeWhiteSpace(char *str){
int i = 0;
int j = 0;
while(str[i] != '\0'){
if(!isspace((unsigned char)str[i])){
    str[j++] = str[i];
    }
i++;

}
str[j] = '\0';
}

void saving_image(char array[],obrazek *image,int numberOf_row,int cols){
removeWhiteSpace(array);
size_t numberOf_rowHere = numberOf_row + 1;
int **temp_matrix = realloc(image->bitmap,(numberOf_rowHere) * sizeof(int *));
if(temp_matrix == NULL){
perror("Invalid wrong realloc in saving_image \n");
image->bitmap = NULL;
return;
}
image->bitmap = temp_matrix;
image->bitmap[numberOf_row] = malloc(cols * sizeof(int));
if(image->bitmap[numberOf_row] == NULL){
perror("Invalid wrong malloc in temp_matrix \n");
image->bitmap = NULL;
return;
}
for (int i =0; i < cols; i++) {

if(!isdigit(array[i])){
    fprintf(stderr,"Invalid wrong symbols in image \n");
    image->bitmap = NULL;
    return;
}
if(array[i] - '0' != 0 && array[i] - '0' != 1){
    fprintf(stderr,"Invalid wrong symbols in image \n");
    image->bitmap = NULL;
    return;
        }
image->bitmap[numberOf_row][i] = array[i] - '0';
    }
}

void free_image(obrazek *image){
for(int i = 0;i < image->rows;i++){
        free(image->bitmap[i]);
    }
    free(image->bitmap);
    free(image);
    }
void free_int(int **array,int row){
   for (int i = 0; i < row; i++) {
        free(array[i]);
   }
    free(array);
}
void readingFile(FILE *file,obrazek *image){
char buffer[256];
int numberOf_row = 0;
int counter = 0;
while(fgets(buffer,sizeof(buffer),file) != NULL){
    if(counter == 0){
        buffer[strcspn(buffer, "\n")] = '\0';
        if(sscanf(buffer, "%i %i ",&image->rows, &image->cols) != 2){
            fprintf(stderr, "Invalid :wrong number of dimension or bad format \n");
            image->bitmap = NULL;
            return;
            }
        if(image->rows < 0 || image->cols < 0){
            fprintf(stderr, "Invalid : negative number \n");
            image->bitmap = NULL;
            return;
        }

        }else {

        int cols = 0;
        for(int i = 0;buffer[i] != '\n';i++){
        if(buffer[i] == ' '){
        continue;
                }
        cols++;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        if(cols != image->cols){
            fprintf(stderr, "Invalid number of cols \n");
            image->bitmap = NULL;
            return;
            }
        printf("number of cols %i \n",cols);
        saving_image(buffer,image,numberOf_row,cols);
        numberOf_row++;
        }

        counter++;

    }
    if(numberOf_row  != image->rows){
        fprintf(stderr, "Invalid wrong number of dimension of rows compare to real matrix %i to %i  %i number of cols \n",numberOf_row,image->rows,image->cols);
        image->bitmap =NULL;
        return;
    }

}
int **hline(obrazek *image){
int biggest_leng = 0;
int **position_bigH = malloc(2 * sizeof(int*));
    if(position_bigH == NULL){
    perror("Ivalid malloc in hline 1");
        return NULL;
    }
for(int i = 0;i < 2;i++){
    position_bigH[i] = malloc(2 * sizeof(int));
    if(position_bigH[i] == NULL){
        perror("Invalid malloc in hline 2");
        return NULL;
        }
    position_bigH[i][0] = 0;
    position_bigH[i][1] = 0;
    }
for (int i = 0; i < image->rows; i++) {
    for (int j = 0; j < image->cols; j++) {
       if (image->bitmap[i][j] == 1) {
                int counting = 1;
                int z = j + 1;
                while(z < image->cols && image->bitmap[i][z] == 1){
                 counting++;
                 z++;

                }
                if(counting > biggest_leng){
                    biggest_leng = counting;
                    position_bigH[0][0] = i;
                    position_bigH[0][1] = j;
                    position_bigH[1][0] = i;
                    position_bigH[1][1] = z - 1;
                    }
                j = z - 1;
            }
        }
    }
    return position_bigH;
}
void printing_result(int **array){
    for(int i = 0; i < 2;i++){
       for(int j = 0; j < 2;j++){
          printf(" %i ",array[i][j]);
       }
   }
}
int **vline(obrazek *image){
int biggest_leng = 0;
int **position_bigHV = malloc(2 * sizeof(int*));
if(position_bigHV == NULL){
    perror("Invalid : error in mallock in vline1 \n");
    return NULL;
    }
for(int i = 0; i< 2;i++){
    position_bigHV[i] = malloc(2 * sizeof(int));
    if(position_bigHV[i] == NULL){
        perror("Invalid : error in malloc in vline2 \n");
        return NULL;
        }
    position_bigHV[i][0] = 0;
    position_bigHV[i][1] = 0;
    }
for(int i = 0;i < image->cols;i++){
    for(int j = 0;j< image->rows;j++){
        if(image->bitmap[j][i] == 1){
        int counting = 1;
        int z = j + 1;
        while(z < image->rows && image->bitmap[z][i] == 1){
                counting++;
                z++;
                }

                if(counting > biggest_leng){
                    biggest_leng = counting;
                    position_bigHV[0][0] = j;
                    position_bigHV[0][1] = i;
                    position_bigHV[1][0] = z - 1;
                    position_bigHV[1][1] = i;
                    }
                j = z - 1;
            }
        }

    }
    return position_bigHV;
}
int **square(obrazek *image){
int biggest_leng = 0;
int **position_bigSq = malloc(2 * sizeof(int*));
if(position_bigSq == NULL){
    perror("Invalid : error in mallock in vline1 \n");
    return NULL;
    }
for(int i = 0; i< 2;i++){
    position_bigSq[i] = malloc(2 * sizeof(int));
    if(position_bigSq[i] == NULL){
        perror("Invalid : error in malloc in vline2 \n");
        return NULL;
        }
    position_bigSq[i][0] = 0;
    position_bigSq[i][1] = 0;
    }
    for (int i = 0; i < image->rows; i++) {
        for(int j = 0; j< image->cols;j++){
            if(image->bitmap[i][j] == 1){
            int side_L = 1;
            int valid_top_left = 1;
            while (valid_top_left && i + side_L < image->rows && j + side_L < image->cols) {
                    for (int k = 0; k <= side_L; k++) {
                        if (image->bitmap[i][j + k] != 1 || image->bitmap[i + k][j] != 1) {
                            valid_top_left = 0;
                            break;
                        }
                    }
                    if (valid_top_left) side_L++;
                }

                int valid_bottom_right = 1;
            for (int k = 0; k < side_L; k++) {
                if (image->bitmap[i + side_L - 1][j + k] != 1 || image->bitmap[i + k][j + side_L - 1] != 1) {
                    valid_bottom_right = 0;
                    break;
                }
            }
            if(valid_bottom_right && valid_top_left && side_L -1  > biggest_leng){
                biggest_leng = side_L - 1;
                position_bigSq[0][0] = i;
                position_bigSq[0][1] = j;
                position_bigSq[1][0] = i + biggest_leng;
                position_bigSq[1][1] = j + biggest_leng;
                }

            }
        }
    }
    return position_bigSq;
}
int main(int argc, char *argv[]){
if(argc != 3){
  fprintf(stderr,"wrong number of arguments");
   return 1;
 }
FILE *fileopen = fopen(argv[2],"r");
if(fileopen == NULL){
    perror("wrong file");
    return 1;
    }

obrazek *image;
image = malloc(sizeof(obrazek));
if(image ==NULL){
    perror("Ivalid malloc of image");
    return 1;
    }
image->bitmap = NULL;
size_t ActivityOpt_lenght = sizeof(ActivityOpt) / sizeof(ActivityOpt[0]);
for(size_t i = 0; i < ActivityOpt_lenght;i++){
    if(strcmp(ActivityOpt[i],argv[1]) == 0)
switch (i) {
        case 0:
            printf("use one of this option");
            for (size_t i = 0; i < ActivityOpt_lenght; i++) {
                printf(" %s \n",ActivityOpt[i]);
            }
            printf("also give me file where is your image \n");
            break;
        case 1:
            readingFile(fileopen, image);
            free_image(image);
            fclose(fileopen);
            break;
        case 2:
            readingFile(fileopen,image);
            if(image->bitmap == NULL){
                free_image(image);
                fclose(fileopen);
                return 1;
                    }
            int **vysledekH = hline(image);
            if(vysledekH == NULL){
                free_image(image);
                fclose(fileopen);
                return 1;
                    }
            printing_result(vysledekH);
            free_int(vysledekH,2);
            free_image(image);
            break;
        case 3:
            readingFile(fileopen, image);
            if(image->bitmap ==NULL){
                free_image(image);
                fclose(fileopen);
                return 1;
                    }
            int **vysledekV = vline(image);
            if(vysledekV == NULL){
                free_image(image);
                fclose(fileopen);
                return 1;
                    }
            printing_result(vysledekV);
            free_int(vysledekV, 2);
            free_image(image);
            break;
        case 4:
            readingFile(fileopen, image);
            if(image->bitmap ==NULL){
                free_image(image);
                fclose(fileopen);
                return 1;
                    }
            int **vysledekSquare = square(image);
            if(vysledekSquare == NULL){
                free_image(image);
                fclose(fileopen);
                return 1;
                    }
            printing_result(vysledekSquare);
            free_int(vysledekSquare, 2);
            free_image(image);
            break;
        default:
            printf("Invalid no argument give \n");
}
}
fclose(fileopen);
}

