/*
    Program: loop_2.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 24/10/2023
    Description: Perulangan menggunakan while do
*/
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    // KAMUS
    int n;
    float i, s;

    // ALGORITMA
    printf("Masukan nilai N: ");
    scanf("%d", &n);

    i = 1;
    s = 1.0;
    printf("s = 1 + ");

    while (i <= n) {
        printf("%1.3f", 1 / i);

        if (i < n) {
            printf(" + ");
            s = s + 1 / i;
        }

        i++;
    }

    printf("\nNilai s : %.2f\n\n", s);

    return 0;
}