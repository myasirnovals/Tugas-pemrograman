#ifndef _STACK_H
#define _STACK_H
#include "boolean.h"
#include <stdio.h>
#include <conio.h>

#define Nil 0
#define MaxEl 10
#define IdxUndef -999

#define Top(S) (S).Top
#define Info(S) (S).T[(S).Top]
#define ElStack(S) (S).T[i]


typedef int infotype;
typedef int addres;
typedef struct 
{
    infotype T[MaxEl+1];
    addres Top;
}Stack;

void CreateStack(Stack *S);
void BacaStack(Stack *S);

boolean IsStackEmpty(Stack S);
boolean IsStackFull(Stack S);
void Push(Stack *S,infotype X);
void pop(Stack *S,infotype *X);
void PrintStackInfo(Stack S);
boolean IsKetemu(Stack S, infotype X);
addres CariElemenStack(Stack S, infotype X);

#endif