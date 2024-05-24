#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void CreateStack(Stack *S)
{
    Top(*S) = Nil;
}

addres Alokasi(infotype X)
{
    addres NewNode;

    Info(NewNode) = X;
    Next(NewNode) = Nil;
}
void Dealokasi(addres p)
{
    free(p);
}

void Push(Stack *S, infotype X)
{
    addres NewNode;
    NewNode = Alokasi(X);

    if (IsStackEmpty)
    {
        Next(NewNode) = Top(*S);
        Top(*S) = NewNode;
        Bottom(*S) = NewNode;
    }
    else
    {
        Next(NewNode) = Top(*S);
        Top(*S) = NewNode;
    }
}
void Pop(Stack *S, infotype *X)
{
    if (IsStackEmpty)
    {
        printf("\nStack Kosong");
    }else
    {
        (*X) = Info(Top(*S));
        Top(*S) = Next(Top(*S));
    }
}
void PrintInfo(Stack S)
{
    addres Current;
    if (IsStackEmpty)
    {
        printf("\nStack kosong");
    }else
    {
        
        Current = Top(S);
        while (Current != Next(Bottom(S)))
        {
            printf("[%d]", Info(Current));
            Current = Next(Current);
        }
    }
}
boolean IsStackEmpty(Stack S)
{
    if (Top(S) == Nil)
    {
        return true;
    }else
    {
        return false;
    }
    
    
}
boolean CariElemenStack(Stack S, infotype X)
{
    addres Current;
    Current = Top(S);
    boolean ketemu;
    ketemu = false;
    
    while (Current != Next(Bottom(S)) && !ketemu)
    {
        if (Info(Current) == X)
        {
            ketemu = true;
        }
        
    }

    return ketemu;
    
}