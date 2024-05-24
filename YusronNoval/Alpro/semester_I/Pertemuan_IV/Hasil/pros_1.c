/*
    Program: pros_1.c
    Name: Muhamad Yusron Noval
    NIM: 2350081003
    Class: A
    Description: ...
*/
#include <stdio.h>
#include <stdlib.h>

void tukar(int *a, int *b);

int main()
{
    // Kamus
    int bil1, bil2;

    // Algoritma
    printf("Masukkan bilangan 1: ");
    scanf("%d", &bil1);

    printf("Masukkan bilangan 2: ");
    scanf("%d", &bil2);

    tukar(&bil1, &bil2);
    printf("\nHasil pertukaran a: %d, b: %d\n\n", bil1, bil2);

    return 0;
}

void tukar(int *a, int *b) 
{
    // Kamus
    int tmp;

    // Algoritma
    tmp = *a;
    *a = *b;
    *b = tmp;
}