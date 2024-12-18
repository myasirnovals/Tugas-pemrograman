/*
    Program     : queue2.c
    Author      : 2350081062, Aji Kartiko Hartanto
    Kelas       : C
    Deskripsi   : file .c dari file header queue
    Tanggal     : 23 Mei 2024
*/

#include "queue.h"

// Prototype Queue
// Konstruktor membentuk Queue
void CreateQueue(Queue *Q) {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

// {Operasi terhadap komponen: selektor Get dan Set} : tidak perlu sudah di define diatas
int NBElmt(Queue Q) {
    if (Head(Q) == 0 && Tail(Q) == 0) {
        return 0;
    } else {
        return Tail(Q) + 1 - Head(Q);
    }
}

// Destruktor/Dealokator: tidak perlu

// {Kelompok operasi pada Queue}
boolean IsQueueEmpty(Queue Q) {
    if (Head(Q) == Nil && Tail(Q) == Nil) {
        return true;
    } else {
        return false;
    }
}

boolean IsQueueFull(Queue Q) {
    if (Tail(Q) == MaxEl) {
        return true;
    } else {
        return false;
    }
}

// Menambahkan sebuah element ke queue
void AddQueue(Queue *Q, infotype X) {
    if (IsQueueEmpty(*Q)) {
        Head(*Q)++;
        InfoHead(*Q) = X;

        Tail(*Q) = Head(*Q);
    } else {
        if (!IsQueueFull(*Q)) {
            Tail(*Q)++;
            InfoTail(*Q) = X;
        } else {
            printf("Stack penuh");
        }
    }
}

// Menghapus sebuah element queue
void DelQueue(Queue *Q, infotype *X) {
    // kamus

    // algoritma
    if (!IsQueueEmpty(*Q)) {
        if (Head(*Q) == Tail(*Q)) {
            *X = InfoHead(*Q);

            CreateQueue(Q);
        } else {
            *X = InfoHead(*Q);
            Head(*Q)++;
        }
    } else {
        printf("Queue kosong");
    }
}

// {Kelompok interaksi dengan i/o device, Baca/Tulis}
void PrintQueueInfo(Queue S) {
    // kamus
    int i;

    // algoritma
    if (!IsQueueEmpty(S)) {
        for (i = Head(S); i <= Tail(S); i++) {
            printf("[%d] <- ", InfoElm(S));
        }

        printf("Null");
    }
}

// Kelompok operasi lain terhadap type
boolean isInfoKetemu(Queue S, infotype X) {
    // kamus
    int i;

    // algoritma
    if (IsQueueEmpty(S)) {
        return false;
    } else {
        for (i = 1; i <= Tail(S); i++) {
            if (InfoElm(S) == X) {
                return true;
            }
        }

        return false;
    }
}

address CariElemenQueue(Queue Q, int X) {
    // kamus
    int i;

    // algoritma
    if (IsQueueEmpty(Q)) {
        // jika tabel kosong return Index undefine
        return IdxUndef;
    } else {
        // jika ditemukan return addres yaitu i
        for (i = 1; i <= Tail(Q); i++) {
            if (InfoElm(Q) == X) {
                return i;
            }
        }

        // jika data x tidak ditemukan return Index undefine
        return IdxUndef;
    }
}