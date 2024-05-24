#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int abs, ord;

} Point;

typedef struct {
    Point T[100];
    int neff;

} TabPoint;

int main()
{
    // Kamus
    int x,y,i;
    Point P;
    TabPoint myTab;

    // Algoritma
    printf("Masukan nilai absis: ");
    scanf("%d", &x);

    printf("Masukan nilai ordinat: ");
    scanf("%d", &y);

    P.abs = x;
    P.ord = y;

    myTab.T[0] = P;
    myTab.neff = 1;

    for(i=0; i < myTab.neff; i++) {
        printf("Nilai absis: %d     ordinat: %d", myTab.T[i].abs, myTab.T[i].ord);
    }

    return 0;
}