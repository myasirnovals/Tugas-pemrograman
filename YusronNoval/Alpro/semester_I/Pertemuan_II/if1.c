/*
    Program: if1.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 17/10/2023
    Description: Memahami kondisional dari sebuah program
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus
    int a,b;

    // Algoritma
    // Clrscr();
    // Analisa kasus-1
    printf("Masukkan nilai a: ");
    scanf("%d", &a);

    printf("Masukkan nilai b: ");
    scanf("%d", &b);

    if(a > b) {
        printf("\n\na lebih besar dari b\n\n");

    } else if (a == b) {
        printf("\n\na sama dengan b\n\n");
    
    } else {
        printf("\n\na kurang dari b\n\n");
    }

    return 0;
}