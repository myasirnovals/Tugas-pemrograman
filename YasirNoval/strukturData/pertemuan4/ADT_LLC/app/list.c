#include <stdlib.h>
#include "../lib/list.h"

void CreateList(List *L) {
    First(*L) = Nil;
}

address Alokasi(infoType X) {
    address NewNode;

    NewNode = (ElmList *) malloc(sizeof(ElmList));

    Info(NewNode) = X;
    Next(NewNode) = Nil;

    return NewNode;
}

void DeAlokasi(address P) {
    free(P);
}

boolean ListEmpty(List L) {
    if (First(L) == Nil) {
        return true;
    } else {
        return false;
    }
}

void InsFirst(List *L, infoType X) {
    address NewNode;

    NewNode = Alokasi(X);

    if (NewNode != Nil) {
        if (ListEmpty(*L)) {
            Info(NewNode) = X;
        }
    }
}

void InsLast(List *L, infoType X) {
    address NewNode, Current;

    NewNode = Alokasi(X);

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
    address NewNode, Current;
    int i;

    if (Y <= 1) {
        printf("Data akan ditambahkan ke bagian awal\n");
        InsFirst(L, X);
    } else if (Y >= NbElm(*L)) {
        printf("Data akan ditambahkan ke bagian akhir\n");
        InsLast(L, X);
    } else {
        NewNode = Alokasi(X);

        Info(NewNode) = X;
        Current = First(*L);

        for (i = 1; i < Y - 1; i++) {
            Current = Next(Current);
        }

        Next(NewNode) = Next(Current);
        Next(Current) = NewNode;
    }
}

void DelFirst(List *L, infoType *X) {
    address DelNode, Tmp;

    DelNode = First(*L);
    First(*L) = Next(First(*L));

    *X = Info(DelNode);
    Tmp = DelNode;
    DeAlokasi(Tmp);
}

void DelLast(List *L, infoType *X) {
    address DelNode, Current, Before, Tmp;
    int i;

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
    DeAlokasi(Tmp);
}

void DelAfter(List *L, infoType *X, infoType Y) {
    address DelNode, Current, Before, Tmp;
    int i;

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
        DeAlokasi(Tmp);
    }
}

void PrintInfo(List L) {
    address Current;

    Current = First(L);
    while (Current != Nil) {
        printf("[%d] -> ", Info(Current));

        Current = Next(Current);
    }

    printf("Null");
}

int NbElm(List L) {
    address Current;
    int i;

    Current = First(L);

    i = 0;
    while (Current != Nil) {
        Current = Next(Current);
        i++;
    }

    return i;
}

address Search(List L, infoType X) {
    address Current;

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
    List NewList;

    CreateList(&NewList);
    InversList(&L);

    NewList = L;

    return NewList;
}