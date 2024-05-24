/*
    Program: queueCircular.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Memasukan instruksi yang akan dieksekusi didalam fungsi dan prosedur
    Tanggal: 02/04/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include "queueCircular.h"

void createQueue(Queue *Q) {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

int JumElm(Queue Q) {
    if(Head(Q) == Nil && Tail(Q) == Nil) {
        return Nil;
    } else {
        return Tail(Q);
    }
}

boolean isEmpty(Queue Q) {
    if(Head(Q) == Nil && Tail(Q) == Nil) {
        return true;
    } else {
        return false;
    }
}

boolean isFull(Queue Q) {
    if(Head(Q) == MaxElm || Tail(Q) == MaxElm) {
        return true;
    } else {
        return false;
    }
}

void addQueue(Queue *Q, infoType X) {
    if(isEmpty(*Q)) {
        Head(*Q)++;
        infoHead(*Q) = X;

        Tail(*Q) = Head(*Q);
    } else {
        if(!isFull(*Q)) {
            if(Head(*Q) <= Tail(*Q)) {
                Tail(*Q)++;
                infoTail(*Q) = X;
            } else {
                if(Tail(*Q)+1 != Head(*Q)) {
                    Tail(*Q)++;
                    infoTail(*Q) = X;
                } else {
                    printf("Queue sudah penuh\n");
                }
            }
        } else {
            Tail(*Q) = 1;
            infoTail(*Q) = X;
        }
    } 
}

void deleteQueue(Queue *Q, infoType *X) {
    if(!isEmpty(*Q)) {
        if(Head(*Q) == Tail(*Q)) {
            *X = infoHead(*Q);
            Head(*Q) = 0;
            Tail(*Q) = 0;
        } else {
            *X = infoHead(*Q);
            infoHead(*Q) = 0;

            if(!isFull(*Q)) {
                Head(*Q)++;
            } else {
                Head(*Q) = 1;
            }

            if(Tail(*Q) == (Head(*Q)-1+MaxElm) % MaxElm) {
                Tail(*Q) = (Tail(*Q)+1) % MaxElm;
            }
        }
    } else {
        printf("Queue kosong\n");
    }
}

void cetakQueue(Queue S) {
    int i;

    if(!isEmpty(S)) {
        for(i=1; i<=MaxElm; i++) {
            printf("(%d) ", infoElm(S));
        }
    } else {
        printf("\nQueue kosong\n");
    }
}

boolean IsKetemu(Queue S, infoType X) {
    int i;

    if(isEmpty(S)) {
        return false;
    } else {
        for(i=1; i<=MaxElm; i++) {
            if(infoElm(S) == X) {
                return true;
            }
        }
        return false;
    }
}

address cariElm(Queue Q, int X) {
    int i;

    if(isEmpty(Q)) {
        return false;
    } else {
        for(i=1; i<=MaxElm; i++) {
            if(infoElm(Q) == X) {
                return i;
            }
        }
        return false;
    }
}

void setQueue(Queue *Q) {
    int i;

    for(i=1; i<=MaxElm; i++) {
        infoElm(*Q) = 0;
    }
}