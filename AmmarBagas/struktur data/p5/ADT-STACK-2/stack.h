#ifndef _STACK2_H
#define _STACK2_H

#include "boolean.h"
#include <stdio.h>
#include <conio.h>

#define Info(P) (P)->Info
#define Next(P) (P)->Next
#define Top(S) (S).Top
#define Bottom(S) (S).Bottom
#define Nil NULL

typedef int infotype;
typedef struct tElmStack *addres;

typedef struct tElmStack
{
    infotype Info;
    addres Next;
}ElmStack;

typedef struct
{
    addres Top;
    addres Bottom;
} Stack;

void CreateStack(Stack *S);

addres Alokasi(infotype X);
void Dealokasi(addres p);

void Push(Stack *S, infotype X);
void Pop(Stack *S, infotype *X);
void PrintInfo(Stack S);
boolean IsStackEmpty(Stack S);
boolean CariElemenStack(Stack S, infotype X);

#endif
