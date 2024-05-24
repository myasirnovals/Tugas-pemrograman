/**
 * Program: stack.c
 * Author: (2350081004, Muhamad Yasir Noval)
 * Kelas: A
 * Deskripsi: Header file dari stack
 * Tanggal: 10 Mei 2024
 */

#include "../lib/stack.h"

// konstruktor
/*
 * prosedur untuk mengatur index array jadi 0
 */
void CreateStack(Stack *S) {
    /*
     * nil = 0
     * S.neff <-- nil
     *
     */
    Top(*S) = Nil;
}

// {Kelompok operasi pada stack}
// Predikat untuk test keadaan Koleksi
boolean IsStackEmpty(Stack S) {
    /*
     * array terdiri dari 2
     * 1. neff = index
     * 2. elemen = isi dari array
     *
     */
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
void Push(Stack *S, infoType P) {
    if (!IsStackFull(*S)) {
        Top(*S)++;
        InfoTop(*S).X = P.X;
        InfoTop(*S).Y = P.Y;
    } else {
        printf("Stack penuh");
    }
}

/*
 * stack = array = wadah
 *
 *
 */

// procedure Push(in/out S: Stack, in P: infoType)
// {I.S: S stack berisi 5 data}
// {proses: memasukan data point kedalam S}
// {F.S: S bertambah 1 data}
// {kamus}
//  -
// {algoritma}
// if (IsStackFull(S)) then
//      print("stack penuh")
// else
//      Top(S)++
//      InfoTop(S).X <-- P.X
//      InfoTop(S).Y <-- P.Y
/*
 *
 * procedure = bikin kumpulan perintah, wadah yang tidak mengembalikan nilai
 * function = wadah yang mengembalikan nilai jadi
 */

// Menghapus sebuah elemen stack
/*
 * parameter S berupa in/out
 * parameter P berupa in/out
 *
 */
void Pop(Stack *S, infoType *P) {
    /*Cek apakah kosong atau tidak*/
    if (!IsStackEmpty(*S)) {
        *P = InfoTop(*S);
        /*
         * Top(S) = 5
         * Top(S) = 4
         * Top(S)--
         *
         * Top(S) <-- Top(S) - 1
         * S.Top <-- S.Top - 1
         */
        Top(*S)--;
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
        printf("[%d, %d] ", ElemenTop(S).X, ElemenTop(S).Y);
    }
}

/*
 * Buatkan tipe data bentukan untuk tabel unsur periodik yang
 * terdiri nomor atom dan nama atomnya
 *
 */

/*
 *
 * procedure PrintStackInfo(in S: Stack)
 * {kamus}
 *      i: integer
 *
 * {Algoritma}
 *      for(i <-- 1 to Top(S)) do
 *          output("[%d, %d]", ElemenTop(S).X, ElemenTop(S).Y)
 *      endfor
 */


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