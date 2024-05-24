/**
 * Program: proc_2.c
 * Author: 2350081004/Muhamad Yasir Noval
 * Date: 8 November 2023
 * Description: program untuk memanggil prosedur bernama
 * tukar yaitu melakukan pertukaran dari 3 buah masukan
 * bilangan bulat sebagai berikut : a = A, b = B, c = C
 * menjadi a = C, b = A, c = B
 */

#include <stdio.h>
#include <conio.h>

// program untuk memanggil sebuah prosedur

// KAMUS Global
// Definisi prototype
void proc_tukar (int *a, int *b, int *c);

// I.S. : a, b, c terdefinisi sembarang
// F.S. : a, b dan c saling bertukar nilai

int main() {
    // KAMUS lokal pada main driver
    int bil1, bil2, bil3;

    // KAMUS
    printf("Masukan bilangan 1: ");
    scanf("%d", &bil1);

    printf("Masukan bilangan 2: ");
    scanf("%d", &bil2);

    printf("Masukan bilangan 3: ");
    scanf("%d", &bil3);

    // pemanggilan prosedur tukar
    proc_tukar(&bil1, &bil2, &bil3);
    printf("Hasil pertukaran a:%d; b%d; c:%d", bil1, bil2, bil3);

    return 0;
}

// realisasi prototype
void proc_tukar(int *a, int *b, int *c) {
    // I.S. : a, b, c terdefinisi sembarang
    // F.S. : a, b dan c saling bertukar nilai

    // KAMUS lokal
    int tmp;

    // ALGORITMA
    tmp = *c;
    *c = *b;
    *b = *a;
    *a = tmp;
}