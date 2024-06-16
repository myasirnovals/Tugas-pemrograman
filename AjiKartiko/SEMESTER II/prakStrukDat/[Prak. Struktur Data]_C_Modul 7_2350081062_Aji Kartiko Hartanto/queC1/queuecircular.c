/*
	Program 	: queuecircular.c
	Author 		: 2350081062, Aji Kartiko Hartanto
	Kelas 		: C
	Deskripsi 	: Body file dari prototype queue
	Tanggal 	: 29 Mei 2024
*/

#include "queuecircular.h"

/* Konstruktor membentuk Queue */
void CreateQueue(Queue *Q) {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
int NBElmt(Queue Q) {
    if (IsQueuekEmpty(Q)) {
        return 0;
    } else if (Head(Q) <= Tail(Q)) {
        return Tail(Q) - Head(Q) + 1;
    } else {
        return (MaxEl - Head(Q) + 1) + Tail(Q);
    }
}

/* Mengirim true jika Queue kosong: lihat definisi di atas */
boolean IsQueuekEmpty(Queue Q) {
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

/* Mengirim true jika tabel penampung nilai elemen stack penuh yaitu jumlah elemen sudah mencapai MaxEl */
boolean IsQueuekFull(Queue Q) {
    return (NBElmt(Q) == MaxEl);
}

/* Proses: Menambahkan X pada Q dengan aturan FIFO */
void AddQueue(Queue *Q, infotype X) {
    if (IsQueuekEmpty(*Q)) {
        Head(*Q) = 1;
        Tail(*Q) = 1;
        InfoTail(*Q) = X;
    } else {
        if (Tail(*Q) == MaxEl) {
            Tail(*Q) = 1;
        } else {
            Tail(*Q)++;
        }
        InfoTail(*Q) = X;
    }
}

/* Proses: Menghapus X pada Q dengan aturan FIFO */
void DelQueue(Queue *Q, infotype *X) {
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        if (Head(*Q) == MaxEl) {
            Head(*Q) = 1;
        } else {
            Head(*Q)++;
        }
    }
}

/* I.S : S terdefinisi, mungkin kosong
   F.S : Jika Queue tidak kosong, semua info yang disimpan pada elemen queue diprint. */
void PrintQueueInfo(Queue Q) {
    if (IsQueuekEmpty(Q)) {
        printf("Queue is empty\n");
    } else {
        address i = Head(Q);
        while (1) {
            printf("|%d|", Q.T[i]);
            if (i == Tail(Q)) break;
            if (i == MaxEl) {
                i = 1;
            } else {
                i++;
            }
        }
        printf("\n");
    }
}

/* mengirim true jika x ada pada Q */
boolean isInfoKetemu(Queue Q, infotype X) {
    if (IsQueuekEmpty(Q)) {
        return false;
    } else {
        address i = Head(Q);
        do {
            if (Q.T[i] == X) {
                return true;
            }
            if (i == MaxEl) {
                i = 1;
            } else {
                i++;
            }
        } while (i != Tail(Q));
        return (Q.T[Tail(Q)] == X);
    }
}

/* Search apakah ada elemen tabel T yang bernilai X
   Jika x ada pada Q, menghasilkan address terkecil
   Jika tidak ada, mengirimkan Nil
   Memakai Skema search DENGAN boolean Found */
address CariElemenQueue(Queue Q, int X) {
    if (IsQueuekEmpty(Q)) {
        return Nil;
    } else {
        address i = Head(Q);
        do {
            if (Q.T[i] == X) {
                return i;
            }
            if (i == MaxEl) {
                i = 1;
            } else {
                i++;
            }
        } while (i != Tail(Q));
        if (Q.T[Tail(Q)] == X) {
            return Tail(Q);
        } else {
            return Nil;
        }
    }
}

