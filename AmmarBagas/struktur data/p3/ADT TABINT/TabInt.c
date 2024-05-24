#include <stdio.h>
#include <conio.h>
#include "TabInt.h"

/*konstruktor*/
void CreateTabInt(TabInt *T)
{
    (*T).neff = 0;
}
/*selektor tabint*/
int GetJumElmt(TabInt T)
{
    return T.neff;
}
int GetFirstIdx(TabInt T)
{
    return T.T1[1];
}
int GetLlastIdx(TabInt T)
{
    return T.T1[T.neff];
}
int GetElmt(TabInt T, int index)
{
    return T.T1[index];
}
/*set nilai*/
void SetElm(TabInt *T, int i, int v)
{
    (*T).T1[i] = v;
}
/*kelompok operasi cek elemen kosong atau penuh*/
boolean isEmpty(TabInt T)
{
    if (T.neff == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
boolean IsFull(TabInt T)
{
    if (T.neff == nMax)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*kelompok operasi input output device*/
void BacaElm(TabInt *T)
{
    int Elm;
    printf("Masukan Elemen :");
    scanf("%d", &Elm);
    while (Elm != 999)
    {
        AddElm(&(*T), Elm);
        printf("Masukan Elemen :");
        scanf("%d", &Elm);
    }
}
void CetakTabInt(TabInt T)
{
    for (int i = 1; i <= T.neff; i++)
    {
        printf("[%d]", T.T1[i]);
    }
}
void AddElm(TabInt *T, int x)
{
    if (!IsFull((*T)))
    {
        (*T).neff++;
        (*T).T1[(*T).neff] = x;
    }
}
/*kelompok operasi aritmatika*/
TabInt KaliTab(TabInt Tab1, TabInt Tab2)
{
    TabInt NewTAb;
    
    CreateTabInt(&NewTAb);
    if (!isEmpty(Tab1) && !isEmpty(Tab2) && Tab1.neff == Tab2.neff)
    {
        for (int i = 1; i <= Tab1.neff; i++)
        {
            AddElm(&NewTAb, Tab1.T1[i] * Tab2.T1[i]);
        }
    }
    return NewTAb;
}
TabInt KaliKons(TabInt T, int c)
{
    TabInt NewTab;
    CreateTabInt(&NewTab);
    for (int i = 1; i <= T.neff; i++)
    {
        AddElm(&NewTab, T.T1[i] * c);
    }
    return NewTab;
}
/*kelompok operasi relasional terhadap TabInt*/
boolean IsEQTab(TabInt Tab1, TabInt Tab2)
{
    if (Tab1.neff == Tab2.neff)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*kelompok operasi lain terhadap type*/
void CopyTab(TabInt Tabin, TabInt *Tabout)
{
    (*Tabout) = Tabin;
}
TabInt InversTab(TabInt T)
{
    TabInt NewTab;
    CreateTabInt(&NewTab);
    for (int i = T.neff; i >= 1; i--)
    {
        AddElm(&NewTab, T.T1[i]);
    }

    return NewTab;
}
boolean IsElemenAda(TabInt T, ElType X)
{
    int i;
    boolean hasil;
    i = 1;
    hasil = false;
    while (i <= T.neff && !hasil)
    {
        if (T.T1[i] == X)
        {
            hasil = true;
        }
        else
        {
            i++;
        }
    }

    return hasil;
}
int CariElemen(TabInt T, ElType X)
{
    int i = 1;
    boolean ketemu;
    ketemu = false;
    while (i <= T.neff && !ketemu)
    {
        if (T.T1[i] == X)
        {
            return i;
            ketemu = true;
        }
        else
        {
            i++;
        }
    }

    return IdxUndef;
}