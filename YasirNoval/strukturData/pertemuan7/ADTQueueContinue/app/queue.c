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
int NBElmt(Queue Q) {
    if (Head(Q) == 0 && Tail(Q) == 0) {
        return 0;
    } else {
        return Tail(Q);
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
    if (Tail(Q) == MaxEl || Head(Q) == MaxEl) {
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
            if (Head(*Q) <= Tail(*Q)) {
                Tail(*Q)++;
                InfoTail(*Q) = X;
            } else {
                if (Tail(*Q) + 1 != Head(*Q)) {
                    Tail(*Q)++;
                    InfoTail(*Q) = X;
                } else {
                    printf("\nQueue penuh\n");
                }
            }
        } else {
            Tail(*Q) = 1;
            InfoTail(*Q) = X;
        }
    }
}

// Menghapus sebuah element queue
void DelQueue(Queue *Q, infotype *X) {
    // kamus

    // algoritma
    if (!IsQueueEmpty(*Q)) {
        // periksa apakah queue hanya punya satu elemen
        if (Head(*Q) == Tail(*Q)) {
            *X = InfoHead(*Q);
            Head(*Q) = 0;
            Tail(*Q) = 0;
        } else {
            // queue memiliki lebih dari satu elemen
            *X = InfoHead(*Q);
            InfoHead(*Q) = 0;

            if (!IsQueueFull(*Q)) {
                // jika head belum melebihi max
                Head(*Q)++;
            } else {
                // jika head sudah melebihi max
                Head(*Q) = 1;
            }

            if (Tail(*Q) == (Head(*Q) - 1 + MaxEl) % MaxEl) {
                // jika Tail akan melewati Head
                Tail(*Q) = (Tail(*Q) + 1) % MaxEl;
            }
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
        for (i = 1; i <= MaxEl; i++) {
            printf("[%d] ", InfoElm(S));
        }
    } else {
        printf("Queue kosong");
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
        for (i = 1; i <= MaxEl; i++) {
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
        for (i = 1; i <= MaxEl; i++) {
            if (InfoElm(Q) == X) {
                return i;
            }
        }

        // jika data x tidak ditemukan return Index undefine
        return IdxUndef;
    }
}

void SetQueue(Queue *Q) {
    // kamus
    int i;

    // algoritma
    for (i = 1; i <= MaxEl; i++) {
        InfoElm(*Q) = 0;
    }
}
