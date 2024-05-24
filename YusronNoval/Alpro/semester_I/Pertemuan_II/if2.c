/*
    Program: if2.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 17/10/2023
    Description: program menghitung gaji total
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus
    long gatot, gapok, tjAnak, tjGol;
    int Anak, Gol;

    // Algoritma
    printf("Input gapok: ");
    scanf("%d", &gapok);

    printf("Input jum.Anak: ");
    scanf("%d", &Anak);

    printf("Input gol: ");
    scanf("%d", &Gol);

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

    // Untuk Tunjangan Anak
    if(Anak <= 3) {
        tjAnak = Anak * 700000;
        printf("Tunjangan Anak: Rp.%d\n\n", tjAnak);
    
    } else {
        tjAnak = 3 * 700000;
        printf("Tunjangan Anak: Rp.%d\n\n", tjAnak);
    }

    // Hasil Gatot
    gatot = gapok + tjAnak + tjGol;
    printf("Gaji Total: Rp.%ld\n\n", gatot);

    return 0;
}