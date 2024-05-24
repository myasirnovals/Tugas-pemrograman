/*
    Program: doubleLinkedList.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Memasukan instruksi yang akan dieksekusi didalam fungsi dan prosedur
    Tanggal: 02/04/2024
*/
#include <stdio.h>
#include <stdlib.h>
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
    address NewNode = (ElmList *) malloc(sizeof(ElmList));

    Info(NewNode) = X;
    Next(NewNode) = Nil;
    Prev(NewNode) = Nil;

    return NewNode;
}

void Dealokasi(address P) {
    free(P);
}

address Search(List L, infoType X) {
    address Current;

    Current = First(L);
    while (Current != Nil) {
        if (Info(Current) == X) {
            return Current;
        }

        Current = Next(Current);
    }

    return Nil;
}

void AddFirst(List *L, infoType X) {
    address NewNode;

    NewNode = Alokasi(X);

    if(NewNode != Nil) {
        Info(NewNode) = X;
        Next(NewNode) = First(*L);
        First(*L) = Prev(NewNode);
        First(*L) = NewNode;
    }
}

void AddLast(List *L, infoType X) {
    address NewNode, Current;

    NewNode = Alokasi(X);
    Current = First(*L);

    if (NewNode != Nil) {
        while (Next(Current) != Nil) {
            Current = Next(Current);
        }

        Next(Current) = NewNode;
        Prev(NewNode) = Current;
    }
}

void DelFirst(List *L, infoType *X) {
    address DelNode, Tmp;

    DelNode = First(*L);
    First(*L) = Next(First(*L));

    *X = Info(DelNode);
    Tmp = DelNode;
    Dealokasi(Tmp);

    Tmp = Nil;
    Prev(First(*L)) = Nil;
}

void DelLast(List *L, infoType *X) {
    address DelNode, tmp, tmp2;

    DelNode = First(*L);
    *X = Info(DelNode);
    tmp = (DelNode);

    while(Next(tmp) != Nil) {
        tmp = Next(tmp);
    }

    tmp2 = Prev(tmp);
    Next(tmp2) = Nil;
    Dealokasi(tmp);
}

void CetakList(List L) {
    address Current;

    Current = First(L);
    printf("Null");
    while (Current != Nil) {
        printf(" <- [%d] -> ", Info(Current));

        Current = Next(Current);
    }

    printf("Null");
}