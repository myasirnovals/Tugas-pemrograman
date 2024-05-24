/*
 * Program: main.c
 * Author: Muhamad Yasir Noval/2350081004
 * Date: 2 Januari 2024
 * Description: perbaikan soal uas praktikum algoritma
 * dan pemrograman
 */

#include <stdio.h>

#define nMax 10

typedef struct {
    int abs;
    int ord;
} Point;

typedef struct {
    Point Patas, Pbawah;
    int pjg, lbr, luas;
} Kotak;

typedef struct {
    Kotak Tk[nMax + 10];
    int neff;
} TabKotak;

// prototype
void CreateTab(TabKotak *T);

void AddTab(TabKotak *T, Kotak K);

void BuatKotak(Kotak K);

void CetakTab(TabKotak T);

Kotak JadiKotak(Point p1, Point p2);

int Fibonaccy(int N);

int main() {
    //kamus
    TabKotak myTab;
    Point P1, P2;
    Kotak myKotak;

    // Algoritma
    CreateTab(&myTab);

    printf("input x1 :");
    scanf("%d", &P1.abs);
    
    printf("input y1 :");
    scanf("%d", &P1.ord);
    
    printf("input x2 :");
    scanf("%d", &P2.abs);
    
    printf("input y2 :");
    scanf("%d", &P2.ord);

    while ((P1.abs != 999) && (P1.ord != 999) && (P2.abs != 999) && (P2.ord != 999)) {
        myKotak = JadiKotak(P1, P2);
        AddTab(&myTab, myKotak);

        printf("input x1 :");
        scanf("%d", &P1.abs);
        
        printf("input y1 :");
        scanf("%d", &P1.ord);
        
        printf("input x2 :");
        scanf("%d", &P2.abs);
        
        printf("input y2 :");
        scanf("%d", &P2.ord);
    }

    CetakTab(myTab);
    
    return 0;
}

// Body of prototype
void CreateTab(TabKotak *T) {
    // kamus lokal

    // Algoritma
    (*T).neff = 0;
}

void AddTab(TabKotak *T, Kotak K) {
    // kamus lokal

    // Algoritma
    if ((*T).neff < nMax) {
        (*T).neff++;
        (*T).Tk[(*T).neff] = K;
    }
}

void BuatKotak(Kotak K) {
    // Kamus lokal

    // Algritma
    printf("P1(%d,%d)-P2(%d,%d);", K.Patas.abs, K.Patas.ord, K.Pbawah.abs, K.Pbawah.ord);
    printf("(Panjang :%d angka, Lebar :%d, Luas :%d)", K.pjg, K.lbr, K.luas);
}

void CetakTab(TabKotak T) {
    // Kamus lokal
    int i, j, k;

    // Algoritma
    for (i = 1; i <= T.neff; i++) {
        for (j = 1; j <= T.Tk[i].lbr; j++) {
            printf("|");
            for (k = 1; k <= T.Tk[i].pjg; k++) {
                printf(" %d ", Fibonaccy(k));
            }
            printf("|\n");
        }
        BuatKotak(T.Tk[i]);
        printf("\n\n\n");
    }
}

Kotak JadiKotak(Point p1, Point p2) {
    // Kamus lokal
    Kotak K;

    // Algoritma
    K.Patas = p1;
    K.Pbawah = p2;

    if (p1.abs > p2.abs) {
        K.lbr = p1.abs - p2.abs;
    } else {
        K.lbr = p2.abs - p1.abs;
    }

    if (p1.ord > p2.ord) {
        K.pjg = p1.ord - p2.ord;
    } else {
        K.pjg = p2.ord - p1.ord;
    }

    K.luas = K.pjg * K.lbr;

    return K;
}

int Fibonaccy(int N) {
    // Kamus lokal

    // Algoritma
    if (N == 1 || N == 2) {
        return 1;
    } else {
        return Fibonaccy(N - 2) + Fibonaccy(N - 1);
    }
}
