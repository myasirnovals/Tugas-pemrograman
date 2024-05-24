/*
    Program: garis.c
    Author: 2350081004/Muhamad Yasir Noval
    Date: 18 Oktober 2023
    Description: Latihan untuk menentukan gradien 1 dan gradien 2 apakah sejajar
    atau tidak berdasarkan rumus m = (y2 - y1) / (x2 - x1)
*/

#include <stdio.h>
#include <stdlib.h>

// tipe bentukan untuk membuat point
typedef struct {
    int abs, ord;
} Point;

// tipe bentukan untuk membuat garis
typedef struct {
    Point p1, p2;
} Garis;

int main() {
    // KAMUS
    Point x1, y1, x2, y2;
    Point x3, y3, x4, y4;
    Garis g1, g2;
    double m1, m2;

    // ALGORITMA
    // gradien pertama
    printf("Gradien Pertama\n");
    printf("Masukan nilai absis pertama: ");
    scanf("%d", &x1.abs);

    printf("Masukan nilai ordinal pertama: ");
    scanf("%d", &y1.ord);

    g1.p1.abs = x1.abs;
    g1.p1.ord = y1.ord;
    printf("Titik pertama (%d, %d)\n", g1.p1.abs, g1.p1.ord);

    printf("masukan nilai absis kedua: ");
    scanf("%d", &x2.abs);

    printf("masukan nilai ordinal kedua: ");
    scanf("%d", &y2.ord);

    g1.p2.abs = x2.abs;
    g1.p2.ord = y2.ord;
    printf("Titik kedua (%d, %d)\n", g1.p2.abs, g1.p2.ord);

    // mengecek apakah x2 - x1 tidak sama dengan 0
    if ((g1.p2.abs - g1.p1.abs) != 0) {
        // Menghitung gradien pertama
        m1 = (double) (g1.p2.ord - g1.p1.ord) / (double) (g1.p2.abs - g1.p1.abs);
        printf("gradien pertama m1 = (%d - %d) / (%d - %d)\n", g1.p2.ord, g1.p1.ord, g1.p2.abs, g1.p1.abs);
        printf("m1 = %f\n", m1);
    } else {
        printf("Error: tidak bisa dibagi dengan nol");
        return 0;
    }

    // gradien kedua
    printf("Gradien Kedua\n");
    printf("Masukan nilai absis pertama: ");
    scanf("%d", &x3.abs);

    printf("Masukan nilai ordinal pertama: ");
    scanf("%d", &y3.ord);

    g2.p1.abs = x3.abs;
    g2.p1.ord = y3.ord;
    printf("Titik pertama (%d, %d)\n", g2.p1.abs, g2.p1.ord);

    printf("masukan nilai absis kedua: ");
    scanf("%d", &x4.abs);

    printf("masukan nilai ordinal kedua: ");
    scanf("%d", &y4.ord);

    g2.p2.abs = x4.abs;
    g2.p2.ord = y4.ord;
    printf("Titik kedua (%d, %d)\n", g2.p2.abs, g2.p2.ord);

    // mengecek apakah x4 - x3 tidak sama dengan 0
    if ((g2.p2.abs - g2.p1.abs) != 0) {
        // Menghitung gradien kedua
        m2 = (double) (g2.p2.ord - g2.p1.ord) / (double) (g2.p2.abs - g2.p1.abs);
        printf("gradien kedua m2 = (%d - %d) / (%d - %d)\n", g2.p2.ord, g2.p1.ord, g2.p2.abs, g2.p1.abs);
        printf("m2 = %f\n", m2);
    } else {
        printf("Error: tidak bisa dibagi dengan nol");
        return 0;
    }

    // mengecek jika gradien pertama sama dengan gradien kedua
    if ((m1 * m2) == -1) {
        printf("m1 * m2 = %f * %f = %f\n", m1, m2, m1 * m2);
        printf("Garis saling tegak lurus");
    } else {
        printf("m1 * m2 = %f * %f = %f\n", m1, m2, m1 * m2);
        printf("Garis tidak saling tegak lurus");
    }

    return 0;
}