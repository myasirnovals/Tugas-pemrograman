/*
    Program: queue.h
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Membuat beberapa fungsi dan prosedur
    Tanggal: 02/04/2024
*/
#ifndef _QUEUE_H
#define _QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#define Nil 0
#define MaxElm 10
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define infoHead(Q) (Q).T[(Q).HEAD]
#define infoTail(Q) (Q).T[(Q).TAIL]

typedef int infoType;
typedef int address;
typedef struct {
    infoType T[MaxElm+1];
    address HEAD;
    address TAIL;
} Queue;

void createQueue(Queue *Q);

int JumElm(Queue Q);

boolean IsQueueEmpty(Queue Q);
boolean IsQueueFull(Queue Q);

void addQueue(Queue *Q, infoType X);
void deleteQueue(Queue *Q, infoType X);
void cetakQueue(Queue S);

boolean IsKetemu(Queue S, infoType X);
address cariElmQueue(Queue Q, int X);
int Elemen(int x);

#endif