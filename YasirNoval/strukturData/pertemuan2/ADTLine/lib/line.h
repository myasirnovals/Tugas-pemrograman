/*
    Program: line.h
    Author: 2350081004/Muhamad Yasir Noval
    Kelas: A
    Deskripsi: Header file dari prototype line
    Tanggal: 20/03/2024
*/

#ifndef LINE_H
#define LINE_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "point.h"

#define FirsPoint(L) (L).PAwal
#define EndPoint(L) (L).PAkhir

typedef struct {
    POINT PAwal;
    POINT PAkhir;
} LINE;

void CreateLine(LINE *L);

void CreateLine2(LINE *L, POINT First, POINT End);

POINT GetPAwal(LINE L);

POINT GetPAkhir(LINE L);

void SetPAwal(LINE *L, POINT NewFirstP);

void setPAkhir(LINE *L, POINT NewEndP);

void BacaLine(LINE *L);

void CetakLine(LINE L);

boolean IsEQLine(LINE L1, LINE L2);

boolean IsNEQLine(LINE L1, LINE L2);

boolean IsLOnSbX(LINE L);

boolean IsLOnSbY(LINE L);

boolean IsTegakLurus(LINE L1, LINE L2);

boolean IsSejajar(LINE L1, LINE L2);

LINE GeserLine(LINE L, int deltaX, int deltaY);

double Gradien(LINE L);

#endif //LINE_H