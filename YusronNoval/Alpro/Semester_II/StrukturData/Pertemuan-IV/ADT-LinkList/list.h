/*
    Program: list.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Membuat beberapa fungsi dan prosedur
    Tanggal: 02/04/2024
*/
#ifndef _LIST_H
#define _LIST_H
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#define NIL NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

typedef struct tElmList *address;
typedef int infoType;

typedef struct tElmList {
    infoType info;
    address next;
} ElmList;

typedef struct {
    address First;
} List;

void CreateList(List *L);
address Alokasi(infoType X);

void DeAlokasi(address P);
boolean ListEmpty(List L);
void InsFirst(List *L, infoType X);
void InsLast(List *L, infoType X);
void InsAfter(List *L, infoType X, infoType Y);
void DelFirst(List *L, infoType *X);
void DelLast(List *L, infoType *X);
void DelAfter(List *L, infoType *X, infoType  Y);
void PrintInfo(List L);

int NbElm(List L);
address Search(List L, infoType X);
void InversList(List *L);
List getNewInversList(List L);


#endif