/**
 * Program: stack2.c
 * Author: (2350081004, Muhamad Yasir Noval)
 *         (2350081028, Ricky Gunaldo)
 *         (2350081011, M Abhinaya Rakan A)
 * Kelas: A
 * Deskripsi: Header file dari stack
 * Tanggal: 10 Mei 2024
 */

#include "../lib/stack2.h"

// konstruktor
void CreateStack(Stack *S) {
    Top(*S) = Nil;
}

address Alokasi(infoType x) {
    // Kamus
    address newNode;

    // Alokasi memori menggunakan Malloc
    newNode = (ElmStack *) malloc(sizeof(ElmStack));

    // algoritma
    Info(newNode) = x;
    Next(newNode) = Nil;

    return newNode;
}

// Destruktor
void DeAlokasi(address P) {
    free(P);
}

// Operasi stack
void Push(Stack *S, infoType X) {
    // Kamus
    address newNode;

    // Alokasi memori
    newNode = Alokasi(X);

    // algoritma
    if (IsStackEmpty(*S)) {
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
    // kamus
    address delNode, current;
    
    // algoritma
    delNode = Top(*S);
    current = Bottom(*S);

    while (Next(current) != Top(*S)) {
        current = Next(current);
    }

    *X = Info(Top(*S));
    Top(*S) = current;
    Next(Top(*S)) = Nil;

    // dealokasi
    DeAlokasi(delNode);
}

void CetakStack(Stack S) {
    address current;

    current = Bottom(S);
    while (current != Nil) {
        printf("[%d] -> ", Info(current));

        current = Next(current);
    }

    printf("Null");
}

boolean IsStackEmpty(Stack S) {
    if (Top(S) == Nil) {
        return true;
    } else {
        return false;
    }
}

boolean CariElemenStack(Stack S, infoType x) {
    // kamus
    address Current;

    // algoritma
    Current = Bottom(S);
    while (Current != Nil) {
        if (Info(Current) == x) {
            return true;
        }

        Current = Next(Current);
    }

    return false;
}