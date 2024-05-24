/**
 * Program: doubleLinkedList.h
 * Author: (2350081004, Muhamad Yasir Noval)
 * Kelas: A
 * Deskripsi: Header file dari prototype double linked list
 * Tanggal: -
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

void CreateList(List *L);

address Alokasi(infoType X);

void Dealokasi(address P);

address CariElm(List L, infoType X);

void SisipDepan(List *L, infoType X);

void SisipTengah(List *L, infoType X, infoType position);

void SisipBelakang(List *L, infoType X);

void HapusDepan(List *L, infoType *X);

void HapusTengah(List *L, infoType *X, infoType position);

void HapusBelakang(List *L, infoType *X);

void CetakList(List L);

boolean ListEmpty(List L);

int jumlahElemen(List L);

void menuSisip(List *L);

void menuHapus(List *L);

void menuCari(List *L);

#endif
