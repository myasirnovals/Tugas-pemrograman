/*
    Program: loop_3.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 24/10/2023
    Description: Perulangan menggunakan repeat until
*/
#include <stdio.h>
#include <stdlib.h>


int main() {
    // KAMUS
    int n;
    float i, s;

    // ALGORITMA
    printf("Masukan nilai N: ");
    scanf("%d", &n);

    // menggunakan skema loop while...do
    i = 1;
    s = 1.0;
    printf("s = 1 + ");

    do {
        printf("%1.3f", 1 / i);

        if (i < n) {
            printf(" + ");
            s = s + 1 / i;
        }

        i++;
    } while (i <= n);

    printf("\n\nNilai s : %.2f\n\n", s);

    return 0;
}