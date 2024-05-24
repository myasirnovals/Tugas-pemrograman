/* Program	: mpoint.c
   Author	: (2350081028, Ricky Gunaldo)
   Kelas	: A
   Deskripsi: Main driver dari ADT POINT
   Tanggal	: 16 - 03 - 2024
*/

#include "point.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	/* Deklarasi */
	POINT P1, P2, newP;
	
	/* Algoritma */
	/* Membuat point */
	CreatePoint(&P1);
	CreatePoint(&newP);
	CreatePoint2(&P2, 7, 9);
	
	/* Kelompok BACA/TULIS */
	BacaPoint(&P1);
	
	CetakPoint(P1);
	printf("\n");
	CetakPoint(P2);
	
	/* Mengambil nilai absis dan ordinat P1 dan P2 */
	printf("\n");
	printf("\nP1 Absis: %d", GetAbsis(P1));
	printf("\nP1 Ordinat: %d", GetOrdinat(P1));
	printf("\nP2 Absis: %d", GetAbsis(P2));
	printf("\nP2 Ordinat: %d", GetOrdinat(P2));
	printf("\n");
	
	/* Mengubah nilai absis dan ordinat P1 dan P2 */
	SetAbsis(&P1, -7);
	SetOrdinat(&P1, 9);
	SetAbsis(&P2, 5);
	SetOrdinat(&P2, -5);
	
	printf("\n");
	CetakPoint(P1);
	printf("\n");
	CetakPoint(P2);
	printf("\n");
	
	/* Kelompok operasi relasional */
	if(EQ(P1, P2) == true)
	{
		printf("\ntrue");
	}
	else
	{
		printf("\nfalse");
	}
	
	if(NEQ(P1, P2) == true)
	{
		printf("\ntrue");
	}
	else
	{
		printf("\nfalse");
	}
	
	if(LT(P1, P2) == true)
	{
		printf("\ntrue");
	}
	else
	{
		printf("\nfalse");
	}
	
	if(MT(P1, P2) == true)
	{
		printf("\ntrue");
	}
	else
	{
		printf("\nfalse");
	}
	
	/* Kelompok menentukan dimana P berada */
	printf("\n");
	if(IsOrigin(P1) == true)
	{
		printf("\nP1 tidak berada pada kuadran manapun\n");
	}
	else
	{
		printf("\nP1 terletak di kuadran %d\n", Kuadran(P1));
	}
	
	if(IsOnSbX(P1) == true)
	{
		printf("\nP1 berada pada sumbu X\n");
	}
	else if(IsOnSbY(P1) == true)
	{
		printf("\nP1 berada pada sumbu Y\n");
	}
	else
	{
		printf("\nP1 tidak berada pada sumbu X atau Y\n");
	}
	
	/* Operasi lain terhadap type */
	printf("\njarak P1 dengan origin: %.2f\n", JarakO(P1));
	
	GeserKeSbX(&P1);
	CetakPoint(P1);
	printf("\n");
	
	GeserKeSbX(&P2);
	CetakPoint(P2);
	printf("\n");
	
	newP = MirrorOf(P1, IsOnSbX(P1), IsOnSbY(P1));
	CetakPoint(newP);
	printf("\n");
	
	return 0;
}
