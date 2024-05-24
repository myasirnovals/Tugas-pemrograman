/**
 * Program: stack2.h
 * Author: (2350081004, Muhamad Yasir Noval)
 *         (2350081028, Ricky Gunaldo)
 *         (2350081011, M Abhinaya Rakan A)
 * Kelas: A
 * Deskripsi: Header file dari stack
 * Tanggal: 10 Mei 2024
 */

#ifndef ADT_SRK_2_STACK2_H
#define ADT_SRK_2_STACK2_H

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "boolean.h"

// definisi pointer
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Top(S) (S).TOP
#define Bottom(S) (S).BOTTOM

// pendefinisian tipe stack
typedef struct tElmStack *address;
typedef int infoType;

typedef struct tElmStack{
    infoType info;
    address next;
} ElmStack;

typedef struct {
    address BOTTOM;
    address TOP;
} Stack;

// konstruktor
void CreateStack(Stack *S);

address Alokasi(infoType x);

// Destruktor
void DeAlokasi(address P);

// Operasi stack
void Push(Stack *S, infoType X);

void Pop(Stack *S, infoType *X);

void CetakStack(Stack S);

boolean IsStackEmpty(Stack S);

boolean CariElemenStack(Stack S, infoType x);

#endif //ADT_SRK_2_STACK2_H
