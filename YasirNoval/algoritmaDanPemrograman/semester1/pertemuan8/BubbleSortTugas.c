/**
 * Program: BubbleSortTugas.c
 * Author: 2350081004/Muhamad Yasir Noval
 * Date: 12 Desember 2023
 * Description: Program untuk mengurutkan bilangan
 * dari data yang ada didalam tabel secara Descending
 * dan menyisipkan data pada bilangan tertentu
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

void UrutBubbleDes(TabInt *T);

void SisipBil(TabInt *T, int x, int y);

int main() {
    // kamus
    int i, j;
    int tmp;
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

    UrutBubbleDes(&MyTab);
    printf("Isi Tabel Sesudah Terurut Secara Descending\n");
    CetakTab(MyTab);

    printf("\nMasukan bilangan i: ");
    scanf("%d", &i);

    printf("Masukan bilangan j: ");
    scanf("%d", &j);

    SisipBil(&MyTab, i, j);


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

void UrutBubbleDes(TabInt *T) {
    // kamus lokal
    int i, j;
    int N;

    // algoritma
    N = (*T).neff;

    for (i = N; i > 1; i--) {
        for (j = 2; j <= i; j++) {
            if ((*T).T[j - 1] < (*T).T[j]) {
                // pertukaran tempat
                Tukar(T, j);
            }
        }
    }
}

void SisipBil(TabInt *T, int x, int y) {
    // kamus lokal
    int index, i;

    // algoritma
    index = -1;

    for (i = 1; i <= (*T).neff; i++) {
        if ((*T).T[i] == y) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        if ((*T).neff < Mak) {
            (*T).neff++;
            (*T).T[(*T).neff] = x;
        }
    } else {
        if ((*T).neff < Mak) {
            for (i = (*T).neff + 1; i > index + 1; i--) {
                (*T).T[i] = (*T).T[i -1];
            }
            (*T).T[index + 1] = x;
            (*T).neff++;
        }
    }

    CetakTab(*T);
}