#include <stdio.h>
#include <stdlib.h>
#include "jam.c"

int main() {
    // JAM J, J2;
    // CreateJam(&J, 12, 30, 40);
    // PrintJam(J);

    // printf("\n\n");

    // printf("%d", GetHour(J));
    // printf("\n\n");

    // Kamus
    JAM J1, J2, J3, J4;
    int tambahanDetik;

    // Algoritma
    printf("=======Membaca Jam=======\n");
    ReadJam(&J1);

    printf("Nilai J1 = ");
    PrintJam(J1);
    printf("\n");

    printf("\n=======Tambah 1 Detik=======\n");
    J2 = NextDetik(J1);
    printf("Nilai J2 = ");
    PrintJam(J2);
    printf("\n");

    printf("\n=======Tambah Detik=======\n");
    printf("Masukan nilai N detik (0...59) : ");
    scanf("%d", &tambahanDetik);
    J3 = NextNDetik(J1, tambahanDetik);
    printf("Nilai J3 = ");
    PrintJam(J3);
    printf("\n");

    J4 = J1;
    printf("Nilai J4 = ");
    PrintJam(J4);
    printf("\n");

    printf("\n=======Pengecekan Operator Operasional=======\n");
    if(JEQ(J1,J2)) {
        printf("Nilai J1 sama dengan J2\n");
    }

    if(JLT(J1,J2)) {
        printf("Nilai J1 lebih kecil dari J2\n");
    }

    if(JGT(J1,J2)) {
        printf("Nilai J1 lebih besar dari J2\n");
    }
    printf("\n");

    if(JEQ(J3,J4)) {
        printf("Nilai J3 sama dengan J4\n");
    }

    if(JLT(J3,J4)) {
        printf("Nilai J3 lebih kecil dari J4\n");
    }

    if(JGT(J3,J4)) {
        printf("Nilai J3 lebih besar dari J4\n");
    }
    printf("\n");

    if(JEQ(J1,J4)) {
        printf("Nilai J1 sama dengan J4\n");
    }

    if(JLT(J1,J4)) {
        printf("Nilai J1 lebih kecil dari J4\n");
    }

    if(JGT(J1,J4)) {
        printf("Nilai J1 lebih besar dari J4\n");
    }
    // printf("\n");

    printf("\n=======Reset J4=======\n");
    Reset(&J4);
    printf("Nilai J4 = ");
    PrintJam(J4);
    printf("\n\n");

    return 0;
}