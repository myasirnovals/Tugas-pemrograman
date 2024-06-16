/*
    Program     : list.c
    Author      : 2350081062, Aji Kartiko Hartanto
    Kelas       : C
    Deskripsi   : Prototype ADT LLL
    Tanggal     : 03-04-2024
*/

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// Prototype linear list
// konstruktor
void CreateList(List *L) {
    First(*L) = Nil;
}

// Destruktor/Dealokator
address Alokasi(infoType X) {
    // Kamus
    address NewNode;

    // Alokasi memori menggunakan Malloc
    NewNode = (ElmList *) malloc(sizeof(ElmList));

    // algoritma
    Info(NewNode) = X;
    Next(NewNode) = Nil;

    return NewNode;
}

void DeAlokasi(address P) {
    // Dealokasi memori (membebaskan/menghapus alamat memori)
    free(P);
}

// {Kelompok operasi cek elemen kosong atau penuh}
boolean ListEmpty(List L) {
    if (First(L) == Nil) {
        return true;
    } else {
        return false;
    }
}

// {Kelompok interaksi dengan I/O device, Baca/Tulis}
// Penambahan elemen
void InsFirst(List *L, infoType X) {
    // Kamus
    address NewNode;

    // Alokasi memori
    NewNode = Alokasi(X);

    // algoritma
    if (NewNode != Nil) {
        Info(NewNode) = X;
        Next(NewNode) = First(*L);

        First(*L) = NewNode;
    }
}

void InsLast(List *L, infoType X) {
    // Kamus
    address NewNode, Current;

    // Alokasi memori
    NewNode = Alokasi(X);

    // algoritma
    Current = First(*L);

    if (NewNode != Nil) {
        while (Next(Current) != Nil) {
            Current = Next(Current);
        }

        Info(NewNode) = X;
        Next(NewNode) = Nil;

        Next(Current) = NewNode;
    }
}

void InsAfter(List *L, infoType X, infoType Y) {
    // Kamus
    address NewNode, Current;
    int i;

    if (Y <= 1) {
        printf("Data akan ditambahkan ke bagian awal\n");
        InsFirst(L, X);
    } else if (Y >= NbElm(*L)) {
        printf("Data akan ditambahkan ke bagian akhir\n");
        InsLast(L, X);
    } else {
        // alokasi
        NewNode = Alokasi(X);

        // Algoritma
        Info(NewNode) = X;
        Current = First(*L);

        for (i = 1; i < Y - 1; i++) {
            Current = Next(Current);
        }

        Next(NewNode) = Next(Current);
        Next(Current) = NewNode;
    }
}

// Penghapusan elemen
void DelFirst(List *L, infoType *X) {
    // kamus
    address DelNode, Tmp;

    // algoritma

    DelNode = First(*L);
    First(*L) = Next(First(*L));

    // dealokasi memori
    *X = Info(DelNode);
    Tmp = DelNode;
    DeAlokasi(Tmp);
}

void DelLast(List *L, infoType *X) {
    // kamus
    address DelNode, Current, Before, Tmp;
    int i;

    // algoritma
    i = 1;
    Current = First(*L);

    while (i <= NbElm(*L) && Current != Nil) {
        if (i == NbElm(*L) - 1) {
            Before = Current;
        }

        if (i == NbElm(*L)) {
            DelNode = Current;
        }

        Current = Next(Current);
        i++;
    }

    Next(Before) = Nil;

    *X = Info(DelNode);
    Tmp = DelNode;
    free(Tmp);
}

void DelAfter(List *L, infoType *X, infoType Y) {
    // Kamus
    address DelNode, Current, Before, Tmp;
    int i;

    // Algoritma
    if (Y <= 1) {
        printf("Data akan dihapus pada bagian awal");
        DelFirst(L, X);
    } else if (Y >= NbElm(*L)) {
        printf("Data akan dihapus pada bagian akhir");
        DelLast(L, X);
    } else {
        i = 1;
        Current = First(*L);

        while (i <= Y) {
            if (i == Y - 1) {
                Before = Current;
            }

            if (i == Y) {
                DelNode = Current;
            }

            Current = Next(Current);
            i++;
        }

        Next(Before) = Current;

        *X = Info(DelNode);
        Tmp = DelNode;
        free(Tmp);
    }
}

// cetak list
void PrintInfo(List L) {
    address Current;

    Current = First(L);
    while (Current != Nil) {
        printf("[%d] -> ", Info(Current));

        Current = Next(Current);
    }

    printf("Null");
}

// Kelompok operasi lain terhadap type
int NbElm(List L) {
    // kamus
    address Current;
    int i;

    // algoritma
    Current = First(L);

    i = 0;
    while (Current != Nil) {
        Current = Next(Current);
        i++;
    }

    return i;
}

address Search(List L, infoType X) {
    // kamus
    address Current;

    // algoritma
    Current = First(L);
    while (Current != Nil) {
        if (Info(Current) == X) {
            return Current;
        }

        Current = Next(Current);
    }

    return Nil;
}

void InversList(List *L) {
    address Prev, Current, NextNode;

    Prev = Nil;
    Current = First(*L);
    while (Current != Nil) {
        NextNode = Next(Current);
        Next(Current) = Prev;
        Prev = Current;
        Current = NextNode;
    }

    First(*L) = Prev;
}

List getNewInversList(List L) {
    // kamus
    List NewList;

    // algoritma
    CreateList(&NewList);
    InversList(&L);

    NewList = L;

    return NewList;
}