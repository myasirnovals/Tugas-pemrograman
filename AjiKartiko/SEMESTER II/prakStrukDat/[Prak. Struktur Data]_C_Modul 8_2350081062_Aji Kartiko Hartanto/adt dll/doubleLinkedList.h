/*
    Program     : doubleLinkedList.h
    Author      : 2350081062, Aji Kartiko Hartanto
    Kelas       : C
    Deskripsi   : Header file dari prototype double linked list
    Tanggal     : 05-06-2024
*/

#ifndef DoubleLinkedList_H
#define DoubleLinkedList_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) (L).First

typedef int infoType;
typedef struct tElmList *address;

typedef struct tElmList {
    infoType info;
    address next;
    address prev;
} ElmList;

typedef struct {
    address First;
} List;

boolean ListEmpty(List L);

void CreateList(List *L);

address Alokasi(infoType X);

void Dealokasi(address P);

address Search(List L, infoType X);

void AddFirst(List *L, infoType X);

void AddLast(List *L, infoType X);

void DelFirst(List *L, infoType *X);

void DelLast(List *L, infoType *X);

void CetakList(List L);

#endif