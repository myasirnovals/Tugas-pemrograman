/*
    Program      : stack.h
    Author       : 2350081062, Aji Kartiko Hartanto
    Kelas        : C
    Deskripsi    : Header file dari prototype stack
    Tanggal      : 15 Mei 2024
*/

#ifndef ADT_SRK_STACK_H
#define ADT_SRK_STACK_H

#include <stdio.h>
#include <conio.h>

#include "boolean.h"

#define Nil 0
#define MaxEl 10
#define IdxUndef (-999)

// Definisi akses dengan selektor: Set dan Get
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define PopTop(S) (S).T[(S).TOP - 1]
#define ElemenTop(S) (S).T[i]

// Definisi ADT tipe stack
typedef int infoType;
typedef int address;

typedef struct {
    infoType T[MaxEl + 1];
    address TOP;
} Stack;

// konstruktor
void CreateStack(Stack *S);

// {Kelompok operasi pada stack}
// Predikat untuk test keadaan Koleksi
boolean IsStackEmpty(Stack S);

boolean IsStackFull(Stack S);

// Menambahkan sebuah elemen ke stack
void Push(Stack *S, infoType X);

// Menghapus sebuah elemen stack
void Pop(Stack *S, infoType *X);

// Kelompok interaksi dengan I/O device, Baca/tulis
void PrintStackInfo(Stack S);

// Kelompok operasi lain terhadap type
boolean IsInfoKetemu(Stack S, infoType X);

address CariElemenStack(Stack S, infoType X);

#endif 