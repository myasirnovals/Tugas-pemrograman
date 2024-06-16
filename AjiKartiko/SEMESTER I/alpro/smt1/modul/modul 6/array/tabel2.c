/*
	Nama: Aji Kartiko Hartanto
	Nim: 2350081062
	Kelas: C
	1-Des-2023
*/

#include <stdio.h>
#include <stdlib.h>

/* File : tabel2.c */
/* latihan array statis multidimensi : mengisi dg assignment, menulis */
int main()
{
	/* Kamus */
	/* definisi matriks dan isi dengan agregat */
	int tab [3] [4] =
	{ {1, 2, 3, 4},
	{2, 3, 4, 5},
	{3, 4, 5, 6},
	};
	int i; /* indeks baris */
	int j; /* indeks kolom */
	
	/* Program */
	printf(" Print matriks 3 x 4 \n");
	/* traversal: print */ 
	for (i = 0; i < 3; i++)
	{ 
		for (j = 0; j < 4; j++)
		{
			printf("i, j = %d, %d tab[i, j] = %d \n", i, j, tab[i] [j]);
		}
	};
	return 0;
}
