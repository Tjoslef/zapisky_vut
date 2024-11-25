#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define SIZE_OF_RESULT 2
//struct for saving image and date about the image
typedef struct{
int cols;
int rows;
unsigned char *bitmap;
}obrazek;
//constant for matching the argument and choose what to do with image
const char* ActivityOpt[] = {
"--help",
"test",
"hline",
"vline",
"square"
};

// Frees the allocated memory for the image struct, including its bitmap
void free_image(obrazek *image){
    free(image->bitmap);
    free(image);
    }
// Frees a dynamically allocated 2D array and its rows
// `array`: The pointer to the 2D array to be freed
// `row`: The number of rows in the array
void free_result(int **array,int row){
   for (int i = 0; i < row; i++) {
        free(array[i]);
   }
    free(array);
}
//Printing the result in 2D array
void printing_result(int **array){
    for(int i = 0; i < SIZE_OF_RESULT;i++){
       for(int j = 0; j < SIZE_OF_RESULT;j++){
          printf("%i ",array[i][j]);
       }
   }
}
// Allocates a 2x2 2D array for storing the result
// Returns a pointer to the allocated array, or NULL if allocation fails
int **alloc_result(){
    int **result = malloc(2 * sizeof(int*));
    if(result == NULL){
    perror("Ivalid malloc in result");
        return NULL;
    }
for(int i = 0;i < SIZE_OF_RESULT;i++){
    result[i] = malloc(SIZE_OF_RESULT * sizeof(int));
    if(result[i] == NULL){
        perror("Invalid malloc in result 1");
        result = NULL;
        }
    result[i][0] = 0;
    result[i][1] = 0;
    }
    return result;
}
/* This function reads data from a file pointed to by file and populates the `obrazek` structure.

   *Reads the number of rows and columns from the file and stores them in `image->rows` and `image->cols`.
   * Allocates a 1D array for the bitmap in image->bitmap based on the dimensions.
   *  beacuse we allocates 1D array to get to columns we have to multiply always be numbers of rows
      and add number of cols
   * Reads bitmap data into the allocated array.
   * Validates that the total number of bitmap elements matches the specified dimensions.
   * If any errors occur (invalid dimensions, memory allocation failure, or mismatched data),
   * it print an error and sets image->bitmap to NULL.

   Parameters: pointer to file, pointer to obrazek struct
*/
void readingFile(FILE *file,obrazek *image){
unsigned char buffer;
int check_lenght = 0;
int counter = 0;
 if(fscanf(file, "%i %i",&image->rows,&image->cols) != 2){
            fprintf(stderr,"Invalid");
            image->bitmap = NULL;
            return;
}
if(image->rows == 0 && image->cols == 0){
    fprintf(stderr, "Invalid");
    image->bitmap = NULL;
    return;
    }
image->bitmap = malloc(image->rows * image->cols *sizeof(unsigned char));
            if(image->bitmap == NULL){
                perror("Invalid wrong malloc");
                return;
            }

while(fscanf(file, "%hhu", &buffer) != EOF){
    if(check_lenght >= image->rows * image->cols){
            fprintf(stderr, "Invalid");
            image->bitmap = NULL;
            return;
            }
        image->bitmap[check_lenght++] = buffer;
        counter++;
}
if(check_lenght != image->cols * image->rows){
        fprintf(stderr, "Invalid");
        image->bitmap = NULL;
        return;
    }
}
/*
 * Finds the longest horizontal line of 1s in the bitmap of the given `obrazek` struct.
 * Allocates a 2D array using alloc_result to store the start and end coordinates
 * of the line. Iterates through each row, counting consecutive 1s and updating the
 * result if a longer line is found. If no line is found set position_big_hor equal
 * to`NULL`.
 *
 * Parameters:
 * - image: Pointer to the obrazek struct containing the bitmap.
 *
 * Returns:
 * - A 2x2 2D array with the coordinates of the longest line, or `NULL` if none exists.
 */int **hline(obrazek *image){
int biggest_leng = 0;
int **position_big_hor = alloc_result();
for (int i = 0; i < image->rows; i++) {
    for (int j = 0; j < image->cols; j++) {
       if (image->bitmap[i * image->cols + j] == 1) {
                int counting = 1;
                int z = j + 1; //for moving foward in matrix
                while(z < image->cols && image->bitmap[i * image->cols + z] == 1){
                 counting++;
                 z++;

                }
                if(counting > biggest_leng){
                    biggest_leng = counting;
                    position_big_hor[0][0] = i;
                    position_big_hor[0][1] = j;
                    position_big_hor[1][0] = i;
                    position_big_hor[1][1] = z - 1;
                    }
                j = z - 1;/* so we dont check what has been
                * already checked
                */
;
            }
        }
    }

    if(biggest_leng == 0){
        free_result(position_big_hor,SIZE_OF_RESULT);
        position_big_hor = NULL;
        return position_big_hor;
    }
    return position_big_hor;

}
/*
 * Finds the longest vertical line of 1s in the bitmap of the given `obrazek` struct.
 * Allocates a 2D array using `alloc_result` to store the start and end coordinates
 * of the line. Iterates through each column, counting consecutive 1s and updating
 * the result if a longer line is found. If no line is found, returns `NULL`.
 *
 * Parameters:
 * - `image`: Pointer to the `obrazek` struct containing the bitmap.
 *
 * Returns:
 * - A 2x2 2D array with the coordinates of the longest vertical line, or `NULL` if none exists.
*/
int **vline(obrazek *image){
int biggest_leng = 0;
int **position_big_ver = alloc_result();
for(int i = 0;i < image->cols;i++){
    for(int j = 0;j< image->rows;j++){
        if(image->bitmap[j * image->cols + i] == 1){
        int counting = 1;
        int z = j + 1;//for moving down in matrix
        while(z < image->rows && image->bitmap[z * image->cols + i] == 1){
                counting++;
                z++;
                }

                if(counting > biggest_leng){
                    biggest_leng = counting;
                    position_big_ver[0][0] = j;
                    position_big_ver[0][1] = i;
                    position_big_ver[1][0] = z - 1;
                    position_big_ver[1][1] = i;
                    }
                j = z - 1; /* so we dont check what has been
                * already checked
                */
            }
        }
    }
    if(biggest_leng == 0){
    free_result(position_big_ver,SIZE_OF_RESULT);
    position_big_ver = NULL;
    return  position_big_ver;
    }
    return position_big_ver;

}
/*
 * Finds the largest square of 1s in the bitmap of the given `obrazek` struct.
 * The function iterates through the bitmap to identify potential squares, starting
 * from each position that contains a 1. For each potential square, it checks if
 * it can be expanded.If the square can be expanded, it continues checking until no
 * further expansion is possible, at which point the largest valid square is identified.
 * The function also ensures that the bottom-right corner of the square is valid by
 * performing a backtracking check.
 *
 * The result is stored in a 2D array (allocated by the `alloc_result` function),
 *
 * Parameters:
 * - `image`: A pointer to the `obrazek` struct containing the bitmap (1D array).
 *
 * Returns:
 * - A 2x2 2D array containing the coordinates of the largest square found:
 *   If no square is found, the function returns `NULL`.
 */int **square(obrazek *image){
int biggest_leng = 0;
int find_one = 0; //variable checking if anything was found
int **position_big_square = alloc_result();
    for (int i = 0; i < image->rows; i++) {
        for(int j = 0; j< image->cols;j++){
            if(image->bitmap[i * image->cols + j] == 1){
            int side_lenght = 1;
            int can_expand = 1;
            while (can_expand && i + side_lenght < image->rows && j + side_lenght < image->cols) {
                    for (int k = 0; k <= side_lenght; k++) {
                            if (image->bitmap[i * image->cols + j + k] != 1 || image->bitmap[(i + k) * image->cols+ j] != 1) {
                            can_expand = 0;
                            break;
                        }
                    }
                    if (can_expand){
                        side_lenght++;
                    }
                }
            /*start of backtracking if the side equal to 1 it doesnt make sence
            * to do backtracking so will just check with biggest_leng
            */
            if(side_lenght != 1){
                int valid_bottom_right = 1;
                int backwalk = 0;
                while(backwalk < side_lenght){
                    int is_ok = 1;
                    for (int k = 0; k < side_lenght - backwalk;  k++) {
                      /*
                         * The indexing math:
                         * - 'k' is the iteration variable.
                        * - 'side_length' determines the maximum square size.
                        * - 'backwalk' handles the backtracking step.
                         */
                            if (image->bitmap[(i + side_lenght - 1 -backwalk) * image->cols + j + k] != 1
                                || image->bitmap[(i + k) * image->cols + j + side_lenght - 1- backwalk] != 1) {
                                is_ok = 0;
                            break;
                        }
                    }
                    if(is_ok){
                        valid_bottom_right = 1;
                        break;

                    }else {
                        valid_bottom_right =0;
                        backwalk++;
                    }
                }
            find_one = side_lenght;
            side_lenght = side_lenght - backwalk;
            find_one = side_lenght;
    //Updating a position_big_square and biggest_leng
        if(valid_bottom_right  && side_lenght > biggest_leng){
                biggest_leng = side_lenght - 1;
                position_big_square[0][0] = i;
                position_big_square[0][1] = j;
                position_big_square[1][0] = i + biggest_leng;
                position_big_square[1][1] = j + biggest_leng;
                }
            }else if (biggest_leng == 0) {
                position_big_square[0][0] = i;
                position_big_square[0][1] = j;
                position_big_square[1][0] = i;
                position_big_square[1][1] = j;
            }
        }
    }
        }
    if(find_one == 0){
        free_result(position_big_square,SIZE_OF_RESULT);
        position_big_square = NULL;
        return position_big_square;
    }else {
    return position_big_square;
    }
}
/*
 * Pointer function to process an image.
 * - Reads the image from the file.
 * - Applies the given processing function.
 * - Prints the result and frees all allocated resources (image and result array).
 *
 * Returns:
 * - 0 on success.
 * - 1 on failure (e.g., file read error or processing error).
 */
