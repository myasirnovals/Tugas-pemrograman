/**
 * Program: main.c
 * Author: (2350081004, Muhamad Yasir Noval)
 * Kelas: A
 * Deskripsi: Header file dari prototype point
 * Tanggal: 15 Maret 2024
 */

#include "app/point.c"

#include <stdio.h>
#include <conio.h>

int main() {
    // Kamus
    POINT P1, P2, newPoint;

    // Algoritma
    // membuat point
    CreatePoint(&P1);
    CreatePoint(&newPoint);
    CreatePoint2(&P2, 5, 7);

    // membaca point 1
    BacaPoint(&P1);

    // cetak point 1 dan point 2
    CetakPoint(P1);
    printf("\n");
    CetakPoint(P2);

    // Mengambil nilai absis dan ordinat dari kedua point (P1, P2)
    printf("\n");
    printf("\nP1 Absis : %d", GetAbsis(P1));
    printf("\nP1 Ordinat : %d", GetAbsis(P1));
    printf("\nP2 Absis : %d", GetAbsis(P2));
    printf("\nP2 Ordinat : %d", GetAbsis(P2));
    printf("\n");

    // Megubah nilai absis dan ordinat dari kedua point (P1, P2)
    SetAbsis(&P1, -4);
    SetOrdinat(&P1, -7);
    SetAbsis(&P2, 7);
    SetOrdinat(&P2, -4);

    printf("\n");
    CetakPoint(P1);
    printf("\n");
    CetakPoint(P2);
    printf("\n");

    // Operasi relasional
    if (EQ(P1, P2) == true) {
        printf("\ntrue");
    } else {
        printf("\nfalse");
    }

    if (NEQ(P1, P2) == true) {
        printf("\ntrue");
    } else {
        printf("\nfalse");
    }

    if (LT(P1, P2) == true) {
        printf("\ntrue");
    } else {
        printf("\nfalse");
    }

    if (MT(P1, P2) == true) {
        printf("\ntrue");
    } else {
        printf("\nfalse");
    }

    // Menentukan P berada pada kuadran apa
    printf("\n");
    if (IsOrigin(P1) == true) {
        printf("\nPoint P1 tidak berada pada kuadran manapun\n");
    } else {
        printf("\nPoint P1 terletak di kuadran %d\n", Kuadran(P1));
    }

    if (IsOnSbX(P1) == true) {
        printf("\nP1 berada pada sumbu X\n");
    } else if (IsOnSbY(P1) == true) {
        printf("\nP1 berada pada sumbu Y\n");
    } else {
        printf("\nP1 tidak terletak pada sumbu apapun\n");
    }

    // Operasi lain terhadap type
    printf("\nJarak P1 dengan origin: %.2f\n", JarakO(P1));

    GeserKeSbX(&P1);
    CetakPoint(P1);
    printf("\n");

    GeserKeSbY(&P2);
    CetakPoint(P2);
    printf("\n");

    newPoint = MirrorOf(P1, IsOnSbX(P1), IsOnSbY(P1));
    CetakPoint(newPoint);
    printf("\n");

    return 0;
}
