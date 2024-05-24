/**
 * Program: main.c
 * Author: (2350081004, Muhamad Yasir Noval)
 * Kelas: A
 * Deskripsi: Contoh main driver dari ADT Jam
 * tanggal: 15 Maret 2024
 */

#include "app/jam.c"
#include <stdio.h>
#include <conio.h>

int main() {
    // Kamus Data
    JAM J1, J2, J3, J4;
    int tambahanDetik;

    // Algoritma
    ReadJam(&J1);

    printf("Nilai J1 = ");
    PrintJam(J1);
    printf("\n");

    J2 = NextDetik(J1);
    printf("Nilai J2 = ");
    PrintJam(J2);
    printf("\n");

    printf("Masukan nilai N detik (0 .. 59) : ");
    scanf("%d", &tambahanDetik);

    J3 = NextNDetik(J1, tambahanDetik);
    printf("Nilai J3 = ");
    PrintJam(J3);
    printf("\n");

    J4 = J1;
    printf("Nilai J4 = ");
    PrintJam(J4);
    printf("\n");

    printf("\nPengecekan Operator Relasional\n");
    if (JEQ(J1, J2)) {
        printf("nilai J1 sama dengan J2\n");
    }

    if (JLT(J1, J2)) {
        printf("nilai J1 lebih kecil dari J2\n");
    }

    if (JGT(J1, J2)) {
        printf("nilai J1 lebih besar dari J2\n");
    }

    if (JEQ(J3, J1)) {
        printf("nilai J3 sama dengan J1\n");
    }

    if (JLT(J3, J1)) {
        printf("nilai J3 lebih kecil dari J1\n");
    }

    if (JGT(J3, J1)) {
        printf("nilai J3 lebih besar dari J1\n");
    }

    if (JEQ(J1, J4)) {
        printf("nilai J1 sama dengan J4\n");
    }

    if (JLT(J1, J4)) {
        printf("nilai J1 lebih kecil dari J4\n");
    }

    if (JGT(J1, J4)) {
        printf("nilai J1 lebih besar dari J4\n");
    }

    Reset(&J4);
    printf("nilai J4 = ");
    PrintJam(J4);
    printf("\n");

    return 0;
}
