/**
 * Program: sapa.c
 * Author: 2350081004/Muhamad Yasir Noval
 * Date: 8 November 2023
 * Description: Program yang menerima masukan sebuah
 * string untuk nama, serta integer untuk umur. Program
 * untuk memanggil prosedur bernama hello, dengan jumlah
 * argumen 2 buah, yaitu: sebuah string untuk variabel
 * nama dan integer untuk variabel umur
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hallo(char sNama[], int nUmur);

int main() {
    // KAMUS
    int umur;
    char nama[100];

    // ALGORITMA
    printf("Masukan nama anda: ");
    scanf("%[^\n]", &nama);

    printf("Masukan umur anda: ");
    scanf("%d", &umur);

    hallo(nama, umur);

    return 0;
}

void hallo (char sNama[], int nUmur) {
    if (nUmur < 17) {
        printf("Halo dik-%s\n", sNama);
        printf("Kamu belum cukup dewasa");
    } else {
        printf("Hallo kak-%s\n", sNama);
        printf("Kamu sudah cukup dewasa");
    }
}