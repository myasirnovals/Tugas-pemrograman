/*
    Program: stack_2.h
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Membuat beberapa fungsi dan prosedur
    Tanggal: 02/04/2024
*/
#ifndef _STACK_H
#define _STACK_H
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Top(S) (S).TOP
#define Bottom(S) (S).BOTTOM

typedef struct tElmStack *address;
typedef int infoType;

typedef struct tElmStack {
    infoType info;
    address next;
} ElmStack;

typedef struct {
    address BOTTOM;
    address TOP;
} Stack;

void createStack(Stack *S);

address Alokasi(infoType X);
void Dealokasi(address P);

void Push(Stack *S, infoType X);
void Pop(Stack *S, infoType *X);
void cetakStack(Stack S);

boolean isEmpty(Stack S);
boolean cariElm(Stack S, infoType X);

#endif