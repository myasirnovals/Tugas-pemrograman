/*
	Program		: mBTree.c
	Author		: 2350081062, Aji Kartiko Hartanto
	Kelas		: C
	Deskripsi	: Main Driver binary tree
	Tanggal		: 12 - 06 - 2024
*/

#include "bTree.h"
#include <stdio.h>
#include <stdlib.h> 

int main() {
    // Kamus global
    Tree MyPohon = nil;
    int N, akar;

    // Algoritma
    // Hapus layar tergantung pada sistem operasi
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf("Masukkan akar pohon: ");
    scanf("%d", &akar);
    MyPohon = Alokasi(akar);

    printf("Masukan Bilangan: ");
    scanf("%d", &N);
    while (N != 9999) {
        InsSearch(MyPohon, N); 
        printf("Masukan Bilangan: ");
        scanf("%d", &N);
    } 

    printf("PreOrder: ");
    PreOrder(MyPohon);
    printf("\n");

    printf("InOrder: ");
    InOrder(MyPohon);
    printf("\n");

    printf("PostOrder: ");
    PostOrder(MyPohon);
    printf("\n");

    printf("Tinggi Pohon: %d\n", TinggiPohon(MyPohon));

    // Menunggu input sebelum keluar, agar konsol tidak langsung tertutup
    printf("\nPress Enter to exit...");
    getchar(); // Mengambil input sisa dari scanf sebelumnya
    getchar(); // Menunggu input sebenarnya

    return 0;
}
