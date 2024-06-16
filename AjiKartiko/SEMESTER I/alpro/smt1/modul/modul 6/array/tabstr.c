/*
	Nama: Aji Kartiko Hartanto
	Nim: 2350081062
	Kelas: C
	1-Des-2023
*/

#include <stdio.h>
#include <stdlib.h>

/* File : tabstr.c */
/* latihan array dengan def type: mengisi dg assignment, menulis */ 
int main()
{
	/* Kamus */
	/* definisi tabel integer */ 
	typedef struct
	{
		int T[10]; /* array integernya */
		int N; /* ukuran efektif */
	}
	tabint; 
	int i;
	tabint Mytab;
	
	/* Program */
	printf("Tentukan ukuran tabel, maks 10 = "); scanf("%d%", &Mytab.N);
	
	/* isi dengan assignment */ 
	for (i = 0; i < Mytab.N; i++)
	{
		Mytab.T[i] = i;
		printf("i = %d Mytab.T = %d \n", i, Mytab.T[i]);
	};
	
	return 0;
}
