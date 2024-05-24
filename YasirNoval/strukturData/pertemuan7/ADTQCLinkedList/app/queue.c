/**
 * Program: queue.c
 * Author: (2350081004, Muhamad Yasir Noval)
 * Kelas: A
 * Deskripsi: Header file dari prototype queue
 * Tanggal: -
 */

#include "../lib/queue.h"

// Prototype Queue
// Konstruktor membentuk Queue
void CreateQueue(Queue *Q) {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

// {Operasi terhadap komponen: selektor Get dan Set} : tidak perlu sudah di define diatas

// Destruktor/Dealokator untuk mengalokasi memory
// alokasi
address Alokasi(infoType x) {
    address newNode;

    // alokasi
    newNode = (ElmQueue *) malloc(sizeof (ElmQueue));

    // algoritma
    Info(newNode) = x;
    Next(newNode) = Nil;

    return newNode;
}

// Destruktor
void DeAlokasi(address P) {
    free(P);
}

// {Kelompok operasi pada Queue}
boolean IsQueueEmpty(Queue Q) {
    if (Head(Q) == Nil && Tail(Q) == Nil) {
        return true;
    } else {
        return false;
    }
}

// Menambahkan sebuah element ke queue
void AddQueue(Queue *Q, infoType X) {
    // kamus
    address newNode;

    // alokasi
    newNode = Alokasi(X);

    // algoritma
    if (IsQueueEmpty(*Q)) {
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

// Menghapus sebuah element queue
void DelQueue(Queue *Q, infoType *X) {
    // kamus
    address delNode;

    // algoritma
    delNode = Head(*Q);
    Head(*Q) = Next(Head(*Q));

    // dealokasi memori
    *X = Info(delNode);
    DeAlokasi(delNode);
}

// {Kelompok interaksi dengan i/o device, Baca/Tulis}
void CetakQueue(Queue Q) {
    // kamus
    address current;

    // algoritma
    current = Head(Q);
    while (current != Nil) {
        printf("[%d] -> ", Info(current));

        current = Next(current);
    }
    printf("Null");
}

boolean CariElemenQueue(Queue Q, infoType X) {
    // kamus
    address current;
    boolean ketemu;

    // algoritma
    current = Head(Q);
    ketemu = tidak;
    while (current != Nil && !ketemu) {
        if (Info(current) == X) {
            ketemu = ya;
        }

        current = Next(current);
    }

    return ketemu;
}
