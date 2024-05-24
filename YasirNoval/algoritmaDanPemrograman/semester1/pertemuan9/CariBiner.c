/**
 * Program: CariBiner.c
 * Author: 2350081004/Muhamad Yasir Noval
 * Date: 22 Desember 2023
 * Description: membuat function bernama CariBiner,
 * untuk mencari sebuah elemen pada tabel dengan
 * menggunakan metode pencarian bagi dua. jika di-
 * temukan kirim indexnya, jika tidak kirim 0
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

int CariBiner(TabInt T, int index, int x);

int main() {
    // Kamus
    TabInt M;
    int N, X, index;

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

    printf("\nMasukan nilai X: ");
    scanf("%d", &X);

    index = CariBiner(M, M.neff, X);

    if (index != -1) {
        printf("\nData ditemukan pada indeks %d\n\n", index);
    } else {
        printf("\nData tidak ditemukan index %d\n\n", 0);
    }

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

int CariBiner(TabInt T, int index, int x) {
    // kamus lokal
    int low = 0;
    int high = index - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (T.Tb[mid] == x) {
            return mid;
        } else if (T.Tb[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}