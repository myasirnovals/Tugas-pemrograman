#ifndef _LIST_H
#define _LIST_H
#include "../ADT LINK LIST/boolean.h"
#include<stdio.h>
#include<conio.h>

#define Nil NULL
#define info(P) P->info
#define next(P) P->next
#define First(L) (L).first

typedef int InfoType;
typedef struct tElmList *addres; 

typedef struct tElmList
{
    InfoType info;
    addres next;
}ElmList;

typedef struct 
{
    addres first;
}List;

void CreateList(List *L);

addres Alokasi(InfoType X);

void DeAlokasi(addres P);

boolean ListEmpty(List L);

void InsFirst(List *L, InfoType X);

void InsLast(List *L, InfoType X);

void DelFirst(List *L, InfoType *X);

void DelLast(List *L, InfoType *X);

void DelAfter(List *L, InfoType *X, InfoType Y);

void PrintInfo(List L);

int NbElm(List L);

addres Search(List L, InfoType X);

void InversList(List *L);

List GetNewInvers(List L);

void BacaList(List *L);

#endif