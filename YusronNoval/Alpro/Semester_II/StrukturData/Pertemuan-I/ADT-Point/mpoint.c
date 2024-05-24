/*
    Program: main.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Header file dari prototype point
    Tanggal: 15/03/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.c"

int main() {
    // Kamus
    POINT P1,P2,P3,P4;
    int x,y;

    // Algoritma
    BacaPoint(&P1);
    printf("Nilai P1 = ");
    CetakPoint(P1);
    printf("\n");

    CreatePoint(&P2);
    printf("Nilai P2 = ");
    CetakPoint(P2);
    printf("\n");

    printf("\nInputkan nilai X baru: ");
    scanf("%d", &x);
    printf("Inputkan nilai Y baru: ");
    scanf("%d", &y);
    SetAbsis(&P3, x);
    SetOrdinat(&P3, y);
    printf("Nilai P3 = ");
    CetakPoint(P3);
    printf("\n");

    P4 = P1;
    printf("Nilai P4 = ");
    CetakPoint(P4);
    printf("\n");

    printf("\nPengecekan Operator Relasional\n");
    if(EQ(P1,P2)) {
        printf("NIlai P1 sama dengan P2\n");
    }
    if(NEQ(P1,P2)) {
        printf("Nilai P1 tidak sama dengan P2\n");
    }
    if(LT(P1,P2)) {
        printf("Nilai P1 lebih kecil dari P2\n");
    }
    if(MT(P1,P2)) {
        printf("Nilai P1 lebih besar dari P2\n");
    }
    printf("\n");

    if(EQ(P3,P1)) {
        printf("NIlai P3 sama dengan P1\n");
    }
    if(NEQ(P3,P1)) {
        printf("Nilai P3 tidak sama dengan P1\n");
    }
    if(LT(P3,P1)) {
        printf("Nilai P3 lebih kecil dari P1\n");
    }
    if(MT(P3,P1)) {
        printf("Nilai P3 lebih besar dari P1\n");
    }
    printf("\n");

    printf("\nPosisi P3 digeser ke Sumbu Y (SbY)\n");
    GeserKeSbY(&P3);
    printf("NIlai P3 = ");
    CetakPoint(P3);
    printf("\n");

    printf("\nJika P4 di mirrorkan ke Sumbu Y (SbY)\n");
    P4 = MirrorOf(P4, false, true);
    printf("Nilai P4 = ");
    CetakPoint(P4);
    printf("\n");

    printf("\nPengecekan Operator Posisi Origin\n");
    if(IsOrigin(P1)) {
        printf("Nilai P1 berada di Origin\n");
    }
    if(IsOrigin(P2)) {
        printf("Nilai P2 berada di Origin\n");
    }
    if(IsOrigin(P3)) {
        printf("Nilai P3 berada di Origin\n");
    }
    if(IsOrigin(P4)) {
        printf("Nilai P4 berada di Origin\n");
    }
    printf("\n");

    printf("\nPengecekan Operator Posisi Sumbu X\n");
    if(IsOnSbX(P1)) {
        printf("Nilai P1 berada di sumbu X\n");
    }
    if(IsOnSbX(P2)) {
        printf("Nilai P2 berada di sumbu X\n");
    }
    if(IsOnSbX(P3)) {
        printf("Nilai P3 berada di sumbu X\n");
    }
    if(IsOnSbX(P4)) {
        printf("Nilai P4 berada di sumbu X\n");
    }
    printf("\n");

    printf("\nPengecekan Operator Posisi Sumbu Y\n");
    if(IsOnSbY(P1)) {
        printf("Nilai P1 berada di sumbu Y\n");
    }
    if(IsOnSbY(P2)) {
        printf("Nilai P2 berada di sumbu Y\n");
    }
    if(IsOnSbY(P3)) {
        printf("Nilai P3 berada di sumbu Y\n");
    }
    if(IsOnSbY(P4)) {
        printf("Nilai P4 berada di sumbu Y\n");
    }
    printf("\n");

    printf("\nPengecekan Operator Posisi Kuadran\n");
    printf("Nilai P1 berada di Kuadran: %d\n", Kuadran(P1));
    printf("Nilai P2 berada di Kuadran: %d\n", Kuadran(P2));
    printf("Nilai P3 berada di Kuadran: %d\n", Kuadran(P3));
    printf("Nilai P4 berada di Kuadran: %d\n", Kuadran(P4));

    printf("\nPengecekan Operator Jarak Posisi\n");
    printf("Jarak P1 dari Origin: %.2f\n",JarakO(P1));
    printf("Jarak P2 dari Origin: %.2f\n",JarakO(P2));
    printf("Jarak P3 dari Origin: %.2f\n",JarakO(P3));
    printf("Jarak P4 dari Origin: %.2f\n",JarakO(P4));

    return 0;
}