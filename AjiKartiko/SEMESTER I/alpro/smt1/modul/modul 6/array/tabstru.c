/*
	Nama: Aji Kartiko Hartanto
	Nim: 2350081062
	Kelas: C
	1-Des-2023
*/

#include <stdio.h>
#include <stdlib.h>

/* latihan array dengan def type: mengisi dg assignment, menulis */ 
int main()
{
	/* Kamus */
	/* definisi tabel integer */ 
	typedef struct
	{
		int *T; /* array integernya */ 
		int N; /* ukuran efektif */
	}
	tabint; tabint Mytab; int i;
	
	/* Program */
	printf("Tentukan ukuran tabel = "); scanf("%d%", &Mytab.N);
	Mytab.T= (int *) malloc (Mytab.N * sizeof (int));
	/* isi dengan assignment */
	for (i = 0; i < Mytab.N; i++)
	{
		*(Mytab.T+1) = i; /* dapat juga ditulis MyTab.T[i] */ 
		printf("i = %d Mytab.T = %d \n", i, *(Mytab.T + i ));
	};
	
	return 0;
}
