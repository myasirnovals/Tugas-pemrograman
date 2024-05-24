/*
    Program: tabint.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Memasukan instruksi yang akan dieksekusi didalam fungsi dan prosedur
    Tanggal: 28/03/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include "tabint.h"

void CreateTab(Tabint *T) {
    (*T).neff = 0;
}

int GetJumElm(Tabint T) {
    if(IsEmpty(T)) {
        return 0;
    } else {
        return T.neff;
    }
}

int GetFirstIndex(Tabint T) {
    return T.Tb[1];
}

int GetLastIndex(Tabint T) {
    return T.Tb[T.neff];
}

int GetElm(Tabint T, int index) {
    int i;

    if(index <= nmax) {
        for(i=1; i <= T.neff; i++) {
            if(T.Tb[i] == index) {
                return T.Tb[i];
            }
        }
        return false;
    
    } else {
        return false;
    }
}

void SetElm(Tabint *T, int i, int v) {
    if(i <= (*T).neff) {
        (*T).Tb[i] = v;
    
    } else {
        printf("index ke-%d tidak di ketahui", i);
    }
}

boolean IsEmpty(Tabint T) {
    if(T.neff == 0) {
        return true;
    } else {
        return false;
    }
}

boolean IsFull(Tabint T) {
    if(T.neff == nmax) {
        return true;
    } else {
        return false;
    }
}

void BacaElm(Tabint *T) {
    int Elm;

    printf("Masukan bilangan: ");
    scanf("%d", &Elm);

    while(Elm != 999) {
        AddElm(&(*T), Elm);
        printf("Masukan bilangan: ");
        scanf("%d", &Elm);
    }
}

void CetakTab(Tabint T) {
    int i;

    for(i=1; i <= T.neff; i++) {
        printf("<%d>", T.Tb[i]);
    }
}

void AddElm(Tabint *T, int x) {
    if(!IsFull(*T)) {
        (*T).neff++;
        (*T).Tb[(*T).neff] = x;
    } else {
        printf("Tabel Penuh");
    }
}

Tabint KaliTab(Tabint T1, Tabint T2) {
    Tabint NewTab;
    int i;

    CreateTab(&NewTab);
    if(!IsEmpty(T1) && !IsEmpty(T2) && IsEQTab(T1, T2)) {
        for(i=1; i<= T1.neff; i++) {
            AddElm(&NewTab, T1.Tb[i] * T2.Tb[i]);
        }
    } else {
        return NewTab;
    }

    return NewTab;
}

Tabint KaliKons(Tabint T, int c) {
    Tabint NewTab;
    int i;

    CreateTab(&NewTab);
    for(i=1; i<=T.neff; i++) {
        AddElm(&NewTab, T.Tb[i] * c);
    }

    return NewTab;
}

boolean IsEQTab(Tabint T1, Tabint T2) {
    if(T1.neff == T2.neff) {
        return true;
    } else {
        return false;
    }
}

void CopyTab(Tabint TabIn, Tabint *TabOut) {
    (*TabOut) = TabIn;
}

Tabint InversTab(Tabint T) {
    Tabint NewTab;
    int i;

    CreateTab(&NewTab);
    for(i=1; i<=T.neff; i++) {
        AddElm(&NewTab, T.Tb[i]);
    }

    return NewTab;
}

boolean IsElmAda(Tabint T, ElType X) {
    int i;
    boolean ketemu;

    i = 1;
    ketemu = false;
    while(i <= T.neff && !ketemu) {
        if(T.Tb[i]==X) {
            ketemu = true;
        } else {
            i++;
        }
    }

    return ketemu;
}

int CariElm(Tabint T, ElType X) {
    int i;

    if(IsEmpty(T)) {
        return indexUndef;
    } else {
        for(i=1; i<=T.neff; i++) {
            if(T.Tb[i] == X) {
                return i;
            }
        }
        return indexUndef;
    }
}