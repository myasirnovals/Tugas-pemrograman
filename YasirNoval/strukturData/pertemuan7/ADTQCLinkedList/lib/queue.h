/**
 * Program: queue.h
 * Author: (2350081004, Muhamad Yasir Noval)
 * Kelas: A
 * Deskripsi: Header file dari prototype queue
 * Tanggal: -
 */

#ifndef ADTQCLINKEDLIST_QUEUE_H
#define ADTQCLINKEDLIST_QUEUE_H

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "boolean.h"

// definisi pointer
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Head(S) (S).HEAD
#define Tail(S) (S).TAIL

// pendefinisian tipe stack
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

// Prototype Queue
// Konstruktor membentuk Queue
void CreateQueue(Queue *Q);

// Destruktor/Dealokator:
/*Pengalokasian Memory*/
// alokasi
address Alokasi(infoType x);

// Destruktor
void DeAlokasi(address P);

// {Kelompok operasi pada Queue}
boolean IsQueueEmpty(Queue Q);

// Menambahkan sebuah element ke queue
void AddQueue(Queue *Q, infoType X);

// Menghapus sebuah element queue
void DelQueue(Queue *Q, infoType *Y);

// {Kelompok interaksi dengan i/o device, Baca/Tulis}
void CetakQueue(Queue Q);

boolean CariElemenQueue(Queue Q, infoType X);

#endif //ADTQCLINKEDLIST_QUEUE_H
