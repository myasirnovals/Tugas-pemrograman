/*
    Program: queueCircular2.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Memasukan instruksi yang akan dieksekusi didalam fungsi dan prosedur
    Tanggal: 09/04/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include "queueCircular2.h"

void createQueue(Queue *Q) {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

address Alokasi(infoType X) {
    address newNode;

    newNode = (ElmQueue *) malloc(sizeof(ElmQueue));

    Info(newNode) = Nil;
    Next(newNode) = Nil;

    return newNode;
}

void Dealokasi(address P) {
    free(P);
}

boolean isEmpty(Queue Q) {
    if(Head(Q) == Nil && Tail(Q) == Nil) {
        return true;
    } else {
        return false;
    }
}

void addQueue(Queue *Q, infoType X) {
    address newNode;

    newNode = Alokasi(X);

    if(isEmpty(*Q)) {
        Info(newNode) = X;
        Next(newNode) = Head(*Q);

        Head(*Q) = newNode;
        Tail(*Q) = Head(*Q);
    } else {
        Info(newNode) = X;
        Next(newNode) = Nil;

        Next(Tail(*Q)) = newNode;
        Tail(*Q) = newNode;
    }
}

void deleteQueue(Queue *Q, infoType *X) {
    address delNode;

    delNode = Head(*Q);
    Head(*Q) = Next(Head(*Q));

    *X = Info(delNode);
    Dealokasi(delNode);
}

void cetakQueue(Queue S) {
    address current;

    current = Head(S);
    while(current != Nil) {
        printf("(%d) -> ", Info(current));

        current = Next(current);
    }

    printf("Null");
}

boolean cariElm(Queue Q, infoType X) {
    address current;
    boolean ketemu;

    current = Head(Q);
    ketemu = false;
    while(current != Nil && !ketemu) {
        if(Info(current) == X) {
            ketemu = true;
        }

        current = Next(current);
    }

    return ketemu;
}