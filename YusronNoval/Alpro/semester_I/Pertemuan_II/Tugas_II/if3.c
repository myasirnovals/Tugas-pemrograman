/*
    Program: if3.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 17/10/2023
    Description: Program menghitung gaji total dengan tambahan masa kerja
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus
    long gatot, gapok, tjAnak, tjGol;
    int Anak, Gol, tjMk;

    // Algoritma
    printf("Input gapok: ");
    scanf("%d", &gapok);

    printf("Input jum.Anak: ");
    scanf("%d", &Anak);

    printf("Input gol: ");
    scanf("%d", &Gol);

    printf("Input MasaKerja: ");
    scanf("%d", &tjMk);

   // Untuk Tunjangan Golongan
    if(Gol == 1) {
        tjGol = 1000000;
        printf("\nTunjangan Golongan: Rp.1.000.000\n\n");
    
    } else if(Gol == 2) {
        tjGol = 2000000;
        printf("\nTunjangan Golongan: Rp.2.000.000\n\n");
    
    } else {
        printf("\nTunjangan Golongan: Rp.0\n\n");
    }

    // Untuk Tunjangan Masa Kerja
    if(tjMk < 5) {
        tjMk = 500000;
        printf("Tunjangan Masa Kerja: Rp.500.000\n\n");
    
    } else if(tjMk <= 5 && tjMk < 10) {
        tjMk = 1000000;
        printf("Tunjangan Masa Kerja: Rp.1.000.000\n\n");
    
    } else {
        tjMk = 2000000;
        printf("Tunjangan Masa Kerja: Rp.2.000.000\n\n");
    }

    // Untuk Tunjangan Anak
    if(Anak <= 3) {
        tjAnak = Anak * 700000;
        printf("Tunjangan Anak: Rp.%d\n\n", tjAnak);
    
    } else {
        tjAnak = 3 * 700000;
        printf("Tunjangan Anak: Rp.%d\n\n", tjAnak);
    }

    // Hasil Gatot
    gatot = gapok + tjAnak + tjGol + tjMk;
    printf("Gaji Total: Rp.%ld\n\n", gatot);

    return 0;
}