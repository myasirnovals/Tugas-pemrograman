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
    DelFirst(&node, &elemen);
    CetakList(node);

    printf("\n\n=========Operator Delete Last=========\n");
    DelLast(&node, &elemen);
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