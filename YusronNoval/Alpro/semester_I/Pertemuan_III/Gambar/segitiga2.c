/*
    Program: segitiga2.c
    Name: Muhamad Yusron Noval
    NIM: 2350081003
    Class: A
    Description: Membuat gambar menggunakan perulangan for loop
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus
    int N = 5;
    int i,j,x;

    // Algoritma
    for(i=N; i >= 0; i--) {
        for(j=0; j <= i; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}