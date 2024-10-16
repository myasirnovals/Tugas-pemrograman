/*
	Program		: queuecircular2.h
   	Author		: 2350081062 Aji Kartiko Hartanto
				  2350081064 Jarwo Eddy Wicaksono
				  2350081079 Rifqi Fauzi Anwar
	Kelas		: C
	Deskripsi	: Header File ADT Queue Circular
	Tanggal		: 29 Mei 2024
*/

#ifndef _QUEUE2_H
#define _QUEUE2_H
#include "boolean.h"
#include <stdio.h>
#include <conio.h>

//pendefinisian pointer
#define nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL

//Pembentukan tipe Queue
typedef struct tElmQueue *address;
typedef struct tElmQueue{
	int info;
	address next;
} ElmQueue;

typedef struct{
	address HEAD;
	address TAIL;
} Queue;

//Prototype Queue/ Primitif Queue dengan Pointer
//Konstruktor
void CreateQueue(Queue *Q);
/* I.S : Q terdefinisi tidak diketahui isinya
   F.S : Q diinisialisasi dengan HEAD(Q) = Nil, TAIL(Q) = Nil
*/

address Alokasi(int X);
/* Mengirim sebuah address jika alokasi type Queue berhasil */
/* P direlease dari memori */

//Operasi Queue
void AddQueue(Queue *Q, int X);
/* I.S : Q terdefinisi, mungkin kosong, dan
   F.S : Q bertambah sebuah elemen bernilai X dibelakang
   Proses : Head(Q) merupakan elemen terakhir dari Q
*/

void DelQueue(Queue *Q, int *Y);
/* I.S : Q terdefinisi sembarang tidak kosong
   F.S : Q berkurang satu elemen didepam disimpan pada Y
   Proses : Y = info(HEAD), HEAD(Q) = next(HEAD(Q))
   			Dealokasi elemen pertama
*/

//Operasi I/O terhadap Queue
void CetakQueue(Queue Q);
/* I.S : Q terdefinisi sembarang tidak kosong
   F.S : Elemen Queue dicetak dilayar
*/

//Operasi boolean dan relasi terhadap Queue
boolean IsQueueEmpty(Queue Q);
/* Mengirim true jika Queue kosong HEAD(Q) = nil
   false sebaliknya*/

boolean CariElemenQueue(Queue Q, int X);
/* Mengirim true jika elemen X ada pada Q,
   dan false jika X tidak ditemukan pada Q
   Skema pencarian dengan boolean
*/

//Operasi tambahan terhadap Queue
int GetIndex(Queue Q, address P);
/* Menentukan address dari nilai P */

void PrintQueueData(Queue Q);
#endif
