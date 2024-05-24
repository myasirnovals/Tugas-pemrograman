/*
    Program: InsertionSort_1.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 12/12/2023
    Description:
*/
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define nMax 10

typedef struct {
    int Tb[nMax+1];
    int neff;

} TabInt;

void createTab(TabInt *T);
void addElm(TabInt *T, int x);
void cetakTab(TabInt T);
void insertSort(TabInt *T);

int cariBiner(TabInt T, int x);

int main()
{
    // Kamus
    TabInt myTab;
    int N;

    // Algoritma
    createTab(&myTab);
    printf("Masukan bilangan: ");
    scanf("%d", &N);

    while(N != 999) {
        addElm(&myTab, N);
        printf("Masukan bilangan: ");
        scanf("%d", &N);
    }

    printf("\n");
    cetakTab(myTab);
    insertSort(&myTab);
    cetakTab(myTab);
    printf("\n");

    printf("Cari Biner: ");
    scanf("%d", &N);

    if(cariBiner(myTab, N)) {
        printf("Biner = %d", N);
    
    } else {
        printf("Biner = 0");
    }

    printf("\n\n");

    return 0;
}

void createTab(TabInt *T) {
    (*T).neff = -1;
}

void addElm(TabInt *T, int x) {
    if((*T).neff < nMax) {
        (*T).neff++;
        (*T).Tb[(*T).neff] = x;
    }
}

void cetakTab(TabInt T) {
    int i;

    for(i=0; i<=T.neff; i++) {
        printf("<%d>", T.Tb[i]);
    }
    printf("\n");
}

void insertSort(TabInt *T) {
    int i,j,idx;

    for(i=1; i<=(*T).neff; i++) {
        idx = (*T).Tb[i];
        j = i -1;

        while(j>=0 && (*T).Tb[j] > idx) {
            (*T).Tb[j+1] = (*T).Tb[j];
            j--;
        }

        (*T).Tb[j+1] = idx;
    }
}

int cariBiner(TabInt T, int x) {
    boolean ketemu;
    int i;

    ketemu = false;
    i = 1;
    while (i <= T.neff && !ketemu) {
        if(T.Tb[i] % 2 == 0) {
            ketemu = true;
        
        } else {
            i++;
        }
    }
    
    return ketemu;
}