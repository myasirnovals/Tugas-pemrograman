/*
    Program: for3.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 24/10/2023
    Description: Memunculkan bintan sebanyak N menggunakan perulangan for
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus
    int N;
    int i;
    int j;

    // Algoritma
    printf("Masukkan nilai N: ");
    scanf("%d", &N);

    if(N > 0) {
        for(i=0; i <= N; i++) {
            for(j=0; j <= i; j++) {
                printf("*");
            }

            printf("\n");
        }

        for(i=N; i >= 0; i--) {
            for(j=0; j <= i; j++) {
                printf("*");
            }

            printf("\n");
        }
    
    } else {
        printf("Nilai N tidak boleh dari 0");
    }

    return 0;
}