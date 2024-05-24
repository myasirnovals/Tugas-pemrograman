/*
    Program: for2.c
    Author: 2350081004/Muhamad Yasir Noval
    Date: 24 Oktober 2023
    Description: cetak bilangan genap 1 sd N
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // KAMUS
    int i;
    int n;

    // ALGORITMA
    printf("Masukan N: ");
    scanf("%d", &n);

    if (n > 0) {
        for (i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                printf("%d ", i);
            }
        }
    } else {
        printf("Angka tidak boleh kurang dari atau sama dengan 0");
    }

    return 0;
}
