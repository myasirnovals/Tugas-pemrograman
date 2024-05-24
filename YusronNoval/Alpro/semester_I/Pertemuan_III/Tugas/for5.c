/*
    Program: for5.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 24/10/2023
    Description: Menghitung deret menggunakan perulangan for
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus
    int N;
    float i, s;

    // Algoritma
    printf("Masukkan nilai N: ");
    scanf("%d", &N);

    s = 1.0;
    printf("\n");

    for(i=1; i <= N; i++) {
        printf("%1.3f", 1/i);

        if(i < N) {
            printf(" + ");
            s = s + 1/i;
        }
    }

    printf("\n\n");

    return 0;
}