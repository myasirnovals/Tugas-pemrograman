/*
	Nama: Aji Kartiko Hartanto
	Nim: 2350081062
	Kelas: C
	1-Des-2023
*/

#include <stdio.h>
#include <stdlib.h>

/* File: tabel.c */
/* latihan array statis: mengisi dg assignment, menulis */
int main()
{
	/* Kamus */ 
	int i;
	int tab[10]; /* Cara mengacu elemen kp -i: tab[i] */
	int N;
	
	/* Program */
	N = 5;
	printf("Isi dan print tabel untuk indeks 1..5 \n");
	
	/* isi dengan assignment */ 
	for (i = 1; i <= N; i++)
	{
		tab[i] = i;
	};
	
	/* traversal: print */ for (i = 1; i <= N; i++)
	{
		printf ("i=%d tab[i] = %d \n", i, tab[i]);
	};
	return 0;
}
