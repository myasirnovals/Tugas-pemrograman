/**
 * Program: doubleLinkedList.h
 * Author: kelompok
 * Kelas: A
 * Deskripsi: Header file dari prototype double linked list
 * Tanggal: -
 */

#include "../lib/doubleLinkedList.h"

// Konstruktor
void CreateList(List *L) {
    First(*L) = Nil;
}

// Alokasi dan De-Alokasi
address Alokasi(infoType X) {
    // kamus
    address newNode;

    // alokasi
    newNode = (ElmList *) malloc(sizeof(ElmList));

    // algoritma
    Info(newNode) = X;
    Next(newNode) = Nil;
    Prev(newNode) = Nil;

    return newNode;
}

void Dealokasi(address P) {
    free(P);
}

// Kelompok menu sisip
void SisipDepan(List *L, infoType X) {
    // kamus
    address newNode;

    // alokasi
    newNode = Alokasi(X);

    // algoritma
    if (newNode != Nil) {
        // memasukan elemen x kedalam node baru
        Info(newNode) = X;

        // set node baru prev dan next
        Prev(newNode) = First(*L);
        Next(newNode) = First(*L);

        // pindahkan first ke node baru
        First(*L) = newNode;
    }
}

void SisipTengah(List *L, infoType X, infoType elemen) {
    // kamus
    address newNode, current, after;
    boolean ketemu;

    // alokasi
    newNode = Alokasi(X);

    // algoritma
    current = First(*L);

    ketemu = tidak;
    while (Next(current) != Nil && !ketemu) {
        if (Info(current) == elemen) {
            // set node after dengan next dari current
            after = Next(current);

            // next daru current tunjuk ke node baru
            Next(current) = newNode;

            // set node baru prev dan next
            Prev(newNode) = current;
            Next(newNode) = after;

            // set node after dengan prev ke node baru
            Prev(after) = newNode;

            // ubah value untuk keluar dari loop
            ketemu = ya;
        }

        // increment loop
        current = Next(current);
    }

    if (Next(current) == Nil && Info(current) == elemen) {
        // jika elemen yang ingin disisipkan nya ketemu di akhir node
        SisipBelakang(L, X);

        ketemu = ya;
    } else if (ketemu == false) {
        // jika elemen yang ingin disisipkan nya tidak ketemu
        printf("\nError: data tidak ditemukan\n");
    }
}

void SisipBelakang(List *L, infoType X) {
    // kamus
    address newNode, current;

    // alokasi
    newNode = Alokasi(X);

    // algoritma
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
    // kamus
    address delNode;

    // algoritma
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
    // kamus
    address delNode, current, after, before;
    int i;

    // algoritma
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
    // kamus
    address delNode, before, current;

    // algoritma
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

// prosedur cetak list
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

// operasi lain yang dapat membantu dalam pembuatan ADT Double linked list
boolean ListEmpty(List L) {
    if (First(L) == Nil) {
        return true;
    } else {
        return false;
    }
}

address CariElm(List L, infoType X) {
    // kamus
    address current;

    // algoritma
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
