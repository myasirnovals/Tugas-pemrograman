/*
    Program: mdoubleLinkedList.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Program utama yang menjalankan ketiga program sebelumnya
    Tanggal: 02/04/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.c"

int main() {
    List node;
    infoType info, tmp;
    address searchElm;

    CreateList(&node);

    printf("\n=========Operator Pengecekan apakah list kosong atau tidak=========\n");
    if(ListEmpty(node)) {
        printf("List masih kosong\n");
    } else {
        printf("List tidak kosong\n");
    }

    printf("\n=========Operator Add First=========\n");
    AddFirst(&node, 25);
    AddFirst(&node, 45);
    CetakList(node);

    printf("\n\n=========Operator Add Last=========\n");
    AddLast(&node, 15);
    AddLast(&node, 5);
    CetakList(node);

    printf("\n\n=========Operator Delete First=========\n");
    DelFirst(&node, &tmp);
    CetakList(node);

    printf("\n\n=========Operator Delete Last=========\n");
    DelLast(&node, &tmp);
    CetakList(node);

    printf("\n\n=========Operator Search=========\n");
    printf("Masukan Elemen yang dicari: ");
    scanf("%d", &info);

    searchElm = Search(node, info);
    if (searchElm != Nil) {
        printf("\nElemen %d ada di list dengan alamat %d", info, searchElm);
    } else {
        printf("Elemen %d tidak ada di list", info);
    }

    printf("\n\n");

    return 0;
}