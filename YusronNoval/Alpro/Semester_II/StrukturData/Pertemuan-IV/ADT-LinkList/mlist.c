/*
    Program: mlist.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Program utama yang menjalankan ketiga program sebelumnya
    Tanggal: 02/04/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include "list.c"

int main() {
    List node1;
    infoType info, infoElm;
    address searchElm;

    CreateList(&node1);

    printf("Apakah list kosong? \n");
    if (ListEmpty(node1)) {
        printf("List Masih Kosong\n");
    } else {
        printf("List tidak Kosong\n");
    }

    printf("\n=========Operator insert=========\n");
    printf("Insert First List\n");
    InsFirst(&node1, 1);
    InsFirst(&node1, 2);
    InsFirst(&node1, 3);
    InsFirst(&node1, 4);
    PrintInfo(node1);

    printf("\n\nApakah list masih ada yang kosong?\n");
    if (ListEmpty(node1)) {
        printf("List Masih Kosong\n");
    } else {
        printf("List tidak Kosong\n");
    }

    printf("\nInsert last list\n");
    InsLast(&node1, 5);
    InsLast(&node1, 6);
    PrintInfo(node1);
    
    printf("\n\nInsert after list\n");
    InsAfter(&node1, 10, 1);
    InsAfter(&node1, 20, 2);
    PrintInfo(node1);

    printf("\n\n=========Operator delete=========\n");
    printf("Delete first list\n");
    printf("Masukan Info: ");
    scanf("%d", &info);
    DelFirst(&node1, &info);
    DelFirst(&node1, &info);
    PrintInfo(node1);

    printf("\n\nDelete Last list\n");
    printf("Masukan Info: ");
    scanf("%d", &info);
    DelLast(&node1, &info);
    DelLast(&node1, &info);
    PrintInfo(node1);

    printf("\n\nDelete After list\n");
    printf("Masukan Info: ");
    scanf("%d", &info);
    DelAfter(&node1, &info, 3);
    PrintInfo(node1);

    printf("\n\n=========Operator invers=========\n");
    printf("Invers pada list\n");
    PrintInfo(getNewInversList(node1));

    printf("\n\n=========Operator Search=========\n");
    printf("Masukan Elemen yang dicari: ");
    scanf("%d", &infoElm);

    searchElm = Search(node1, infoElm);
    if (searchElm != Nil) {
        printf("\nElemen %d ada di list dengan alamat %d", infoElm, searchElm);
    } else {
        printf("Elemen %d tidak ada di list", infoElm);
    }

    printf("\nBanyak elemen yang ada pada list adalah %d\n\n", NbElm(node1));

    return 0;
}