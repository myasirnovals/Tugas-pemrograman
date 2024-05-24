/*
    Program: fungsi_1.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 31/10/2023
    Description: Program mengirim nilai diskriminant dari nilai a,b dan c
*/
#include <stdio.h>
#include <stdlib.h>

int diskriminant(int a, int b, int c);

int main()
{
    // Kamus
    int D;
    int a,b,c;

    // Algoritma
    printf("Masukan koefesien A: ");
    scanf("%d", &a);

    printf("Masukan koefesien B: ");
    scanf("%d", &b);

    printf("Masukan koefesien C: ");
    scanf("%d", &c);

    D = diskriminant(a,b,c);

    printf("\nDiskriminant = %d\n\n", D);

    return 0;
}

int diskriminant(int a, int b, int c)
{
    // Kamus
    int d;

    // Algoritma
    d = ((b*b) - (4*a*c));

    return d;
}