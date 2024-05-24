/**
 * Program: InsertionSort.c
 * Author: 2350081004/Muhamad Yasir Noval
 * Date: 22 Desember 2023
 * Description: pengurutan data menggunakan insertion
 * sort
 */

#include <stdio.h>
#include <stdlib.h>

#define nMax 10

typedef struct {
    int Tb[nMax + 1];
    int neff;

} TabInt;

void createTab(TabInt *T);

void addElm(TabInt *T, int x);

void cetakTab(TabInt T);

void insertSort(TabInt *T);

int main() {
    // Kamus
    TabInt M;
    int N;

    // Algoritma
    createTab(&M);
    printf("Masukan bilangan: ");
    scanf("%d", &N);

    while (N != 999) {
        addElm(&M, N);
        printf("Masukan bilangan: ");
        scanf("%d", &N);
    }

    printf("\nTabel sebelum terurut\n");
    cetakTab(M);

    printf("\nTabel setelah terurut\n");
    insertSort(&M);
    cetakTab(M);

    return 0;
}

void createTab(TabInt *T) {
    (*T).neff = -1;
}

void addElm(TabInt *T, int x) {
    if ((*T).neff < nMax) {
        (*T).neff++;
        (*T).Tb[(*T).neff] = x;
    }
}

void cetakTab(TabInt T) {
    int i;

    for (i = 0; i <= T.neff; i++) {
        printf("<%d>", T.Tb[i]);
    }
    printf("\n");
}

void insertSort(TabInt *T) {
    int i, j, idx;

    for (i = 1; i <= (*T).neff; i++) {
        idx = (*T).Tb[i];
        j = i - 1;

        while (j >= 0 && (*T).Tb[j] > idx) {
            (*T).Tb[j + 1] = (*T).Tb[j];
            j--;
        }

        (*T).Tb[j + 1] = idx;
    }
}