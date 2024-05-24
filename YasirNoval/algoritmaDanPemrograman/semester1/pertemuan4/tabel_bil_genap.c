/**
 * Program: tabel_bil_genap.c
 * Author: 2350081004/Muhamad Yasir Noval
 * Date: 1 November 2023
 * Description: membuat tabel dari array dan memasukan bilangan sesuai
 * yang diinputkan oleh pengguna, dengan hasil yang muncul hanya bilangan
 * genap saja
 */

#include <stdio.h>
#include <conio.h>
#include "boolean.h"

#define nMax 10

typedef struct {
    int T[nMax + 1];
    int neff;
}TabInt;

int main() {
    // KAMUS
    TabInt MyTab;
    int N;
    int i;

    // ALGORITMA
    MyTab.neff = 0;
    printf("Masukan bilangan: ");
    scanf("%d", &N);

    while (N != 999) {
        if (MyTab.neff < nMax) {
            MyTab.neff++;
            MyTab.T[MyTab.neff] = N;
        }

        printf("Masukan bilangan: ");
        scanf("%d", &N);
    }

    // cetak tabel
    for (i = 1; i <= MyTab.neff; i++) {
        if (MyTab.T[i] % 2 == 0) {
            printf("<%d>", MyTab.T[i]);
        }
    }

    return 0;
}