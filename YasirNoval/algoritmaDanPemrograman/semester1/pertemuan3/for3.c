/*
    Program: for3.c
    Author: 2350081004/Muhamad Yasir Noval
    Date: 24 Oktober 2023
    Description: memunculkan karakter "*" tergantung banyak nya N,
    dengan pola segitiga
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // KAMUS
    int i, j, n;

    // ALGORITMA
    printf("Masukan nilai n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("gambar tidak bisa digambar");
        printf("nilai n tidak boleh kurang dari atau sama dengan 0");
    } else {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= i; j++) {
                printf("*");
            }

            printf("\n");
        }
        for (i = 1; i <= n; i++) {
            for (j = i; j <= n; j++) {
                printf("*");
            }

            printf("\n");
        }
    }

    return 0;
}
