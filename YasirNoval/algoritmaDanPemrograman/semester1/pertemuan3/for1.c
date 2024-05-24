/*
    Program: for1.c
    Author: 2350081004/Muhamad Yasir Noval
    Date: 24 Oktober 2023
    Description: cetak bilangan ganjil sebanyak n
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // KAMUS
    int i;
    int bil;
    int n;

    // ALGORITMA
    printf("Masukan N: ");
    scanf("%d", &n);

    if (n > 0) {
        bil = 1;
        for (i = 1; i <= n; i++) {
            printf("<%d>", bil);
            bil = bil + 2;
        }
    } else {
        printf("Angka tidak boleh kurang dari atau sama dengan 0");
    }

    return 0;
}

