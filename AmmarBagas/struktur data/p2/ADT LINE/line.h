/*
	Program: line.h
	Author: 2350081008/Ammar Bagas Fathurrahman Wantoro
	Kelas: A
	Deskripsi: header file dari adt line
	Tanggal: 03/20/2024
*/

#ifndef LINE_H
#define LINE_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "point.h"

#define FirsPoint(L) (L).PAwal
#define EndPoint(L) (L).PAkhir

typedef struct
{
	POINT PAwal;
	POINT PAkhir;
} LINE;

/*konstruktor*/
void CreateLine(LINE *L);

void CreateLine2(LINE *L, POINT First, POINT End);
/*selektor*/
POINT GetPAwal(LINE L);

POINT GetPAkhir(LINE L);
/*set nilai*/
void SetPAwal(LINE *L, POINT NewFirstP);

void setPAkhir(LINE *L, POINT NewEndP);
/*baca dan tulis*/
void BacaLine(LINE *L);

void CetakLine(LINE L);
/*operator relasional*/
boolean IsEQLine(LINE L1, LINE L2);

boolean IsNEQLine(LINE L1, LINE L2);

boolean IsLOnSbX(LINE L);

boolean IsLOnSbY(LINE L);

boolean IsTegakLurus(LINE L1, LINE L2);

boolean IsSejajar(LINE L1, LINE L2);
/*operasi aritmatika*/
LINE GeserLine(LINE L, int deltaX, int deltaY);
/*operasi aritmatika*/
double Gradien(LINE L);

#endif 