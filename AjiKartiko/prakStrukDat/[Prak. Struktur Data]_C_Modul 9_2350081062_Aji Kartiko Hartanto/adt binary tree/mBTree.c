/*
    Program      : mBTree.c
    Author       : 2350081062, Aji Kartiko Hartanto
    Kelas        : C
    Deskripsi    : main driver dari prototype boolean
    Tanggal      : 12 - 06 - 2024
 */

#include "bTree.c"

int main() {
    Tree myPohon = Nil;
    int N;

    printf("Masukan bilangan: ");
    scanf("%d", &N);

    while (N != 999) {
        myPohon = inSearch(myPohon, N);
        printf("Masukan bilangan: ");
        scanf("%d", &N);
    }

    printf("\n\n");
    printf("\nPrefix: ");
    preOrder(myPohon);
    printf("\nTinggi Pohon: %d\n", TinggiPohon(myPohon));

    printf("\nInfix: ");
    inOrder(myPohon);
    printf("\nTinggi Pohon: %d\n", TinggiPohon(myPohon));

    printf("\nPostfix: ");
    postOrder(myPohon);
    printf("\nTinggi Pohon: %d\n", TinggiPohon(myPohon));

    printf("\n\n");

    return 0;
}
