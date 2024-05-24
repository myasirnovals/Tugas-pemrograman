/*
    Program: MaxSort.c
    Author: 2350081004/Muhamad Yasir Noval
    Date: 28 November 2023
    Description: program untuk mengurutkan nilai dari yang terkecil ke yang terbesar
*/
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define nMax 10

typedef struct {
    int Tb[nMax + 1];
    int neff;

} TabInt;

void CreateTab(TabInt *T);
void AddElm(TabInt *T, int x);
void MaxSort(TabInt *T);
void CetakTab(TabInt T);

int main() 
{
    // KAMUS
    TabInt MyTab;
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
    printf("\n");
    printf("\nTabel Maxsort\n");
    MaxSort(&MyTab);
    printf("\n\n");
    return 0;
}

void MaxSort(TabInt *T) {
    // Kamus lokal
    int j, i, tmp, Max, index;
    
    // Algortima
    for (j = (*T).neff; j >= 1; j--) {
        Max = (*T).Tb[1];
        index = 1;
        
        for (i = 2; i <= j; i++) {
            if ((*T).Tb[i] >= Max) {
                Max = (*T).Tb[i];
                index = i;
            }
        }
        tmp = (*T).Tb[j];
        (*T).Tb[j] = Max;
        (*T).Tb[index] = tmp;
    }
    
    for (i = 1; i <= (*T).neff; i++) {
        printf("<%d>", (*T).Tb[i]);
    }
}

// Body of Prototype
void CreateTab(TabInt *T) {
    // Kamus lokal
    // Algoritma
    (*T).neff = 0;
}

void AddElm(TabInt *T, int x) {
    // Kamus lokal
    // Algoritma
    if ((*T).neff < nMax) {
        (*T).neff++;
        (*T).Tb[(*T).neff] = x;
    }
}

void CetakTab(TabInt T) {
    // Kamus lokal
    int i;
    
    // Algoritma
    for (i = 1; i <= T.neff; i++) {
       printf("<%d>", T.Tb[i]);
    }
}