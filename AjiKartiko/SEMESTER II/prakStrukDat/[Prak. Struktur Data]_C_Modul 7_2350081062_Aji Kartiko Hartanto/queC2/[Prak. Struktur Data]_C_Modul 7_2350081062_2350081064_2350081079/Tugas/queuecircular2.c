/*
	Program		: queuecircular2.c
   	Author		: 2350081062 Aji Kartiko Hartanto
				  2350081064 Jarwo Eddy Wicaksono
				  2350081079 Rifqi Fauzi Anwar
	Kelas		: C
	Deskripsi	: Body File ADT Queue Circular
	Tanggal		: 29 Mei 2024
*/

#include "queuecircular2.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//Konstruktor
void CreateQueue(Queue *Q){
	Head(*Q) = Tail(*Q) = nil;
}

address Alokasi(int X){
//Kamus Lokal
	ElmQueue *P;	
//Algoritma
	P = (ElmQueue*)malloc(sizeof(ElmQueue));
	if(P != nil){
		info(P) = X;
		next(P) = nil;
		return P;
	} 
	else{
		return nil;
	}
}

//Operasi Queue
void AddQueue(Queue *Q, int X){
//Kamus Lokal
	address P;
	ElmQueue *T;
//Algoritma
	P = Alokasi(X);
	T = Tail(*Q);
	if(IsQueueEmpty(*Q)){
		next(P) = Head(*Q);
		next(P) = Tail(*Q);
		Head(*Q) = P;
		Tail(*Q) = P;
	} 
	else{
		while (next(T) != nil){
			T = next(T);
		}
		next(T) = P;
		Tail(*Q) = P;
	}
}

void DelQueue(Queue *Q, int *Y){
    address P = Head(*Q);
    *Y = info(P);

    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) = nil;
        Tail(*Q) = nil;
    } else {
        Head(*Q) = next(Head(*Q));
        next(P) = nil;
    }
}

//Operasi I/O terhadap Queue
void CetakQueue(Queue Q){
//Kamus Lokal
	ElmQueue *P, *S;	
//Algoritma
	if(!IsQueueEmpty(Q)){
		P = Head(Q);
		while(P != nil){
			printf(" [ %d ]", info(P));
			P = next(P);
		}
	} 
	else{
		printf("[ Empty ]");
	}
}

//Operasi boolean dan relasi terhadap Queue
boolean IsQueueEmpty(Queue Q){
	if(Head(Q) == nil || Tail(Q) == nil){
		return 1;
	} else {
		return 0;
	}
}

boolean CariElemenQueue(Queue Q, int X){
//Kamus Lokal
	address P;
	boolean ketemu;
//Algoritma
	P = Head(Q);
	ketemu = false;
	if(!IsQueueEmpty(Q)){
		while(P != nil && ketemu == false){
			if(info(P) == X){
				return 1;
				ketemu = true;
			}
			P = next(P);
		}
		return 0;
	}
}

//Operasi tambahan terhadap Queue
int GetIndex(Queue Q, address P) {
    int index = 1;
    address current = Head(Q);
    while (current != nil) {
        if (current == P) {
            return index;
        }
        index++;
        current = next(current);
    }
    return -1;
}

void PrintQueueData(Queue Q) {
    printf("\nNilai HEAD = %d\n", info(Head(Q)));
    printf("HEAD berada pada index ke %d\n", GetIndex(Q, Head(Q)));
    printf("Nilai TAIL = %d\n", info(Tail(Q)));
    printf("TAIL berada pada index ke %d\n", GetIndex(Q, Tail(Q)));
    
    // Menghitung Banyak Antrian
    int count = 0;
    address P = Head(Q);
    while (P != nil) {
        count++;
        P = next(P);
    }
    printf("Banyak Antrian = %d\n", count);

    // Menghitung Rata-Rata
    int total = 0;
    float avg = 0.0;
    P = Head(Q);
    while (P != nil) {
        total += info(P);
        P = next(P);
    }
    if (count > 0) {
        avg = (float)total / count;
    }
    printf("Waktu rata rata mengantri = %.2f\n", avg);
    printf("==================================\n");
}
