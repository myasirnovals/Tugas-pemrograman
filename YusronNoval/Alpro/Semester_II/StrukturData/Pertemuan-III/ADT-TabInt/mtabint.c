/*
    Program: mtabint.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Program utama yang menjalankan ketiga program sebelumnya
    Tanggal: 28/03/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include "tabint.c"

int main() {
    Tabint myTab, T1, T2, T3, tabCopy;
    int index, newElm, cons, elm;

    CreateTab(&myTab);
    BacaElm(&myTab);
    CetakTab(myTab);

    printf("\n\n=======Mendapatkan jumlah elemen, elm pertama dan terakhir=======\n");
    printf("Jumlah elemen pada tabel: %d\n", GetJumElm(myTab));
    printf("Elemen pertama pada tabel: %d\n", GetFirstIndex(myTab));
    printf("Elemen terakhir pada tabel: %d\n", GetLastIndex(myTab));

    printf("\nMasukan elemen yang akan diambil: ");
    scanf("%d", &index);

    printf("\nElemen index ke %d adalah %d\n", index, GetElm(myTab, index));
    
    printf("Masukan elemen yang baru :");
    scanf("%d", &newElm);
    
    SetElm(&myTab, index, newElm);
    CetakTab(myTab);
    
    if (IsEmpty(myTab)) {
        printf("\nTabel kosong");
    } else {
        printf("\nTabel tidak kosong");
    }
    
    if (IsFull(myTab)) {
        printf("\nTabel penuh");
    } else {
        printf("\nTabel tidak penuh");
    }
    
    printf("\n\n=======Masukan elemen T1 untuk perkalian=======\n");  
    CreateTab(&T1);   
    BacaElm(&T1);
    CetakTab(T1);
    CreateTab(&T2);
    
    T2 = KaliTab(myTab, T1);
    
    printf("\nHasil kali tabel T2: ");
    CetakTab(T2);

    printf("\n\nMasukan konstanta yang akan di kalikan: ");
    scanf("%d", &cons);
    
    CreateTab(&T3);
    T3 = KaliKons(myTab, cons);
    
    printf("\nHasil perkalian tabel dengan konstanta T3:");
    CetakTab(T3);
    
    printf("\n\n=======Operator apakah hasi tabel myTab sama dengan T1=======\n");
    if (IsEQTab(myTab, T1)) {
        printf("myTab dan T1 memiliki jumlah elemen yang sama");
    } else {
        printf("myTab dan T1 memiliki jumlah elemen berbeda");
    }

    CreateTab(&tabCopy);

    CopyTab(myTab, &tabCopy);

    printf("\n\nOperator menyalin tabel myTab ke TabCopy: ");
    CetakTab(tabCopy);

    printf("\nInvers myTab : ");
    CetakTab(InversTab(tabCopy));

    printf("\nMasukan elemen yang akan di cari di TabCopy: ");
    scanf("%d", &elm);

    if (IsElmAda(tabCopy, elm)) {
        printf("Elemen Ada");
    } else {
        printf("Elemen Tidak ada");
    }

    printf("\n\nMasukan elemen yang akan di cari pada myTab: ");
    scanf("%d", &elm);

    printf("Elemen yang di cari berada pada index ke-%d\n\n", CariElm(myTab, elm));

    return 0;
}