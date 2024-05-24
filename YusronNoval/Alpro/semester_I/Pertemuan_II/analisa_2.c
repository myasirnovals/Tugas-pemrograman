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
    printf("Masukkan nilai a: ");
    scanf("%d", &a);

    printf("Masukkan nilai b: ");
    scanf("%d", &b);

    if(a >= b) {
        if(a > b) {
            printf("a > b");
        
        } else {
            printf("a = b");
        }
    
    } else {
        printf("a < b");
    }

    return 0;
}