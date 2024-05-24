/*
    Program: line.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Mengisi instruksi di dalam fungsi dan prosedur yang sudah kita buat
    Tanggal: 15/03/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include "line.h"

void CreateLine(LINE *L) {
    CreatePoint(&(*L).PAwal);
    CreatePoint(&(*L).PAkhir);
}
void CreateLine2(LINE *L, POINT First, POINT End) {
    (*L).PAwal = First;
    (*L).PAkhir = End;
}

POINT GetPAwal(LINE L) {
    return L.PAwal;
}

POINT GetPAkhir(LINE L) {
    return L.PAkhir;
}

void SetPAwal(LINE *L, POINT NewFirstP) {
    (*L).PAwal = NewFirstP;
}

void setPAkhir(LINE *L, POINT NewEndP) {
    (*L).PAkhir = NewEndP;
}

void BacaLine(LINE *L) {
    printf("Point Awal: ");
    BacaPoint(&(*L).PAwal);
    printf("\nPoint Akhir: ");
    BacaPoint(&(*L).PAkhir);
}
void CetakLine(LINE L) {
    printf("Garis dari (%d,%d) ke (%d,%d)\n", L.PAwal.X, L.PAwal.Y, L.PAkhir.X, L.PAkhir.Y);
}

boolean IsEQLine(LINE L1, LINE L2) {
    return EQ(L1.PAwal, L2.PAwal) && EQ(L1.PAkhir, L2.PAkhir);
}

boolean IsNEQLine(LINE L1, LINE L2) {
    return NEQ(L1.PAwal, L2.PAwal) && NEQ(L1.PAkhir, L2.PAkhir);
}

boolean IsLOnSbX(LINE L) {
    return IsOnSbX(L.PAwal) && IsOnSbX(L.PAkhir);
}

boolean IsLOnSbY(LINE L) {
    return IsOnSbY(L.PAwal) && IsOnSbY(L.PAkhir);
}

boolean IsTegakLurus(LINE L1, LINE L2) {
    double M1, M2, result;

    M1 = Gradien(L1);
    M2 = Gradien(L2);

    result = M1 * M2;

    if (result == -1) {
        return true;
    } else {
        return false;
    }
}

boolean IsSejajar(LINE L1, LINE L2) {
    return Gradien(L1) == Gradien(L2);
}

LINE GeserLine(LINE L, int deltaX, int deltaY) {
    LINE newL;

    newL.PAwal.X = L.PAwal.X + deltaX;
    newL.PAwal.Y = L.PAwal.Y + deltaY;
    newL.PAkhir.X = L.PAkhir.X + deltaX;
    newL.PAkhir.Y = L.PAkhir.Y + deltaY;

    return newL;
}

double Gradien(LINE L) {
    int Mx;

    Mx = (L.PAkhir.X - L.PAwal.X);

    // error handling division by zero
    if (Mx != 0) {
        return (double) (L.PAkhir.Y - L.PAwal.Y) / (double) Mx;
    } else {
        return false;
    }
}
