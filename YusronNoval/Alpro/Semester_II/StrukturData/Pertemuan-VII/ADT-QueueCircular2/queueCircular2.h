/*
    Program: queueCircular2.h
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Membuat beberapa fungsi dan prosedur
    Tanggal: 09/04/2024
*/
#ifndef _QUEUE_H
#define _QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#define Nil 0
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Head(S) (S).HEAD
#define Tail(S) (S).TAIL

typedef struct tElmQueue *address;
typedef int infoType;

typedef struct tElmQueue {
    infoType info;
    address next;
} ElmQueue;

typedef struct {
    address HEAD;
    address TAIL;
} Queue;

void createQueue(Queue *Q);

address Alokasi(infoType X);
void Dealokasi(address P);

boolean isEmpty(Queue Q);

void addQueue(Queue *Q, infoType X);
void deleteQueue(Queue *Q, infoType *X);
void cetakQueue(Queue S);

boolean cariElm(Queue Q, infoType X);

#endif