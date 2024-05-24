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
#define MaxEl 10
#define IdxUndef (-999)
#define Head(Q) (Q).Head
#define Tail(Q) (Q).Tail
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]

// Definisi Queue
typedef int infotype;
typedef int address;

typedef struct {
    infotype T[MaxEl + 1];
    address HEAD;
    address TAIL;
} Queue;

// Prototype Queue
// Konstruktor membentuk Queue
void CreateQueue(Queue * Q);

// {Operasi terhadap komponen: selektor Get dan Set} : tidak perlu sudah di define diatas
int NBElmt(Queue Q);

// Destruktor/Dealokator: tidak perlu

// {Kelompok operasi pada Queue}
boolean IsQueueEmpty(Queue Q);

boolean IsQueueFull(Queue Q);

// Menambahkan sebuah element ke queue
void AddQueue(Queue *Q, infotype X);

// Menghapus sebuah element queue
void DelQueue(Queue *Q, infotype X);

// {Kelompok interaksi dengan i/o device, Baca/Tulis}
void PrintQueueInfo(Queue S);

// Kelompok operasi lain terhadap type
boolean isInfoKetemu(Queue S, infotype X);

address CariElemenQueue(Queue Q, int X);

int elemen (int x);

#endif //QUEUE_H