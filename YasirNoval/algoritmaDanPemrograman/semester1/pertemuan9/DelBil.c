/**
 * Program: DelBil.c
 * Author: 2350081004/Muhamad Yasir Noval
 * Date: 22 Desember 2023
 * Description: membuat prosedur dengan nama DelBil,
 * untuk menghapus sebuah elemen pada tabel. dengan
 * proses penghapusan dimulai dengan pencarian bilangan
 * yang akan dihapus menggunakan function CariBiner,
 * jika bilangan nya ditemukan maka proses penghapusan
 * dapat dilakukan namun jika bilangan nya tidak di-
 * temukan maka proses penghapusan tidak dapat dilakukan
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

void DelBil(TabInt *T, int x);

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
        printf("\nTabel setelah data terhapus\n");
        DelBil(&M, X);
    } else {
        printf("\nProses penghapusan tidak dapat dilakukan\n");
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

void DelBil(TabInt *T, int x) {
    // kamus lokal
    int i, index, data;

    // algoritma
    index = (*T).neff;

    // mencari bilangan
    data = CariBiner((*T), index, x);

    for (i = data + 1; i <= (*T).neff; i++) {
        (*T).Tb[i - 1] = (*T).Tb[i];
    }
    (*T).neff = (*T).neff - 1;
    cetakTab((*T));
}