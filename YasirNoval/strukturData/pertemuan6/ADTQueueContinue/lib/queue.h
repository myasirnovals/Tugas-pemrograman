/**
 * Program: queue.h
 * Author: (2350081004, Muhamad Yasir Noval)
 * Kelas: A
 * Deskripsi: Header file dari queue
 * Tanggal: 16 Mei 2024
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"

#include <stdio.h>
#include <conio.h>

#define Nil 0
#define MaxEl 10
#define IdxUndef (-999)
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define InfoElm(Q) (Q).T[i]
#define InfoNextElm(Q) (Q).T[i + 1]

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
void DelQueue(Queue *Q, infotype *X);

// {Kelompok interaksi dengan i/o device, Baca/Tulis}
void PrintQueueInfo(Queue S);

// Kelompok operasi lain terhadap type
boolean isInfoKetemu(Queue S, infotype X);

address CariElemenQueue(Queue Q, int X);

#endif //QUEUE_H
