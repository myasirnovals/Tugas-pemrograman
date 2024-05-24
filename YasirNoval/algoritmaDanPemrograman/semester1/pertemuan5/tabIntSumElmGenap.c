/**
 * Program: tabIntSumElmGenap.c
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

boolean CariElm(TabInt T, int X);

int SumElm(TabInt T);

int getJumElm(TabInt T);

int SumElmGenap(TabInt T);

// Main Driver
int main() {
    // KAMUS
    TabInt MyTab;
    int N;
    int x;

    // ALGORITMA
    CreateTab(&MyTab);

    printf("Masukan bil: ");
    scanf("%d", &N);

    while(N != 999) {
        AddElm(&MyTab, N);
        printf("Masukan bil: ");
        scanf("%d", &N);
    }

    printf("\nTabel\n");
    CetakTab(MyTab);

    printf("\n\nBanyak Elemen: %d\n", getJumElm(MyTab));
    printf("\nJumlah Elemen: %d\n", SumElm(MyTab));
    printf("\nJumlah Elemen Genap: %d\n", SumElmGenap(MyTab));

    printf("\nCari bil: ");
    scanf("%d", &N);

    if (CariElm(MyTab, N)) {
        printf("Ada");
    } else {
        printf("Tidak Ada");
    }

    return 0;
}

// Body of Prototype
void CreateTab(TabInt *T) {
    (*T).neff = 0;
}

void AddElm(TabInt *T, int x) {
    if ((*T).neff < nMax) {
        (*T).neff++;
        (*T).Tb[(*T).neff] = x;
    }
}

void CetakTab(TabInt T) {
    int i;

    for (i = 1; i <= T.neff; i++) {
        printf("<%d>", T.Tb[i]);
    }
}

boolean CariElm(TabInt T, int X) {
    // Kamus
    boolean ketemu;
    int i;

    // Algoritma
    ketemu = false;
    i = 1;

    while (i <= T.neff && !ketemu) {
        if (T.Tb[i] == X) {
            ketemu = true;
        } else {
            i++;
        }
    }

    return ketemu;
}

int SumElm(TabInt T) {
    // Kamus
    int sum;
    int i;

    // Algoritma
    sum = 0;

    for (i = 1; i <= T.neff; i++) {
        sum = sum + T.Tb[i];
    }

    return sum;
}

int getJumElm(TabInt T) {
    // Kamus
    int jum;

    // Algoritma
    jum = T.neff;

    return jum;
}

int SumElmGenap(TabInt T) {
    // Kamus
    int sum, i;

    // Algoritma
    sum = 0;
    for (i = 1; i <= T.neff; i++) {
        if (T.Tb[i] % 2 == 0) {
            sum = sum + T.Tb[i];
        }
    }

    return sum;
}