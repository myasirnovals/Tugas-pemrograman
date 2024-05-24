/*
    Program: for1.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 24/10/2023
    Description: Perulangan menggunakan for loop untuk bilangan ganjil
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus
    int i;
    int bil;
    int N;
    
    // Algoritma
    printf("Masukkan N: ");
    scanf("%d", &N);
    printf("\n");

    if(N > 0) {
        bil = 1;

        for(i=1; i <= N; i++) {
            printf("<%d> ", bil);
            bil = bil + 2;
        }

        printf("\n\n");
    
    } else {
        printf("Nilai tidak boleh kurang dari 0");
    }

    return 0;
}