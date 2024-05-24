/**
 * Program: segitigaUtuhTerbalik.c
 * Author: 2350081004/Muhamad Yasir Noval
 * Date: ...............
 * Description: ...............
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    // KAMUS
    int i, j, t;

    // ALGORITMA
    printf("Masukan Tinggi Segitiga: ");
    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }

        for (j = i; j < t; j++) {
            printf("*");
        }

        for (j = i; j < t - 1; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}