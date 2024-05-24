/*
    Program: point.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 17/10/2023
    Description: Program menghitung point
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int abs, ord;
} Point;



int main()
{
    // Kamus
    Point x,y;

    // Algoritma
    printf("Masukkan nilai absis (x): ");
    scanf("%d", &x.abs);

    printf("Masukkan nilai ordinat (y): ");
    scanf("%d", &y.ord);

    if(x.abs > 0 && y.ord > 0) {
        printf("\n\nTitik (%d,%d) berada di kuadran 1\n\n", x.abs, y.ord);
    
    } else if(x.abs < 0 && y.ord > 0) {
        printf("T\n\nitk (%d,%d) berada di kuadran 2\n\n", x.abs, y.ord);

    } else if(x.abs < 0 && y.ord < 0) {
        printf("\n\nTitik (%d,%d) berada di kuadran 3\n\n", x.abs, y.ord);

    } else if(x.abs > 0 && y.ord < 0) {
        printf("\n\nTitik (%d,%d) berada di kuadran 4\n\n", x.abs, y.ord);
    
    } else {
        printf("\n\nTitik (%d,%d) tidak berada di kuadran manapun\n\n", x.abs, y.ord);
    }

    return 0;
}