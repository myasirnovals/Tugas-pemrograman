/*
	Nama: Aji Kartiko Hartanto
	Nim: 2350081062
	Kelas: C
	1-Des-2023
*/

#include <stdio.h>
#include <stdlib.h>

/* File : arrstru.c */
/* Mencoba array of a structure : array dengan elemen type terstruktur */
int main()
{
	/* Kamus */ 
	int i;
	typedef struct
	{
		int x; int y;
	} 
	Point;
	Point P;
	Point arrp[10]; /* definisi, alokasi tabel statik */ 
	/* Definisikan elemen tabel */
	for ( i = 0; i <= 9; i ++)
	{
		arrp[i].x = i; 
		arrp[i].y = i + 1;
	}
	/* tulis isi tabel */ 
	for (i = 0; i <= 9; i++)
	{
		printf("\n %d/%d", arrp[i].x, arrp[i].y);
	}
	
	return 0;
}
