/*
	program		: point.h
	author		: 2350081008/Ammar Bagas Fathurrahman Wantoro
	kelas		: A
	deskripsi	: header file dari prototype point
	tanggal		: 3/16/2024

*/
#ifndef _POINT_H
#define _POINT_H
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#define absis(p) (p).X
#define ordinat(p) (p).Y
#define PI 3.14159265

/*definisi type data POINT*/
typedef struct
{
	int X;
	int Y;
} POINT;

/*konstruktor POINT*/
void CreatePoint(POINT *P);
void CreatePoint2(POINT *P, int XBaru, int YBaru);

/*selektor POINT*/
int GetAbsis(POINT P);
int GetOrdinat(POINT P);

/*set nilai POINT*/
void SetAbsis(POINT *P, int XBaru);
void SetOrdinat(POINT *P, int YBaru);

/*kelompok interaksi dengan I/O device, Baca/Tulis*/
void BacaPoint(POINT *P);
void CetakPoint(POINT *P);

/*kelompok operasi relasional terhadap POINT*/
boolean EQ(POINT P1, POINT P2);
boolean NEQ(POINT P1, POINT P2);
boolean LT(POINT P1, POINT P2);
boolean MT(POINT P1, POINT P2);

/*kelompok menentukan dimana P berada*/
boolean IsOrigin(POINT P);
boolean IsOnSbX(POINT P);
boolean IsOnSbY(POINT P);
int Kuadran(POINT P);

/*kelompok operasi lain terhadap type*/
POINT MirrorOf(POINT P, boolean SbX, boolean SbY);
float jarakO(POINT P);
void GeserKeSbX(POINT *P);
void GeserKeSbY(POINT *P);

#endif
