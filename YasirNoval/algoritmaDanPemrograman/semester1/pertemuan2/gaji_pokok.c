/*
    Program: gaji_pokok.c
    Author: 2350081004/Muhamad Yasir Noval
    Date: 17 Oktober 2023
    Description: latihan untuk mencari gaji total
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    // KAMUS
    long gaTot, gaPok, tjAnak, tjGol;
    int anak, gol;

    // ALGORITMA
    printf("Input Gaji Pokok: ");
    scanf("%d", &gaPok);

    printf("Input Jumlah Anak: ");
    scanf("%d", &anak);

    printf("Input Golongan: ");
    scanf("%d", &gol);

    // menentukan golongan yang diinputkan
    if (gol == 1) {
        tjGol = 1000000;
    } else if (gol == 2) {
        tjGol = 2000000;
    } else {
        tjGol = 0;
    }

    // menentukan jumlah anak yang diinputkan
    if (anak <= 3) {
        tjAnak = anak * 700000;
    } else {
        tjAnak = 3 * 700000;
    }

    gaTot = gaPok + tjAnak + tjGol;

    printf("Gaji Total = Rp.%ld + Rp.%ld + Rp.%ld\n", gaPok, tjAnak, tjGol);
    printf("Gaji Total = Rp.%ld", gaTot);

    return 0;
}
