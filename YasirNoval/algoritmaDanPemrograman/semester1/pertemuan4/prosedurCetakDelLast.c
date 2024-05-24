/**
 * Program: prosedurCetakDelLast.c
 * Author: 2350081004/Muhamad Yasir Noval
 * Date: 8 November 2023
 * Description: Membuat tabel integer dengan menggunakan
 * prosedur sebagai pemisah untuk aksi tertentu misalnya
 * cetak tabel, menambahkan elemen array, cetak tabel genap
 * membuat tabel, cetak tabel invers, insert first, dan
 * delete last
 */

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define nMax 10

typedef struct {
    int Tb[nMax + 1];
    int neff;
} TabInt;

// prototype
void CreateTab(TabInt *T);

void AddElm(TabInt *T, int x);

void CetakTab(TabInt T);

void CetakGenap(TabInt T);

void CetakInvers(TabInt T);

void InsertFirst(TabInt *T, int x);

void DelLast(TabInt *T, int *y);

// Main Driver
int main() {
    // KAMUS
    TabInt MyTab;
    int N, x, y;

    // ALGORITMA
    y = 0;
    CreateTab(&MyTab);

    printf("Masukan bil: ");
    scanf("%d", &N);

    while (N != 999) {
        AddElm(&MyTab, N);
        printf("Masukan bil: ");
        scanf("%d", &N);
    }

    printf("Masukan nilai X: ");
    scanf("%d", &x);

    printf("\nCetak Tabel\n");
    CetakTab(MyTab);

    printf("\n\nCetak Tabel Genap\n");
    CetakGenap(MyTab);

    printf("\n\nCetak Tabel Invers\n");
    CetakInvers(MyTab);

    printf("\n\nCetak Tabel Insert First\n");
    InsertFirst(&MyTab, x);

    printf("\n\nCetak Tabel Delete Last\n");
    DelLast(&MyTab, &y);

    return 0;
}

// Body of prototype
void CreateTab(TabInt *T) {
    (*T).neff = 0;
}

void AddElm(TabInt *T, int x) {
    if ((*T).neff < nMax) {
        (*T).neff++;
        (*T).Tb[(*T).neff] = x;
    }
}

void InsertFirst(TabInt *T, int x) {
    int last, i;

    last = (*T).neff;

    // menggeser data
    if ((*T).neff < nMax) {
        for (i = 1; i <= (*T).neff; i++) {
            (*T).Tb[last + 1] = (*T).Tb[last];
            last--;
        }
        (*T).Tb[last + 1] = x;
        (*T).neff++;
    }

    // mencetak tabel
    for (i = 1; i <= (*T).neff; i++) {
        printf("<%d>", (*T).Tb[i]);
    }
}

void DelLast(TabInt *T, int *y) {
    int last, i, tmp;

    last = (*T).neff;

    // mengambil data terakhir dan memasukannya kedalam variabel tmp
    if (last < nMax) {
        for (i = 1; i <= (*T).neff; i++) {
            tmp = (*T).Tb[last];
        }
        *y = tmp;
        (*T).neff--;
    }

    // mencetak tabel
    for (i = 1; i <= (*T).neff; i++) {
        printf("<%d>", (*T).Tb[i]);
    }
    printf("\nY = %d", *y);
}

void CetakGenap(TabInt T) {
    int i;

    for (i = 1; i <= T.neff; i++) {
        if (T.Tb[i] % 2 == 0) {
            printf("<%d>", T.Tb[i]);
        }
    }
}

void CetakTab(TabInt T) {
    int i;

    for (i = 1; i <= T.neff; i++) {
        printf("<%d>", T.Tb[i]);
    }
}

void CetakInvers(TabInt T) {
    int i;

    for (i = T.neff; i >= 1; i--) {
        printf("<%d>", T.Tb[i]);
    }
}