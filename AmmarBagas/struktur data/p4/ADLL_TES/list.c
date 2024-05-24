#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void CreateList(List *L)
{
    First(*L) = Nil;
}

addres Alokasi(InfoType X)
{
    addres NodeBaru;

    NodeBaru = (ElmList *)malloc(sizeof(ElmList));

    info(NodeBaru) = X;
    next(NodeBaru) = Nil;

    return NodeBaru;
}

void DeAlokasi(addres P)
{
    free(P);
}

boolean ListEmpty(List L)
{
    if (First(L) == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void InsFirst(List *L, InfoType X)
{
    addres NodeBAru;

    NodeBAru = Alokasi(X);

    next(NodeBAru) = First(*L);
    First(*L) = NodeBAru;
}

void InsLast(List *L, InfoType X)
{
    addres current, NewNode;

    NewNode = Alokasi(X);
    current = First(*L);

    if (First(*L) == Nil)
    {
        InsFirst(&(*L),X);
    }else
    {
        while (next(current) != Nil)
        {
            current = next(current);
        }

        next(current) = NewNode;
        next(NewNode) = Nil;
    }
    
    


}

void DelFirst(List *L, InfoType *X)
{
    addres DelNode;

    if (First(*L) == Nil)
    {
        (*X) = 0;
    }
    else
    {
        DelNode = First(*L);
        First(*L) = next(First(*L));
        (*X) = info(DelNode);
        DeAlokasi(DelNode);
    }
}

void DelLast(List *L, InfoType *X)
{
    addres PrevNode, DelNode;

    DelNode = First(*L);
    PrevNode = Nil;
    if (ListEmpty((*L)))
    {
        (*X) = 0;
    }
    else if (next(First(*L)) == Nil)
    {
        DelFirst(&(*L), &(*X));
    }
    else
    {
        while (next(DelNode) != Nil)
        {
            PrevNode = DelNode;
            DelNode = next(DelNode);
        }
        (*X) = info(DelNode);
        next(PrevNode) = next(DelNode);
        DeAlokasi(DelNode);
    }
}

void DelAfter(List *L, InfoType *X, InfoType Y)
{
    addres current, Delnode;
    boolean ketemu;
    current = First(*L);
    ketemu = false;

    if (ListEmpty((*L)))
    {
        (*X) = 0;
    }
    else
    {
        if (next(First(*L)) == Nil)
        {
            (*X) = 0;
        }
        else
        {
            while (current != Nil && !ketemu)
            {
                if (info(current) == Y)
                {
                    Delnode = next(current);
                    (*X) = info(Delnode);
                    next(current) = next(Delnode);
                    DeAlokasi(Delnode);
                    ketemu = true;
                }
                else
                {
                    (*X) = 0;
                    current = next(current);
                }
            }
        }
    }
}

void PrintInfo(List L)
{
    addres Current;
    Current = First(L);
    while (Current != Nil)
    {
        printf("[%d]->", info(Current));
        Current = next(Current);
    }
    printf("Nill");
}

int NbElm(List L)
{
    addres Count;
    int CountElm;
    Count = First(L);
    CountElm = 0;

    while (Count != Nil)
    {
        Count = next(Count);
        CountElm++;
    }
    return CountElm;
}

addres Search(List L, InfoType X)
{
    addres current;

    while (current != Nil)
    {
        if (info(current) == X)
        {
            return current;
        }
        current = next(current);
    }
    return Nil;
}

void InversList(List *L)
{
    addres Prev, Current, NextNode;

    Prev = Nil;
    Current = First(*L);
    while (Current != Nil)
    {
        NextNode = next(Current);
        next(Current) = Prev;
        Prev = Current;
        Current = NextNode;
    }

    First(*L) = Prev;
}

List GetNewInvers(List L)
{
    List NewList;

    CreateList(&NewList);
    NewList = L;

    InversList(&NewList);
    return NewList;
}

void BacaList(List *L)
{
    InfoType x;
    printf("Masukan info elemen list :");scanf("%d",&x);

    while (x != 999)
    {
        InsLast(&(*L),x);
        printf("Masukan info elemen list :");scanf("%d",&x);
    }
    
}