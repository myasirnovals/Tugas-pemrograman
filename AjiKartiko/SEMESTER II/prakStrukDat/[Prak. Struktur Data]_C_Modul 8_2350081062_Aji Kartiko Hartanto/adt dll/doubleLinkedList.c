/*
    Program     : doubleLinkedList.c
    Author      : 2350081062, Aji Kartiko Hartanto
    Kelas       : C
    Deskripsi   : body file dari prototype double linked list
    Tanggal     : 05-06-2024
 */

#include "doubleLinkedList.h"

boolean ListEmpty(List L) {
    if(First(L) == Nil) {
        return true;
    } else {
        return false;
    }
}

void CreateList(List *L) {
    First(*L) = Nil;
}

address Alokasi(infoType X) {
    // kamus
    address newNode;

    // alokasi
    newNode = (ElmList *) malloc(sizeof(ElmList));

    // algoritma
    Info(newNode) = X;
    Next(newNode) = Nil;
    Prev(newNode) = Nil;

    return newNode;
}

void Dealokasi(address P) {
    free(P);
}

address Search(List L, infoType X) {
    address current;

    current = First(L);
    while (current != Nil) {
        if (Info(current) == X) {
            return current;
        }

        current = Next(current);
    }

    return Nil;
}

void AddFirst(List *L, infoType X) {
    address newNode;

    newNode = Alokasi(X);

    if(newNode != Nil) {
        Info(newNode) = X;
        Next(newNode) = First(*L);
        First(*L) = Prev(newNode);
        First(*L) = newNode;
    }
}

void AddLast(List *L, infoType X) {
    address newNode, current;

    newNode = Alokasi(X);
    current = First(*L);

    if (newNode != Nil) {
        while (Next(current) != Nil) {
            current = Next(current);
        }

        Next(current) = newNode;
        Prev(newNode) = current;
    }
}

void DelFirst(List *L, infoType *X) {
    address delNode, tmp;

    delNode = First(*L);
    First(*L) = Next(First(*L));

    *X = Info(delNode);
    tmp = delNode;
    Dealokasi(tmp);

    tmp = Nil;
    Prev(First(*L)) = Nil;
}

void DelLast(List *L, infoType *X) {
    address delNode, tmp, tmp2;

    delNode = First(*L);
    *X = Info(delNode);
    tmp = (delNode);

    while(Next(tmp) != Nil) {
        tmp = Next(tmp);
    }

    tmp2 = Prev(tmp);
    Next(tmp2) = Nil;
    Dealokasi(tmp);
}

void CetakList(List L) {
    address current;

    current = First(L);
    printf("Null");
    while (current != Nil) {
        printf(" <- [%d] -> ", Info(current));

        current = Next(current);
    }

    printf("Null");
}