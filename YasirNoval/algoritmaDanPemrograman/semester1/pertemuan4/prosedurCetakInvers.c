/**
 * Program: prosedurCetakInvers.c
 * Author: 2350081004/Muhamad Yasir Noval
 * Date: ...............
 * Description: .............
 */

#include <conio.h>
#include <stdio.h>
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

// Main Driver
int main() {
    // KAMUS
    TabInt MyTab;
    int N;

    // ALGORITMA
    CreateTab(&MyTab);

    printf("Masukan bil: ");
    scanf("%d", &N);

    while(N != 999) {
        AddElm(&MyTab, N);
        printf("Masukan bil: ");
        scanf("%d", &N);
    }

    printf("Cetak Tabel\n");
    CetakTab(MyTab);

    printf("\nCetak Tabel Genap\n");
    CetakGenap(MyTab);

    printf("\nCetak Tabel Invers\n");
    CetakInvers(MyTab);

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