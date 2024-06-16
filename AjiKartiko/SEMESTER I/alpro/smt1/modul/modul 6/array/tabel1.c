/*
	Nama: Aji Kartiko Hartanto
	Nim: 2350081062
	Kelas: C
	1-Des-2023
*/

#include <stdio.h>
#include <stdlib.h>

/*File: tabel1.c */
/* latihan array dinamik. Ukuran tabel ditentukan dari pembacaan */ 
int main()
{
	/* Kamus */
	/* definisi tabel integer */
	int *tab;  /* deklarasi array; perhatikan tanpa komentar */
	/* belum tampak bedanya dengan pointer ke integer biasa */ 
	int N;
	/* definisi indeks */ 
	int i;
	
	/* Program */
	printf("Contoh mengisi array dinamik berukuran 0..N : \n" ) ;
	printf(" N = ");
	scanf("%d", &N);
	printf("Alokasi setelah mengetahui ukuran tabel \n"); 
	tab = (int *) malloc ((N + 1) * sizeof (int));
	/* alokasi: ukuran! */
	if (tab != NULL)
	{ 
		/* Mendefinisikan elemen tabel */ 
		for (i = 0; i <= N; i++)
		{
			*(tab + i) = 1;
			printf("i = %d tab[i] = %d \n", i, *(tab + i));
		};
		printf("Akhir program \n");
		/* dealloc */
		free (tab); /* dealokasi */ 
		return 0;
	}
	else
	{
		printf("alokasi gagal ... \n"); 
		return 1;
	}
}
