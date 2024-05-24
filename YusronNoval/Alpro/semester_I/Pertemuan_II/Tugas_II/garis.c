/*
    Program: garis.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 18/10/2023
    Description: Program untuk menentukan garis
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int abs, ord;
} Point;

typedef struct
{
    Point p1, p2;
} Garis;


int main()
{
    // Kamus
    Point x1,y1,x2,y2, x3,y3,x4,y4;
    Garis g1,g2;
    double m1, m2;

    // Algoritma
    // Gradien I
    printf("Gradien I\n");
    printf("Masukkan nilai absis I: ");
    scanf("%d", &x1.abs);

    printf("Masukkan nilai ordinat I: ");
    scanf("%d", &y1.ord);

    g1.p1.abs = x1.abs;
    g1.p1.ord = y1.ord;
    printf("\nNilai Point I (%d,%d)\n", x1.abs, y1.ord);

    printf("\nMasukkan nilai absis II: ");
    scanf("%d", &x2.abs);

    printf("Masukkan nilai ordinat II: ");
    scanf("%d", &y2.ord);

    g1.p2.abs = x2.abs;
    g1.p2.ord = y2.ord;
    printf("\nNilai Point II (%d,%d)\n", x2.abs, y2.ord);

    if(g1.p2.ord - g1.p1.ord == 0) {
        printf("\n\nNilai m1 tidak boleh sama dengan 0\n\n");
        exit(0);
    
    } else {
        m1 = (g1.p2.ord - g1.p1.ord) / (g1.p2.abs - g1.p1.abs);
        printf("\nNilai m1 = %f\n", m1);
    }

    // Gradien II
    printf("\n\nGradien II\n");
    printf("Masukkan nilai absis I: ");
    scanf("%d", &x3.abs);

    printf("Masukkan nilai ordinat I: ");
    scanf("%d", &y3.ord);

    g2.p1.abs = x3.abs;
    g2.p1.ord = y3.ord;
    printf("\nNilai Point I (%d,%d)\n", x3.abs, y3.ord);

    printf("\nMasukkan nilai absis II: ");
    scanf("%d", &x4.abs);

    printf("Masukkan nilai ordinat II: ");
    scanf("%d", &y4.ord);

    g2.p2.abs = x4.abs;
    g2.p2.ord = y4.ord;
    printf("\nNilai Point II (%d,%d)\n", x4.abs, y4.ord);

    if(g2.p2.ord - g2.p1.ord == 0) {
        printf("\n\nNilai m2 tidak boleh sama dengan 0\n\n");
        exit(0);
    
    } else {
        m2 = (g2.p2.ord - g2.p1.ord) / (g2.p2.abs - g2.p1.abs);
        printf("\nNilai m2 = %f\n", m1);
    }

    if((m1 * m2) == -1) {
        printf("\n\nGaris saling tegak lurus\n\n");

    } else {
        printf("\n\nGaris tidak saling tegak lurus\n\n");
    }

    return 0;
}
