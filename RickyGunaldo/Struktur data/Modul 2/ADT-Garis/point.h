/*
    Program: point.h
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Header file dari prototype point
    Tanggal: 15/03/2024
*/

#ifndef _POINT_H
#define _POINT_H
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#define Abbsis(P) (P).X
#define Ordinat(P) (P).Y
#define PI 3.14159265

typedef struct
{
    int X;
    int Y;
} POINT;

void CreatePoint(POINT *P);
void CreatePoint2(POINT *P, int XBaru, int YBaru);

int GetAbsis(POINT P);
int GetOrdinat(POINT P);

void SetAbsis(POINT *P, int newX);
void SetOrdinat(POINT *P, int newY);

void BacaPoint(POINT *P);
void CetakPoint(POINT P);

boolean EQ(POINT P1, POINT P2);
boolean NEQ(POINT P1, POINT P2);
boolean LT(POINT P1, POINT P2);
boolean MT(POINT P1, POINT P2);
boolean IsOrigin(POINT P);
boolean IsOnSbX(POINT P);
boolean IsOnSbY(POINT P);

int Kuadran(POINT P);
POINT MirrorOf(POINT P, boolean SbX, boolean SbY);
double JarakO(POINT P);
void GeserKeSbX(POINT *P);
void GeserKeSbY(POINT *P);

#endif