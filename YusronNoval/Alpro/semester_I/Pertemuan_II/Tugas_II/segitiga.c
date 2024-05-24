/*
    Program: segitiga.c
    Author: 2350081003/Muhamad Yusron NOval
    Date: 17/10/2023
    Description: Tugas untuk menentukan sebuah segitiga menggunakan program
*/

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    // KAMUS
    int a, b, c;

    // ALGORITMA
    printf("Masukkan nilai A: ");
    scanf("%d", &a);

    printf("Masukkan nilai B: ");
    scanf("%d", &b);

    printf("Masukkan nilai C: ");
    scanf("%d", &c);

    if (a > 0 && b > 0 && c > 0) {
        printf("\n\nSebuah segitiga\n\n");

    } else {
        printf("\n\nBukan segitiga\n\n");
    }

    return 0;
}