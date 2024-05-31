/**
 * Program: main.c
 * Author: (2350081004, Muhamad Yasir Noval)
 * Kelas: A
 * Deskripsi: main program dari Adt double linked list
 * Tanggal: -
 */

#include "app/doubleLinkedList.c"

int main() {
    List node;
    infoType info, elemen;
    address Tmp;

    CreateList(&node);

    printf("\nApakah List masih kosong?\n");
    if(ListEmpty(node)) {
        printf("List masih kosong\n");
    } else {
        printf("List tidak kosong\n");
    }

    printf("\n\nTambah Awal\n");
    AddFirst(&node, 1);
    AddFirst(&node, 2);
    CetakList(node);

    printf("\n\nTambah Akhir\n");
    AddLast(&node, 3);
    AddLast(&node, 4);
    CetakList(node);

    printf("\n\nHapus Awal\n");
    DelFirst(&node, &elemen);
    CetakList(node);

    printf("\n\nHapus Akhir\n");
    DelLast(&node, &elemen);
    CetakList(node);

    printf("\n\nCari Elemen\n");
    printf("Masukan Elemen yang dicari: ");
    scanf("%d", &info);

    Tmp = Search(node, info);
    if (Tmp != Nil) {
        printf("\nElemen %d ada di list dengan alamat %p", info, Tmp);
    } else {
        printf("Elemen %d tidak ada di list", info);
    }

    printf("\n\n");

    return 0;
}