int proccesing_image(FILE *fileopen,obrazek *image, int ** (*procces_function)(obrazek *)){
readingFile(fileopen,image);
if(image->bitmap == NULL){
    free_image(image);
    fclose(fileopen);
    return 1;
    }
int ** result = procces_function(image);
if(result == NULL){
    printf("Not found \n");
    free_image(image);
    fclose(fileopen);
    return 1;
    }
printing_result(result);
free_result(result, SIZE_OF_RESULT);
free_image(image);
fclose(fileopen);
return 0;
}

int main(int argc, char *argv[]){
//checking for numbers of arguments
if(argc != 3){
  fprintf(stderr,"wrong number of arguments");
   return 1;
 }
//opening of file
FILE *fileopen = fopen(argv[2],"r");
if(fileopen == NULL){
    perror("wrong file");
    return 1;
    }
//allocation of obrazek struct like a image
obrazek *image;
image = malloc(sizeof(obrazek));
if(image ==NULL){
    perror("Ivalid malloc of image");
    fclose(fileopen);
    return 1;
    }
image->bitmap = NULL;
/*
 * Matches the given argument (`argv[1]`) with available options in `ActivityOpt`
 * and invokes the corresponding function via `processing_image` using a `switch` statement.
 *
 * - `ActivityOpt` contains the available options.
 * - The default case handles invalid input.
 * - The program suggests valid options if no match is found.
 */
size_t ActivityOpt_lenght = sizeof(ActivityOpt) / sizeof(ActivityOpt[0]);
for(size_t i = 0; i < ActivityOpt_lenght;i++){
    if(strcmp(ActivityOpt[i],argv[1]) == 0)
switch (i) {
        case 0:
            printf("Use one of this option");
            for (size_t i = 0; i < ActivityOpt_lenght; i++) {
                printf(" %s \n",ActivityOpt[i]);
            }
            printf("Also give me file where is your image \n");
            break;
        case 1:
         readingFile(fileopen, image);
            if(image->bitmap !=  NULL){
                printf("Valid");
                free_image(image);
                fclose(fileopen);
                return 0;
                    }
            free_image(image);
            fclose(fileopen);
            break;

        case 2:
                return proccesing_image(fileopen, image, hline);

        case 3:
                return proccesing_image(fileopen, image, vline);

        case 4:
               return proccesing_image(fileopen, image, square);
        default:
            printf("Invalid \n");

}
}
fclose(fileopen);
}
