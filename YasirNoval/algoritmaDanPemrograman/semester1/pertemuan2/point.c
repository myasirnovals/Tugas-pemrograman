/*
    Program: point.c
    Author: 2350081004/Muhamad Yasir Noval
    Date: 18 Oktober 2023
    Description: latihan untuk mencari kuadran dari nilai bilangan bulat
    yang diinputkan oleh pengguna
*/

#include <stdio.h>
#include <stdlib.h>

// tipe bentukan untuk membuat point
typedef struct {
    int abs, ord
} Point;

int main() {
    // KAMUS
    Point x, y;

    // ALGORITMA
    printf("Masukan absis: ");
    scanf("%d", &x.abs);

    printf("Masukan ordinal: ");
    scanf("%d", &y.ord);

    if (x.abs > 0 && y.ord > 0) {
        printf("titik (%d, %d) berada di kuadran I", x.abs, y.ord);
    } else if (x.abs < 0 && y.ord > 0) {
        printf("titik (%d, %d) berada di kuadran II", x.abs, y.ord);
    } else if (x.abs < 0 && y.ord < 0) {
        printf("titik (%d, %d) berada di kuadran III", x.abs, y.ord);
    } else if (x.abs > 0 && y.ord < 0) {
        printf("titik (%d, %d) berada di kuadran IV", x.abs, y.ord);
    } else {
        printf("titik (%d, %d) tidak berada di kuadran manapun", x.abs, y.ord);
    }

    return 0;
}