/*
    Program: fungsi_2.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 31/10/2023
    Description: Menghitung akar dari persamaan kuadrat
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int diskriminant(int a, int b, int c);
float persamaanKuadrat(float a, float b, float d);

int main()
{
    // Kamus
    int a,b,c, D;
    float fungsi;

    // Algoritma
    printf("Masukan nilai A: ");
    scanf("%d", &a);

    printf("Masukan nilai B: ");
    scanf("%d", &b);

    printf("Masukan nilai C: ");
    scanf("%d", &c);

    D = diskriminant(a,b,c);
    printf("\nHasil Diskriminant = %d\n", D);

    if(D > 0) {
        fungsi = persamaanKuadrat(a,b,D);
        printf("Fungsi persamaan kuadrat = %1.2f\n\n", fungsi);
    
    } else {
        printf("Nilai persamaan kuadrat menghasilkan nilai imajiner\n");
    }

    return 0;
}

int diskriminant(int a, int b, int c)
{
    // Kamus
    int d;

    // Algoritma
    d = ((b*b)-(4*a*c));

    return d;
}

float persamaanKuadrat(float a, float b, float d)
{
    float x1, x2, hasil;

    x1 = (-b + sqrt(d)) / (2 * a);
    x2 = (-b + sqrt(d)) / (2 * a);

    hasil = x1 + x2;

    return hasil;
}