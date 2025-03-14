/*
    Program     : mlist.c
    Author      : 2350081062, Aji Kartiko Hartanto
    Kelas       : C
    Deskripsi   : main driver ADT linked list
    Tanggal     : 05-04-2024
*/



#include <stdio.h>
#include "list.c"

int main() {
    List node1;
    infoType tmpDelFirst, tmpDelLast, tmpDelafter, infoElm;
    address searchElm;

    // membuat list
    CreateList(&node1);

    // mengecek apakah list kosong atau tidak
    printf("Apakah list kosong? \n");
    if (ListEmpty(node1)) {
        printf("List Masih Kosong");
    } else {
        printf("List tidak Kosong");
    }

    // menambahkan elemen pada list
    printf("\n\n");
    printf("Insert First List\n");
    InsFirst(&node1, 1);
    InsFirst(&node1, 2);
    InsFirst(&node1, 3);
    InsFirst(&node1, 4);

    // Cetak List
    PrintInfo(node1);

    // mengecek apakah list kosong atau tidak
    printf("\n\n");
    printf("Apakah list masih kosong? \n");
    if (ListEmpty(node1)) {
        printf("List Masih Kosong");
    } else {
        printf("List tidak Kosong");
    }

    // menambahkan elemen terakhir pada list
    printf("\n\n");
    printf("Insert last list\n");
    InsLast(&node1, 5);
    InsLast(&node1, 6);

    // Cetak List
    PrintInfo(node1);

    // menambahkan elemen setelah node ke Y pada list
    printf("\n\n");
    printf("Insert after list\n");
    InsAfter(&node1, 10, 1);
    InsAfter(&node1, 20, 2);

    // Cetak List
    PrintInfo(node1);

    // menghapus elemen pertama pada list
    printf("\n\n");
    printf("Delete first list\n");
    DelFirst(&node1, &tmpDelFirst);
    DelFirst(&node1, &tmpDelFirst);

    // Cetak List
    PrintInfo(node1);

    // menghapus elemen akhir pada list
    printf("\n\n");
    printf("Delete Last list\n");
    DelLast(&node1, &tmpDelLast);
    DelLast(&node1, &tmpDelLast);

    // Cetak List
    PrintInfo(node1);

    // menghapus elemen setelah node ke Y pada list
    printf("\n\n");
    printf("Delete After list\n");
    DelAfter(&node1, &tmpDelafter, 3);

    // Cetak List
    PrintInfo(node1);

    // invers list
    printf("\n\n");
    printf("Invers pada list\n");
    PrintInfo(getNewInversList(node1));

    // mencari element list dengan info
    printf("\n\n");
    printf("Masukan Elemen yang dicari: ");
    scanf("%d", &infoElm);

    searchElm = Search(node1, infoElm);
    if (searchElm != Nil) {
        printf("\nElemen %d ada di list dengan alamat %d", infoElm, searchElm);
    } else {
        printf("Elemen %d tidak ada di list", infoElm);
    }

    // mengirim banyak nya elemen pada list
    printf("\n\n");
    printf("Banyaknya elemen pada list adalah %d\n", NbElm(node1));

    return 0;
}