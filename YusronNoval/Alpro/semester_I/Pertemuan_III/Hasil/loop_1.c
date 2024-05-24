/*
    Program: loop_1.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 24/10/2023
    Description: Perulangan menggunakan for loop
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus
    int N;
    float i,s;

    // Algoritma
    printf("Masukkan N: ");
    scanf("%d", &N);
    s = 1.0;

    printf("s = 1+");
    for(i=2; i <= N; i++) {
        printf("%1.3f", 1/i);

        if(i < N) {
            printf("+");
            s = s + 1/i;
        }
    }

    printf("\nNilai s: %3.2f", s);

    return 0;
}