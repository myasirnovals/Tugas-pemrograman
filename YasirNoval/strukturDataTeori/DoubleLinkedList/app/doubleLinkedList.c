#include "../lib/doubleLinkedList.h"

void CreateList(List *L) {
    First(*L) = Nil;
}

address Alokasi(infoType X) {
    address newNode;

    newNode = (ElmList *) malloc(sizeof(ElmList));

    Info(newNode) = X;
    Next(newNode) = Nil;
    Prev(newNode) = Nil;

    return newNode;
}

void Dealokasi(address P) {
    free(P);
}

void SisipDepan(List *L, infoType X) {
    address newNode;

    newNode = Alokasi(X);

    if (newNode != Nil) {
        Info(newNode) = X;

        Prev(newNode) = First(*L);
        Next(newNode) = First(*L);

        First(*L) = newNode;
    }
}

void SisipTengah(List *L, infoType X, infoType elemen) {
    address newNode, current, after;
    boolean ketemu;

    newNode = Alokasi(X);

    current = First(*L);

    ketemu = tidak;
    while (Next(current) != Nil && !ketemu) {
        if (Info(current) == elemen) {
            after = Next(current);

            Next(current) = newNode;

            Prev(newNode) = current;
            Next(newNode) = after;

            Prev(after) = newNode;

            ketemu = ya;
        }

        current = Next(current);
    }

    if (Next(current) == Nil && Info(current) == elemen) {
        SisipBelakang(L, X);

        ketemu = ya;
    } else if (ketemu == false) {
        printf("\nError: data tidak ditemukan\n");
    }
}

void SisipBelakang(List *L, infoType X) {
    address newNode, current;

    newNode = Alokasi(X);

    current = First(*L);

    if (newNode != Nil) {
        while (Next(current) != Nil) {
            current = Next(current);
        }

        Next(current) = newNode;
        Prev(newNode) = current;
    }
}

// Kelompok menu hapus
void HapusDepan(List *L, infoType *X) {
    address delNode;

    if (!ListEmpty(*L)) {
        delNode = First(*L);
        First(*L) = Next(First(*L));

        *X = Info(delNode);
        Dealokasi(delNode);

        Prev(First(*L)) = Nil;
    } else {
        printf("\nError: List Kosong\n");
    }
}

void HapusTengah(List *L, infoType *X, infoType position) {
    address delNode, current, after, before;
    int i;

    if (!ListEmpty(*L)) {
        if (position == 1) {
            HapusDepan(L, X);
        } else if (position == jumlahElemen(*L)) {
            HapusBelakang(L, X);
        } else if (position < 1 || position > jumlahElemen(*L)) {
            printf("\nError: Elemen yang ingin anda hapus tidak ada di posisi tersebut\n");
            printf("Error: undefined index %d", position);
        } else {
            i = 1;
            current = First(*L);

            while (i <= position) {
                if (i == position - 1) {
                    before = current;
                }

                if (i == position) {
                    delNode = current;
                    after = Next(delNode);
                }

                current = Next(current);
                i++;
            }

            Next(before) = after;
            Prev(after) = before;

            *X = Info(delNode);

            Prev(delNode) = Nil;
            Next(delNode) = Nil;

            Dealokasi(delNode);
        }
    } else {
        printf("\nList Kosong\n");
    }
}

void HapusBelakang(List *L, infoType *X) {
    address delNode, before, current;

    current = First(*L);

    if (!ListEmpty(*L)) {
        while (Next(current) != Nil) {
            if (Next(Next(current)) == Nil) {
                before = current;
            }

            current = Next(current);
        }

        Next(before) = Nil;

        delNode = current;
        Prev(delNode) = Nil;

        *X = Info(current);
        Dealokasi(delNode);
    } else {
        printf("\nList Kosong\n");
    }
}

void CetakList(List L) {
    address current;

    current = First(L);
    if (!ListEmpty(L)) {
        printf("Null");
        while (current != Nil) {
            printf(" <- [%d] -> ", Info(current));

            current = Next(current);
        }

        printf("Null");
    } else {
        printf("\nList Kosong\n");
    }
}

boolean ListEmpty(List L) {
    if (First(L) == Nil) {
        return true;
    } else {
        return false;
    }
}

address CariElm(List L, infoType X) {
    address current;

    current = First(L);
    while (current != Nil) {
        if (Info(current) == X) {
            return current;
        }

        current = Next(current);
    }

    return Nil;
}

int jumlahElemen(List L) {
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
