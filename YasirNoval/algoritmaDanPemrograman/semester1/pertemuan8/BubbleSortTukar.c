/**
 * Program: BubbleSortTukar.c
 * Author: 2350081004/Muhamad Yasir Noval
 * Date: 12 Desember 2023
 * Description: Program untuk mengurutkan bilangan
 * dari data yang ada didalam tabel secara Ascending
 * dengan menggunakan prosedur tukar dalam mengurutkan
 * data nya
 */

#include <stdio.h>
#include <conio.h>

#define Mak 20

typedef struct {
    int T[Mak + 1];
    int neff;
} TabInt;

// prototype
void CreateTab(TabInt *T);

void IsiTab(TabInt *T, int x);

void CetakTab(TabInt T);

void UrutBubble(TabInt *T);

void Tukar(TabInt *T, int j);

int main() {
    // kamus
    int x;
    TabInt MyTab;

    // Algoritma
    CreateTab(&MyTab);
    printf("Masukan Nilai: ");
    scanf("%d", &x);

    while (x != 9999) {
        IsiTab(&MyTab, x);
        printf("Masukan Nilai: ");
        scanf("%d", &x);
    }

    printf("\nIsi Tabel Belum Terurut\n");
    CetakTab(MyTab);

    UrutBubble(&MyTab);
    printf("Isi Tabel Sesudah Terurut\n");
    CetakTab(MyTab);

    return 0;
}

// body of prototype
void CreateTab(TabInt *T) {
    (*T).neff = 0;
}

void IsiTab(TabInt *T, int x) {
    if ((*T).neff < Mak) {
        (*T).neff++;
        (*T).T[(*T).neff] = x;
    }
}

void CetakTab(TabInt T) {
    // kamus lokal
    int i;

    // algoritma
    for (i = 1; i <= T.neff; i++) {
        printf("| %d ", T.T[i]);
    }

    printf("\n");
}

void UrutBubble(TabInt *T) {
    // kamus lokal
    int i, j;
    int N;

    // algoritma
    N = (*T).neff;

    for (i = N; i > 1; i--) {
        for (j = 2; j <= i; j++) {
            if ((*T).T[j - 1] > (*T).T[j]) {
                // pertukaran tempat
                Tukar(T, j);
            }
        }
    }
}

void Tukar(TabInt *T, int j) {
    // kamus lokal
    int tmp;

    // algoritma
    tmp = (*T).T[j - 1];
    (*T).T[j - 1] = (*T).T[j];
    (*T).T[j] = tmp;
}