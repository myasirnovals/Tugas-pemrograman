/* Program	: point.h
   Author	: (2350081028, Ricky Gunaldo)
   Kelas	: A
   Deskripsi: Header dari ADT POINT
   Tanggal	: 16 - 03 - 2024
*/

#ifndef POINT_H
#define POINT_H
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
#define PI 3.14159265

/** Definisi ABSTRACT DATA TYPE POINT **/
typedef struct
{
	int X; //absis
	int Y; //ordinat
}POINT;

/* Prototype POINT */

/* Kontruktor membentuk POINT */
void CreatePoint(POINT *P);
void CreatePoint2(POINT *P, int XBaru, int YBaru);

/* Selektor POINT */
int GetAbsis(POINT P);
int GetOrdinat(POINT P);

/* Set nilai komponen */
void SetAbsis(POINT *P, int newX);
void SetOrdinat(POINT *P, int newY);

/* Destruktor / Dealokator: tidak perlu */

/** {Kelompok Interaksi dengan I/O device, BACA/TULIS} **/
void BacaPoint(POINT *P);
void CetakPoint(POINT P);

/** Kelompok operasi relasional terhadap POINT **/
boolean EQ(POINT P1, POINT P2);
boolean NEQ(POINT P1, POINT P2);
boolean LT(POINT P1, POINT P2);
boolean MT(POINT P1, POINT P2);

/** Kelompok menentukan dimana P berada **/
boolean IsOrigin(POINT P);
boolean IsOnSbX(POINT P);
boolean IsOnSbY(POINT P);
int Kuadran(POINT P);

/** Kelompok operasi lain terhadap type **/
POINT MirrorOf(POINT P, boolean SbX, boolean SbY);
float JarakO(POINT P);
void GeserKeSbX(POINT *P);
void GeserKeSbY(POINT *P);

#endif
