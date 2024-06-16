/*
    Program     : list.h
    Author      : 2350081062, Aji Kartiko Hartanto
    Kelas       : C
    Deskripsi   : header file prototype ADT LLL
    Tanggal     : 03-04-2024
*/

#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <conio.h>

#include "boolean.h"

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

// Definisi ADT List
typedef struct tElmList *address;
typedef int infoType;

typedef struct tElmList {
    infoType info;
    address next;
} ElmList;

typedef struct {
    address First;
} List;

// Prototype linear list
// konstruktor
void CreateList(List *L);

// Destruktor/Dealokator
address Alokasi(infoType X);

void DeAlokasi(address P);

// {Kelompok operasi cek elemen kosong atau penuh}
boolean ListEmpty(List L);

// {Kelompok interaksi dengan I/O device, Baca/Tulis}
// Penambahan elemen
void InsFirst(List *L, infoType X);

void InsLast(List *L, infoType X);

void InsAfter(List *L, infoType X, infoType Y);

// Penghapusan elemen
void DelFirst(List *L, infoType *X);

void DelLast(List *L, infoType *X);

void DelAfter(List *L, infoType *X, infoType  Y);

// cetak list
void PrintInfo(List L);

// Kelompok operasi lain terhadap type
int NbElm(List L);

address Search(List L, infoType X);

void InversList(List *L);

List getNewInversList(List L);

#endif //ADT_LLL_LIST_H