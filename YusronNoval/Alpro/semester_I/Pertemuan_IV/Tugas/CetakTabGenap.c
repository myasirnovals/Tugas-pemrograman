/*
    Program: TabInvers.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 31/10/2023
    Description: Membuat Tabel Integer Invers menggunakan Bahasa C dan Array
*/
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define nMax 10

typedef struct {
    int Tb[nMax+1];
    int neff;

} TabInt;

// Prototype
void CreateTable(TabInt *T);
void AddElm(TabInt *T, int x);
void CetakTable(TabInt T);
void CetakTabGenap(TabInt T);

// Main Driver
int main()
{
    // Kamus
    TabInt myTab;
    int N;

    // Algoritma
    CreateTable(&myTab);
    printf("Masukan bilangan: ");
    scanf("%d", &N);

    while(N != 999) {
        AddElm(&myTab, N);
        printf("Masukan bilangan: ");
        scanf("%d", &N);
    }

    CetakTable(myTab);
    CetakTabGenap(myTab);

    return 0;
}

// Body of prototype
void CreateTable(TabInt *T) {
    (*T).neff = 0;
}

void AddElm(TabInt *T, int x) {
    if((*T).neff < nMax) {
        (*T).neff++;
        (*T).Tb[(*T).neff] = x;
    }
}

void CetakTable(TabInt T) {
    int i;
    printf("\n");
    
    for(i=1; i <= T.neff; i++) {
        printf("<%d>", T.Tb[i]);
    }
    printf("\n\n");
}

void CetakTabGenap(TabInt T) {
    int i;
    printf("\n");

    for(i=1; i <= T.neff; i++) {
        if(T.Tb[i] % 2 == 0) {
            printf("<%d>", T.Tb[i]);
        }
    }
    printf("\n\n");
}