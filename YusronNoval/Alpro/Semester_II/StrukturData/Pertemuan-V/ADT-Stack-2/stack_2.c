/*
    Program: stack_2.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Memasukan instruksi yang akan dieksekusi didalam fungsi dan prosedur
    Tanggal: 02/04/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack_2.h"

void createStack(Stack *S) {
    Top(*S) = Nil;
}

address Alokasi(infoType X) {
    address newNode;

    newNode = (ElmStack *) malloc(sizeof(ElmStack));
    Info(newNode) = X;
    Next(newNode) = Nil;
    
    return newNode;
}

void Dealokasi(address P) {
    free(P);
}

void Push(Stack *S, infoType X) {
    address newNode;

    newNode = Alokasi(X);

    if(isEmpty(*S)) {
        Info(newNode) = X;
        Next(newNode) = Bottom(*S);

        Bottom(*S) = newNode;
        Top(*S) = Bottom(*S);
    } else {
        Info(newNode) = X;
        Next(newNode) = Nil;

        Next(Top(*S)) = newNode;
        Top(*S) = newNode;
    }
}

void Pop(Stack *S, infoType *X) {
    address delNode, current;

    delNode = Top(*S);
    current = Bottom(*S);

    while(Next(current) != Top(*S)) {
        current = Next(current);
    }

    *X = Info(Top(*S));
    Top(*S) = current;
    Next(Top(*S)) = Nil;
    Dealokasi(delNode);
}

void cetakStack(Stack S) {
    address current;

    current = Bottom(S);
    while(current != Nil) {
        printf("(%d) -> ", Info(current));
        current = Next(current);
    }

    printf("Null");
}

boolean isEmpty(Stack S) {
    if(Top(S) == Nil) {
        return true;
    } else {
        return false;
    }
}

boolean cariElm(Stack S, infoType X) {
    address current;

    current = Bottom(S);
    while(current != Nil) {
        if(Info(current) == X) {
            return true;
        }
        current = Next(current);
    }

    return false;
}