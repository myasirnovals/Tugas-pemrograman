//
// Created by myasi on 11/10/2023.
//

// File : enum.c
// Deklarasi dan pemakaian type enumerasi

#include <stdio.h>

int main() {
    // KAMUS
    enum hari {
        senin, selasa, rabu, kamis, jumat, sabtu
    } hariku;

    enum {
        satu, dua, tiga
    } angka;

    enum {
        KEYWORD = 01, EXTERNAL = 04, STATIC = 04
    };

    typedef enum {
        merah, putih, kuning
    } warna;

    unsigned int flags;
    warna w = kuning;

    // ALGORITMA
    angka = tiga;
    printf("Angka %d \n", angka);

    hariku = 0;
    printf("Hari %d \n", hariku);

    printf("Masukkan sebuah angka [0..2] ");
    scanf("%d", &angka);
    printf("Angka %d \n", angka);

    flags = EXTERNAL;
    printf("flags %d \n", flags);

    printf("Warna = %d\n", w);

    return 0;

}