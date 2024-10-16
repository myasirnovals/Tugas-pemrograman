/*
	Nama: Aji Kartiko Hartanto
	Nim: 2350081062
	Kelas: C
	1-Des-2023
*/

#include <stdio.h>
#include <stdlib.h>

/* File : tabel3.c */
/* latihan array statis multidimensi : mengisi dg assignment, menulis */
int main()
{
	/* Kamus +/
	/* definisi tabel 3 dimensi */
	int tab[3] [4] [2];
	/* definisi indeks */
	int i; /*indeks baris */
	int j; /* indeks kolom */
	int k; /* indeks ??? */
	
	/* Program */
	printf("Isi dan print tabel 3 dimensi, kemudian print \n"); 
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 2; k++)
			{
				if ((i == j) && (j == k) && ( i ==k) )
				{
					tab[i] [j] [k] = 1;
				}
				else
				{
					tab[i] [j] [k] = 0;
				}
			printf("i, j, k = %d, %d, %d tab [i, j, k] = %d \n", i, j, k, tab[i] [j] [k]);
			}
		}
	};
	return 0;
}
