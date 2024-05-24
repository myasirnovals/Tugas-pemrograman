/*
    Program: stack_1.h
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
#define Nil 0
#define maxElm 10
#define Top(S) (S).TOP
#define infoTop(S) (S).T[(S).TOP]
#define popTop(S) (S).T[(S).TOP - 1]
#define elmTop(S) (S).T[i]

typedef int infoType;
typedef int address;

typedef struct {
    infoType T[maxElm+1];
    address TOP;
} Stack;

void createStack(Stack *S);

boolean isEmpty(Stack S);
boolean isFull(Stack S);

void Push(Stack *S, infoType X);
void Pop(Stack *S, infoType *X);
void cetakStack(Stack S);

boolean isKetemu(Stack S, infoType X);
address cariElm(Stack S, infoType X);

#endif