/*
    Program: TabIntAdvance.c
    Author: 2350081004/Muhamad Yasir Noval
    Date: 28 November 2023
    Description: Prorgram untuk membuat tabel, menambahkan elemen, mencetak tabel
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

boolean CariElm(TabInt T, int X);
int SumElm(TabInt T);
int SumElmGenap(TabInt T);
int getJumElm(TabInt T);
int getJumElmGanjil(TabInt T);

TabInt CopyNegTab(TabInt T);
boolean IsPrima(int n);

void MaxSort(TabInt *T);
void CekPrima(TabInt T);

// Main Driver
int main()
{
    // KAMUS
    TabInt MyTab;
    TabInt MyTab1;
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
    
    printf("\n\nBanyak Elemen: %d\n", getJumElm(MyTab));
    printf("Jumlah Elemen: %d\n", SumElm(MyTab));
    printf("Jumlah Elemen Genap: %d\n", SumElmGenap(MyTab));
    printf("\nTabel Ganjil\n");
    printf("\nBanyak Elemen Ganjil: %d\n", getJumElmGanjil(MyTab));
    printf("\nTabel Negasi\n");
    
    MyTab1 = CopyNegTab(MyTab);
    CetakTab(MyTab1);
    printf("\n\nTabel MaxSort\n");
    MaxSort(&MyTab);
    
    printf("\n\nCari Elemen Prima:\n");
    CekPrima(MyTab);
    
    printf("\n\nCari bil: ");
    scanf("%d", &N);
    
    if (CariElm(MyTab, N)) {
        printf("Ada");
        if (IsPrima(N) == true) {
            printf(", Bilangan %d prima", N);
        
        } else {
            printf(", Bilangan %d bukan prima", N);
        }
    
    } else {
        printf("Tidak Ada");
        
        if ( IsPrima(N) == true) {
        printf(", Bilangan %d prima", N);
        
        } else {
            printf(", Bilangan %d bukan prima", N);
        }
    }
    
    return 0;
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

boolean CariElm(TabInt T, int X) {
    // Kamus lokal
    boolean ketemu;
    int i;

    // Algoritma
    ketemu = false;
    i = 1;
    while (i <= T.neff && !ketemu) {
        if (T.Tb[i] == X) {
            ketemu = true;
        } else {
            i++;
        }
    }
    return ketemu;
}

boolean IsPrima(int n) {
    // Kamus lokal
    // Algoritma
    if (n == 2) {
        return true; // true
    } else if (n % 2 == 0 || n == 1) {
        return false; // false
    }
    return true;
}

int SumElm(TabInt T) {
    // Kamus lokal
    int sum;
    int i;

    // Algoritma
    sum = 0;
    for (i = 1; i <= T.neff; i++) {
        sum = sum + T.Tb[i];
    }
    return sum;
}

int SumElmGenap(TabInt T) {
    // Kamus lokal
    int sum, i;

    // Algoritma
    sum = 0;
    for (i = 1; i <= T.neff; i++) {
        if (T.Tb[i] % 2 == 0) {
            sum = sum + T.Tb[i];
        }
    }
    return sum;
}

int getJumElm(TabInt T) {
    // Kamus lokal
    int jum;

    // Algoritma
    jum = T.neff;
    return jum;
}

int getJumElmGanjil(TabInt T) {
    // Kamus lokal
    int jum, i;

    // Algoritma
    jum = 0;
    for (i = 1; i <= T.neff; i++) {
        if (T.Tb[i] % 2 != 0) {
            jum = jum + 1;
            printf("<%d> ", T.Tb[i]);
        }
    }
    return jum;
}

TabInt CopyNegTab(TabInt T) {
    // Kamus lokal
    TabInt MyTab1;
    int i;

    // Algoritma
    MyTab1.neff = 0;
    for (i = 1; i <= T.neff; i++) {
        MyTab1.neff = MyTab1.neff + 1;
        MyTab1.Tb[i] = T.Tb[i] * -1;
    }
    return MyTab1;
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

void CekPrima(TabInt T) {
    // Kamus lokal
    int i;

    // Algoritma
    for (i = 1; i <= T.neff; i++) {
        if (IsPrima(T.Tb[i])) {
            printf("<%d> bilangan prima\n", T.Tb[i]);
        } else {
            printf("<%d> bukan bilangan prima\n", T.Tb[i]);
        }
    }
}