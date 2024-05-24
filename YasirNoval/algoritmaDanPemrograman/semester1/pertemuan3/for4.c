/*
    Program: for4.c
    Author: 2350081004/Muhamad Yasir Noval
    Date: 24 Oktober 2023
    Description: memunculkan pola bilangan tergantung nilai N
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // KAMUS
    int n, i, j;

    // ALGORITMA
    printf("Masukan nilai N: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            printf("%d ", j);
        }

        for (j = 1; j < i; j++) {
            printf("%d ", j + n);
        }
        printf("\n");
    }

    return 0;
}
