/*
    Program: for2.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 24/10/2023
    Description: Perulangan menggunakan for loop untuk bilangan genap
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus
    int i;
    int N;
    
    // Algoritma
    printf("Masukkan N: ");
    scanf("%d", &N);
    printf("\n");

    if(N > 0) {
        for(i=1; i <= N; i++) {
            if(i % 2 == 0) {
                printf("%d ", i);
            }
        }

        printf("\n\n");
    
    } else {
        printf("Nilai tidak boleh kurang dari 0\n\n");
    }

    return 0;
}