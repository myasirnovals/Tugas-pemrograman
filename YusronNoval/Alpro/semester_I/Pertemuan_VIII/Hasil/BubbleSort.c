/*
    Program: BubbleSort.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 12/12/2023
    Description:
*/
#include <stdio.h>
#include <stdlib.h>

#define nMax 20

typedef struct {
    int Tb[nMax+1];
    int neff;

} TabInt;

void createTab(TabInt *T);
void isiTab(TabInt *T, int x);
void cetakTab(TabInt T);
void urutBubble(TabInt *T);

int main()
{
    // Kamus
    int i,j,tmp,N;
    TabInt myTab;

    // Algoritma
    createTab(&myTab);
    printf("Masukan bilangan: ");
    scanf("%d", &N);

    while (N != 999) {
        isiTab(&myTab, N);
        printf("Masukan bilangan: ");
        scanf("%d", &N);
    }

    printf("\n");
    printf("Isi tabel yang belum terurut\n");
    cetakTab(myTab);
    urutBubble(&myTab);

    printf("\n");
    printf("Isi tabel yang sudah terurut\n");
    cetakTab(myTab);
    printf("\n\n");

    return 0;
}

void createTab(TabInt *T) {
    (*T).neff = 0;
}

void isiTab(TabInt *T, int x) {
    if((*T).neff < nMax) {
        (*T).neff++;
        (*T).Tb[(*T).neff] = x;
    }
}

void cetakTab(TabInt T) {
    int i;

    for(i=1; i <= T.neff; i++) {
        printf("<%d>", T.Tb[i]);
    }
    printf("\n");
}

void urutBubble(TabInt *T) {
    int i, j, tmp, N;

    N = (*T).neff;

    for(i=N; i>1; i--) {
        for(j=2; j<=i; j++) {
            if((*T).Tb[j-1] > (*T).Tb[j]) {
                tmp = (*T).Tb[j-1];
                (*T).Tb[j-1] = (*T).Tb[j];
                (*T).Tb[j] = tmp;
            }
        }
    }
}