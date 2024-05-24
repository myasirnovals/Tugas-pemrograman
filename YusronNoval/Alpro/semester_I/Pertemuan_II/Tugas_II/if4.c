/*
    Program: if4.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 17/10/2023
    Description: Program menghitung gaji total dengan tambahan masa kerja dan usia tunjangan anak
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus
    long gatot, gapok, tjAnak1, tjAnak2, tjAnak22, tjAnak3, tjAnak32, tjAnak33, tjGol;
    int Anak, Gol, tjMk, UsiaAnak1, UsiaAnak2, UsiaAnak3;

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
    if(Anak == 1) {
        printf("Input Usia Anak1: ");
        scanf("%d", &UsiaAnak1);
        
        if(UsiaAnak1 <= 17) {
            tjAnak1 = 1 * 700000;
            printf("\n\nTunjangan Anak1: Rp.%d\n\n", tjAnak1);
        
        } else {
            tjAnak1 = 0;
            printf("\n\nAnak yang lebih umur-nya dari 17 tidak dapat tunjangan\n\n");
        }

        // Hasil Gatot

        gatot = gapok + tjAnak1 + tjGol + tjMk ;
        printf("Gaji Total: Rp.%ld\n\n", gatot);
    }
    
    else if(Anak == 2) {
        printf("Input Usia Anak1: ");
        scanf("%d", &UsiaAnak1);

        printf("Input Usia Anak2: ");
        scanf("%d", &UsiaAnak2);
        
        if(UsiaAnak1 <= 17) {
            tjAnak2 = 1 * 700000;
            printf("\n\nTunjangan Anak1: Rp.%d\n\n", tjAnak2);
        
        } else {
            tjAnak2 = 0;
            printf("\n\nAnak yang lebih umur-nya dari 17 tidak dapat tunjangan\n\n");
        }
        
        if(UsiaAnak2 <= 17) {
            tjAnak22 = 1 * 700000;
            printf("Tunjangan Anak2: Rp.%d\n\n", tjAnak22);
        
        } else {
            tjAnak22 = 0;
            printf("\n\nAnak yang lebih umur-nya dari 17 tidak dapat tunjangan\n\n");
        }

        // Hasil Gatot

        gatot = gapok + tjAnak2 + tjAnak22+ tjGol + tjMk ;
        printf("Gaji Total: Rp.%ld\n\n", gatot);
    }

    else if(Anak == 3) {
        printf("Input Usia Anak1: ");
        scanf("%d", &UsiaAnak1);

        printf("Input Usia Anak2: ");
        scanf("%d", &UsiaAnak2);

        printf("Input Usia Anak3: ");
        scanf("%d", &UsiaAnak3);

        if(UsiaAnak1 <= 17) {
            tjAnak3 = 1 * 700000;
            printf("\n\nTunjangan Anak1: Rp.%d\n\n", tjAnak3);
        
        } else {
            tjAnak3 = 0;
            printf("Anak yang lebih umur-nya dari 17 tidak dapat tunjangan\n\n");
        }
        
        if(UsiaAnak2 <= 17) {
            tjAnak32 = 1 * 700000;
            printf("Tunjangan Anak2: Rp.%d\n\n", tjAnak32);
        
        } else {
            tjAnak32 = 0;
            printf("Anak yang lebih umur-nya dari 17 tidak dapat tunjangan\n\n");
        }
        
        if(UsiaAnak3 <= 17) {
            tjAnak33 = 1 * 700000;
            printf("Tunjangan Anak3: Rp.%d\n\n", tjAnak33);
        
        } else {
            tjAnak33 = 0;
            printf("Anak yang lebih umur-nya dari 17 tidak dapat tunjangan\n\n");
        }
        

        // Hasil Gatot

        gatot = gapok + tjAnak3 + tjAnak32+  tjAnak33+ tjGol + tjMk ;
        printf("Gaji Total: Rp.%ld\n\n", gatot);

    } else {
        printf("Batas jumlah anak adalah 3 anak, lebih dari itu tidak akan mendapat tunjangan.\n\n");

        // Hasil Gatot
        gatot = gapok + tjGol + tjMk ;
        printf("Gaji Total: Rp.%ld\n\n", gatot);
    }

    return 0;
}