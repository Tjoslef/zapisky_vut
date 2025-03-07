#include <stdio.h>


void vypis_pod_diagonalou(int matice[][4], int velikost) {
    for (int i = velikost-1; i >= 0; i--) { // Začneme od druhého řádku (index 1)
            printf("%d ", matice[i][i]);
        printf("\n");
    }
}
int main() {
    int matice[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };
    int velikost = 4;

    vypis_pod_diagonalou(matice, velikost);

    return 0;
}
