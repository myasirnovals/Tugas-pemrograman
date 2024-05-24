/* Program	: point.c
   Author	: (2350081028, Ricky Gunaldo)
   Kelas	: A
   Deskripsi: Body file dari prototype POINT
   Tanggal	: 16 - 03 - 2024
*/

#include "point.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

/* Prototype POINT */

/* Kontruktor membentuk POINT */
void CreatePoint(POINT *P)
{
	(*P).X = 0;
	(*P).Y = 0;
}

void CreatePoint2(POINT *P, int XBaru, int YBaru)
{
	(*P).X = XBaru;
	(*P).Y = YBaru;
}

/* Selektor POINT */
int GetAbsis(POINT P)
{
	return P.X;
}

int GetOrdinat(POINT P)
{
	return P.Y;
}

/* Set nilai komponen */
void SetAbsis(POINT *P, int newX)
{
	(*P).X = newX;
}

void SetOrdinat(POINT *P, int newY)
{
	(*P).Y = newY;
}

/* Destruktor / Dealokator: tidak perlu */

/** {Kelompok Interaksi dengan I/O device, BACA/TULIS} **/
void BacaPoint(POINT *P)
{
	/* Deklarasi */
	int x, y;
	
	/* Algoritma */
	printf("Masukkan X: "); scanf("%d", &x);
	printf("Masukkan Y: "); scanf("%d", &y);
	CreatePoint2(&(*P), x, y);
}

void CetakPoint(POINT P)
{
	printf("Titik: %d,%d", GetAbsis(P), GetOrdinat(P));
}

/** Kelompok operasi relasional terhadap POINT **/
boolean EQ(POINT P1, POINT P2)
{
	if((GetAbsis(P1) == GetOrdinat(P2)) && (GetAbsis(P1) == GetOrdinat(P2)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

boolean NEQ(POINT P1, POINT P2)
{
	if((GetAbsis(P1) != GetOrdinat(P2)) || (GetAbsis(P1) != GetOrdinat(P2)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

boolean LT(POINT P1, POINT P2)
{
	if((GetAbsis(P1) < GetOrdinat(P2)) || (GetAbsis(P1) < GetOrdinat(P2)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

boolean MT(POINT P1, POINT P2)
{
	if((GetAbsis(P1) > GetOrdinat(P2)) || (GetAbsis(P1) > GetOrdinat(P2)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/** Kelompok menentukan dimana P berada **/
boolean IsOrigin(POINT P)
{
	if((GetAbsis(P) == 0) && (GetOrdinat(P) == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

boolean IsOnSbX(POINT P)
{
	if((GetOrdinat(P) == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

boolean IsOnSbY(POINT P)
{
	if((GetAbsis(P) == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Kuadran(POINT P)
{
	if((GetAbsis(P) > 0) && (GetOrdinat(P) > 0))
	{
		return 1;
	}
	else if((GetAbsis(P) < 0) && (GetOrdinat(P) > 0))
	{
		return 2;
	}
	else if((GetAbsis(P) < 0) && (GetOrdinat(P) < 0))
	{
		return 3;
	}
	else if((GetAbsis(P) > 0) && (GetOrdinat(P) < 0))
	{
		return 4;
	}
	else
	{
		return 0;
	}
}

/** Kelompok operasi lain terhadap type **/
POINT MirrorOf(POINT P, boolean SbX, boolean SbY)
{
	/* Deklarasi lokal */
	POINT newP;
	
	/* Algoritma */
	CreatePoint2(&newP, GetAbsis(P), GetOrdinat(P));
	
	if(SbX == true)
	{
		newP.X = GetAbsis(P) * -1;
	}
	else if(SbY == true)
	{
		newP.Y = GetOrdinat(P) * -1;
	}
	else
	{
		return newP;
	}
}

float JarakO(POINT P)
{
	/* Deklarasi lokal */
	double jarak;
	
	/* Algoritma */
	jarak = sqrt(pow((GetAbsis(P) - 0), 2) + pow((GetOrdinat(P) - 0), 2));
	
	return jarak;
}

void GeserKeSbX(POINT *P)
{
	if(GetOrdinat(*P) != 0)
	{
		SetOrdinat(&(*P), 0);
	}
}

void GeserKeSbY(POINT *P)
{
	if(GetAbsis(*P) != 0)
	{
		SetAbsis(&(*P), 0);
	}
}
