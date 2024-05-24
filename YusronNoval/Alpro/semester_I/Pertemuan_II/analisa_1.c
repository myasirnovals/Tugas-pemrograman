/*
    Program: Assigment1.c
    Name: Muhamad Yusron Noval
    NIM: 2350081003
    Class: A
    Description: ...
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus
    int a, b;

    // Algoritma
    // Clrscr();
    printf("Masukkan a: ");
    scanf("%d", &a);

    printf("Masukkan b: ");
    scanf("%d", &b);

    // Analisa kasus 1
    if(a > b) {
        printf("a > b");
    
    } else if(a == b) {
        printf("a = b");
    
    } else {
        printf("a < b");
    }

    return 0;
}