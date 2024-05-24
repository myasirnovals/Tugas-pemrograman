#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void CreateStack(Stack *S)
{
    Top(*S) = Nil;
}

void BacaStack(Stack *S)
{
    infotype x;

    printf("Masukan info Stack :");
    scanf("%d", &x);

    while (x != 999)
    {
        Push(*(&S), x);
        printf("\nMasukan info Stack :");
        scanf("%d", &x);
    }
}

boolean IsStackEmpty(Stack S)
{
    if (Top(S) == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}
boolean IsStackFull(Stack S)
{
    if (Top(S) == MaxEl)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Push(Stack *S, infotype X)
{
    if (IsStackFull)
    {
        printf("\nStack Full");
    }
    else
    {
        Top(*S)++;
        Info(*S) = X;
    }
}
void pop(Stack *S, infotype *X)
{
    if (IsStackEmpty)
    {
        printf("\nStack kosong");
    }
    else
    {
        (*X) = Info(*S);
        Top(*S)--;
    }
}
void PrintStackInfo(Stack S)
{

    if (IsStackEmpty)
    {
        printf("Nil");
    }
    else
    {
        for (addres i = Top(S); i >= 1; i--)
        {
            printf("[%d]", ElStack(S));
        }
    }
}
boolean IsKetemu(Stack S, infotype X)
{
    boolean ketemu;
    addres i;

    i = Top(S);
    while (Top(S) != Nil && !ketemu)
    {
        if (ElStack(S) == X)
        {
            ketemu = true;
        }
        else
        {
            i--;
        }
    }
    return ketemu;
}
addres CariElemenStack(Stack S, infotype X)
{
    boolean ketemu;
    addres i;

    i = Top(S);
    while (Top(S) != Nil && !ketemu)
    {
        if (ElStack(S) == X)
        {
            return i;
        }
        else
        {
            i--;
        }
    }
    if (!ketemu)
    {
        return IdxUndef;
    }
}
