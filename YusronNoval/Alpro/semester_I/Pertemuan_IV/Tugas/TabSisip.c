/*
    Program: TabSisip.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 01/11/2023
    Description: Membuat Tabel Integer Sisipkan nilai x dan y
*/
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define nMax 10

typedef struct {
    int T[nMax + 1];
    int neff;
} TabInt;

int main() 
{
    // KAMUS
    TabInt MyTab;
    int i, y, x, N, index;

    // ALGORITMA
    // membuat tabel
    MyTab.neff = 0;

    printf("Membuat tabel\n");
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
    printf("\nTabel pertama\n");
    for (i = 1; i <= MyTab.neff; i++) {
        printf("%d ", MyTab.T[i]);
    }
    printf("\n\n");

    // menyisipkan nilai x di antara y
    printf("Masukan nilai X: ");
    scanf("%d", &x);

    printf("Masukan nilai Y: ");
    scanf("%d", &y);

    index = -1;

    for (i = 1; i <= MyTab.neff; i++) {
        if (MyTab.T[i] == y) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        // jika y tidak ditemukan di dalam array, tempatkan x di akhir
        if (MyTab.neff < nMax) {
            MyTab.neff++;
            MyTab.T[MyTab.neff] = x;
        }
    } else {
        // jika y ditemukan, masukan x setelah y
        if (MyTab.neff < nMax) {
            for (i = MyTab.neff + 1; i > index + 1; i--) {
                MyTab.T[i] = MyTab.T[i - 1];
            }
            MyTab.T[index + 1] = x;
            MyTab.neff++;
        }
    }

    // cetak tabel
    printf("\nTabel kedua\n");
    for (i = 1; i <= MyTab.neff; i++) {
        printf("%d ", MyTab.T[i]);
    }

    printf("\n\n");

    return 0;
}