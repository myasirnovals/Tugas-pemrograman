/*
    Program: pros_1.c
    Name: Muhamad Yusron Noval
    NIM: 2350081003
    Class: A
    Description: ...
*/
#include <stdio.h>
#include <stdlib.h>

void tukar(int *a, int *b, int *c);

int main()
{
    // Kamus
    int bil1, bil2, bil3;

    // Algoritma
    printf("Masukkan bilangan 1: ");
    scanf("%d", &bil1);

    printf("Masukkan bilangan 2: ");
    scanf("%d", &bil2);

    printf("Masukkan bilangan 3: ");
    scanf("%d", &bil3);

    tukar(&bil1, &bil2, &bil3);
    printf("\nHasil pertukaran a: %d, b: %d, c: %d\n\n", bil1, bil2, bil3);

    return 0;
}

void tukar(int *a, int *b, int *c)
{
    // Kamus
    int tmp;

    // Algoritma
    tmp = *c;
    *c = *b;
    *b = *a;
    *a = tmp;

}