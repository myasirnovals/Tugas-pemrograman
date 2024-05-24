#ifndef _TABINT_H
#define _TABINT_H
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#define nMax 10
#define ElType int
#define IdxUndef -999
typedef struct 
{
    ElType T1[nMax +1];
    int neff;
    /* data */
}TabInt;



/*konstruktor*/
void CreateTabInt(TabInt *T);
/*selektor tabint*/
int GetJumElmt(TabInt T);
int GetFirstIdx(TabInt T);
int GetLlastIdx(TabInt T);
int GetElmt(TabInt T, int index);
/*set nilai*/
void SetElm(TabInt *T,int i,int v);
/*kelompok operasi cek elemen kosong atau penuh*/
boolean isEmpty(TabInt T);
boolean IsFull(TabInt T);
/*kelompok operasi input output device*/
void BacaElm(TabInt *T);
void CetakTabInt(TabInt T);
void AddElm(TabInt *T,int x);
/*kelompok operasi aritmatika*/
TabInt KaliTab(TabInt Tab1,TabInt Tab2);
TabInt KaliKons(TabInt T, int c);
/*kelompok operasi relasional terhadap TabInt*/
boolean IsEQTab(TabInt Tab1, TabInt Tab2);
/*kelompok operasi lain terhadap type*/
void CopyTab(TabInt Tabin, TabInt *Tabout);
TabInt InversTab(TabInt T);
boolean IsElemenAda(TabInt T, ElType X);
int CariElemen(TabInt T, ElType X);


#endif

