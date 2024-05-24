/**
 * Program: pros_1.c
 * Author: 2350081004/Muhamad Yasir Noval
 * Date: 8 November 2023
 * Description: program untuk memanggil prosedur bernama
 * tukar yaitu melakukan pertukaran dari 2 buah masukan
 * bilangan bulat sebagai berikut : a = A, b = B menjadi a = B, b = A
 */

#include <stdio.h>
#include <conio.h>

// program untuk memanggil sebuah prosedur

// KAMUS Global
// Definisi prototype
void tukar (int *a, int *b);

// I.S. : a, b terdefinisi sembarang
// F.S. : a dan b saling bertukar nilai

int main() {
    // KAMUS lokal pada main driver
    int bil1, bil2;

    // KAMUS
    printf("Masukan bilangan 1: ");
    scanf("%d", &bil1);

    printf("Masukan bilangan 2: ");
    scanf("%d", &bil2);

    // pemanggilan prosedur tukar
    tukar(&bil1, &bil2);
    printf("Hasil pertukaran a:%d; b%d", bil1, bil2);

    return 0;
}

// realisasi prototype
void tukar(int *a, int *b) {
    // I.S. : a, b terdefinisi sembarang
    // F.S. : a dan b saling bertukar nilai

    // KAMUS lokal
    int tmp;

    // ALGORITMA
    tmp = *a;
    *a = *b;
    *b = tmp;
}