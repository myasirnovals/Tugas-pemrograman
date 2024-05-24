/*
    Program: tabint.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Membuat beberapa fungsi dan prosedur
    Tanggal: 28/03/2024
*/
#ifndef TABINT_H
#define TABINT_H
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#define nmax 10
#define ElType int
#define indexUndef -999

typedef struct {
    ElType Tb[nmax+1];
    int neff;
} Tabint;

void CreateTab(Tabint *T);

int GetJumElm(Tabint T);
int GetFirstIndex(Tabint T);
int GetLastIndex(Tabint T);
int GetElm(Tabint T, int index);

void SetElm(Tabint *T, int i, int v);

boolean IsEmpty(Tabint T);
boolean IsFull(Tabint T);

void BacaElm(Tabint *T);
void CetakTab(Tabint T);
void AddElm(Tabint *T, int x);

Tabint KaliTab(Tabint T1, Tabint T2);
Tabint KaliKons(Tabint T, int c);

boolean IsEQTab(Tabint T1, Tabint T2);
void CopyTab(Tabint TabIn, Tabint *TabOut);
Tabint InversTab(Tabint T);
boolean IsElmAda(Tabint T, ElType X);
int CariElm(Tabint T, ElType X);

#endif