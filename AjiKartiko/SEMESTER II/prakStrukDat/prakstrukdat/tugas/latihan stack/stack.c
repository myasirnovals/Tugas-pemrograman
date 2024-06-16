/*
    Program      : stack.c
    Author       : 2350081062, Aji Kartiko Hartanto
    Kelas        : C
    Deskripsi    : Header file dari stack
    Tanggal      : 16 Mei 2024
*/

#include "stack.h"

// konstruktor
void CreateStack(Stack *S) {
    Top(*S) = Nil;
}

// {Kelompok operasi pada stack}
// Predikat untuk test keadaan Koleksi
boolean IsStackEmpty(Stack S) {
    if (Top(S) == Nil) {
        return true;
    } else {
        return false;
    }
}

boolean IsStackFull(Stack S) {
    if (Top(S) == MaxEl) {
        return true;
    } else {
        return false;
    }
}

// Menambahkan sebuah elemen ke stack
void Push(Stack *S, infoType X) {
    if (!IsStackFull(*S)) {
        Top(*S)++;
        InfoTop(*S) = X;
    } else {
        printf("Stack penuh");
    }
}

// Menghapus sebuah elemen stack
void Pop(Stack *S, infoType *X) {
    if (!IsStackEmpty(*S)) {
        *X = InfoTop(*S);
        Top(*S) = PopTop(*S);
    } else {
        printf("Stack kosong");
    }
}

// Kelompok interaksi dengan I/O device, Baca/tulis
void PrintStackInfo(Stack S) {
    // kamus
    int i;

    // algoritma
    for (i = 1; i <= Top(S); i++) {
        printf("[%d] ", ElemenTop(S));
    }
}

// Kelompok operasi lain terhadap type
boolean IsInfoKetemu(Stack S, infoType X) {
    // kamus
    int i;
    boolean ketemu;

    // algoritma
    i = 1;
    ketemu = tidak;
    while (i <= Top(S) && !ketemu) {
        if (ElemenTop(S) == X) {
            ketemu = ya;
        } else {
            i++;
        }
    }

    return ketemu;
}

address CariElemenStack(Stack S, infoType X) {
    // kamus
    int i;

    // algoritma
    if (!IsStackEmpty(S)) {
        for (i = 1; i <= Top(S); i++) {
            if (ElemenTop(S) == X) {
                return i;
            }
        }

        return IdxUndef;
    } else {
        return IdxUndef;
    }
}