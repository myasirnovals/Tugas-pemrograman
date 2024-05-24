/**
 * Program: boolean.h
 * Author: (2350081004, Muhamad Yasir Noval)
 * Kelas: A
 * Deskripsi: Header file dari prototype boolean
 * Tanggal: -
 */

#include "app/binaryTree.c"

int main() {
    Tree myPohon = Nil;
    int N;

    printf("Masukan bilangan: ");
    scanf("%d", &N);

    while(N != 999) {
        myPohon = inSearch(myPohon, N);
        printf("Masukan bilangan: ");
        scanf("%d", &N);
    }

    preOrder(myPohon);
    printf("\n\nTinggi Pohon: %d", TinggiPohon(myPohon));
    getchar();

    printf("\n\n");

    return 0;
}