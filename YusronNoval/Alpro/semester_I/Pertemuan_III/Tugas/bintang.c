/*
    Program: bintang.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 24/10/2023
    Description: Membuat gambar menggunakan perulangan for loop
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus
    int N = 5;
    int i, j;

    // Algoritma
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

    return 0;
}