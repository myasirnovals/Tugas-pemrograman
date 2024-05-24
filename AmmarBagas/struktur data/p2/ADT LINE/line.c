/*
    Program: line.c
    Author: 2350081008/Ammar Bagas Fathurrahman Wantoro
    Kelas: A
    Deskripsi: program line.c merupakan program yang menuliskan semua operasi fungsi dari ADT
    Tanggal: 03/20/2024
*/
#include <stdio.h>
#include "line.h"

void CreateLine(LINE *L)
{
    CreatePoint(&(*L).PAwal);
    CreatePoint(&(*L).PAkhir);
}

void CreateLine2(LINE *L, POINT First, POINT End)
{
    (*L).PAwal = First;
    (*L).PAkhir = End;
}

POINT GetPAwal(LINE L)
{
    return L.PAwal;
}

POINT GetPAkhir(LINE L)
{
    return L.PAkhir;
}

void SetPAwal(LINE *L, POINT NewFirstP)
{
    (*L).PAwal = NewFirstP;
}

void setPAkhir(LINE *L, POINT NewEndP)
{
    (*L).PAkhir = NewEndP;
}

void BacaLine(LINE *L)
{
    printf("Point Awal:\n ");
    BacaPoint(&(*L).PAwal);
    printf("\nPoint Akhir:\n ");
    BacaPoint(&(*L).PAkhir);
}

void CetakLine(LINE L)
{
    printf("Garis dari (%d,%d) ke (%d,%d)\n", L.PAwal.X, L.PAwal.Y, L.PAkhir.X, L.PAkhir.Y);
}

boolean IsEQLine(LINE L1, LINE L2)
{
    if (EQ(GetPAwal(L1), GetPAwal(L2)) && EQ(GetPAkhir(L1), GetPAkhir(L2)))
    {
        return true;
    }else
    {
        return false;
    }
    
}

boolean IsNEQLine(LINE L1, LINE L2)
{
    if (NEQ(GetPAwal(L1), GetPAwal(L2)) && NEQ(GetPAkhir(L1), GetPAkhir(L2)))
    {
        return true;
        /* code */
    }else
    {
        return false;
    }
    
    
    
}

boolean IsLOnSbX(LINE L)
{
    if (IsOnSbX(GetPAwal(L)) && IsOnSbX(GetPAkhir(L)))
    {
        return true;
    }else
    {
        return false;
    }
}

boolean IsLOnSbY(LINE L)
{
    if (IsOnSbY(GetPAwal(L)) && IsOnSbY(GetPAkhir(L)))
    {
        return true;
        
    }else
    {
        return false;
    }
}

boolean IsTegakLurus(LINE L1, LINE L2)
{
    int M1, M2, result;

    M1 = (GetPAkhir(L2).Y - GetPAwal(L1).Y) / (GetPAkhir(L2).X - GetPAwal(L1).X);
    M2 = (GetPAkhir(L2).Y - GetPAwal(L1).Y) / (GetPAkhir(L2).X - GetPAwal(L1).X);

    result = M1 * M2;

    if (result == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

boolean IsSejajar(LINE L1, LINE L2)
{
    if (Gradien(L1) == Gradien(L2))
    {
        return true;
    }else
    {
        return false;
    }
}

LINE GeserLine(LINE L, int deltaX, int deltaY)
{
    LINE newL;

    newL.PAwal.X = L.PAwal.X + deltaX;
    newL.PAwal.Y = L.PAwal.Y + deltaY;
    newL.PAkhir.X = L.PAkhir.X + deltaX;
    newL.PAkhir.Y = L.PAkhir.Y + deltaY;

    return newL;
}

double Gradien(LINE L)
{
    return (double)(L.PAkhir.Y - L.PAwal.Y) / (double)(L.PAkhir.X - L.PAwal.X);
}