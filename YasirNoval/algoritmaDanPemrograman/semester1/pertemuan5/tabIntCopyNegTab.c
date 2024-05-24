/**
 * Program: tabIntCopyNegTab.c
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

TabInt CopyNegTab(TabInt T);

// Main Driver
int main() {
    // KAMUS
    TabInt MyTab;
    TabInt MyTab1;
    int N;

    // ALGORITMA
    CreateTab(&MyTab);

    printf("Masukan bil: ");
    scanf("%d", &N);

    while (N != 999) {
        AddElm(&MyTab, N);
        printf("Masukan bil: ");
        scanf("%d", &N);
    }

    printf("\nTabel\n");
    CetakTab(MyTab);

    printf("\n\nBanyak Elemen: %d\n", getJumElm(MyTab));
    printf("\nJumlah Elemen: %d\n", SumElm(MyTab));

    printf("\nTabel Negasi\n");
    MyTab1 = CopyNegTab(MyTab);
    CetakTab(MyTab1);

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

TabInt CopyNegTab(TabInt T) {
    // Kamus
    TabInt MyTab1;
    int i;

    // Algoritma
    MyTab1.neff = 0;
    for (i = 1; i <= T.neff; i++) {
        MyTab1.neff = MyTab1.neff + 1;
        MyTab1.Tb[i] = T.Tb[i] * -1;
    }

    return MyTab1;
}