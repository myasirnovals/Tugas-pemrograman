/**
 * Program: prosedur.c
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

    CetakTab(MyTab);

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