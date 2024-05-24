/*
    Program: queue.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Memasukan instruksi yang akan dieksekusi didalam fungsi dan prosedur
    Tanggal: 02/04/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void createQueue(Queue *Q) {
    (*Q).HEAD = Nil;
    (*Q).TAIL = Nil;
}

int JumElm(Queue Q) {
    if(Q.HEAD == 0 && Q.TAIL) {
        return 0;
    } else {
        return Q.TAIL;
    }
}

boolean IsQueueEmpty(Queue Q) {
    if(Q.HEAD == Nil && Q.TAIL == Nil) {
        return true;
    } else {
        return false;
    }
}

boolean IsQueueFull(Queue Q) {
    if(Q.TAIL == MaxElm) {
        return true;
    } else {
        return false;
    }
}

void addQueue(Queue *Q, infoType X) {
    if(IsQueueFull(*Q)) {
        printf("Tidak dapat menampung elemen Q dikarenakan sudah penuh\n");
    } else {
        (*Q).HEAD = 1;
        (*Q).TAIL++;
        (*Q).T[(*Q).TAIL] = X;
    }
}

void deleteQueue(Queue *Q, infoType X) {
    int tmp, i, j;

    tmp = 0;
    if(IsQueueEmpty(*Q)) {
        printf("Penampung elemen Q kosong\n");
    } else {
        for(i=1; i<=(*Q).TAIL; i++) {
            if((*Q).T[i] == X) {
                if((*Q).T[i] == (*Q).T[(*Q).HEAD]) {
                    tmp = (*Q).T[i];
                    break;
                } else {
                    printf("Elemen tidak bisa dihapus, karena tidak sesuai dengan aturan FIFO\n");
                }
            }
        }
        
        if(tmp != Nil) {
            for(j=1; j<=(*Q).TAIL; j++) {
                (*Q).T[j] = (*Q).T[j+1];
            }
            (*Q).TAIL--;
        } else {
            printf("Penghapusan elemen gagal");
        }
    }
}

void cetakQueue(Queue S) {
    int i;

    if(IsQueueEmpty(S)) {
        printf("Tabel Queue Kosong\n");
    } else {
        for(i=1; i<=S.TAIL; i++) {
            printf("<%d>", S.T[i]);
        }
    }
}

boolean IsKetemu(Queue S, infoType X) {
    int i;

    if(IsQueueEmpty(S)) {
        return false;
    } else {
        for(i=1; i<=S.TAIL; i++) {
            if(S.T[i] == X) {
                return true;
            }
        }

        return false;
    }
}

address cariElmQueue(Queue Q, int X) {
    int i;

    if(IsQueueEmpty(Q)) {
        return false;
    } else {
        for(i=1; i<=Q.TAIL; i++) {
            if(Q.T[i] == X) {
                return i;
            }
        }

        return false;
    }
}

int Elemen(int x) {
    return x;
}