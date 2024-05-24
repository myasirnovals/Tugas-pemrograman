/*
    Program: mbtree.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Program utama yang menjalankan ketiga program sebelumnya
    Tanggal: 05/04/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include "btree.c"

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