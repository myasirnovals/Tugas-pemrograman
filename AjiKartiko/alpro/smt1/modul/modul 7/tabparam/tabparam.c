#include <stdio.h>
#include <stdlib.h>

/* File : tabparam.c */
/* tabel sebagai parameter prosedur. perhatikan cara passing parameter aktual */

/* prototype */
int maxab(int a, int b); void tukar(int *a, int *b);
void Offsettab(int *T, int Awal, int Akhir);

/* melakukan incerement terhadap setiap elemen tabel */
/* dengan indeks awal sampai akhir */
void printtab(int *T, int Awal, int Akhir);

/* print isi tabel indeks awal s/d akhir */
int main(){
	/* KAMUS */
	int tab[10]; /* definisi tabel integer */
	int N = 10;
	int i; /* indeks */
	
	/* ALGORITMA */
	/* mengisi tabel */
	for (i = 0; i < N; i++)
	{
		tab[i] = i;
		printf("%d\n", tab[i]);
	}
	printtab (tab, 0, N - 1);
	/* passing parameter aktual berupa integer */
	tukar (&tab[1], &tab[5]);
	
	printf("tab[1]= %d; tab[5]= %d\n", tab[1], tab[5]);
	printf("maks dari 1 elemen dibdk 10 = %d\n", maxab (tab[1], tab[2]));
	
	/* passing parameter input output (aktual) berupa tabel: tanpa & */ 
	Offsettab (tab, 0, N - 1);
	printtab (tab, 0, N - 1);
	return 0;
}
/* BODY/REALISASI prosedur/fungsi */
int maxab(int a, int b)
{
	/* mencari maksimum dua bilangan bulat */
	return ((a >= b) ? a : b);
}
void tukar (int *a, int *b)
{
	/* menukar dua bilangan bulat */
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void Offsettab (int *T, int Awal, int Akhir)
{
	/*melakukan increment terhadap setiap elemen tabel */
	/* dengan indeks Awal s/d Akhir */
	/* kamus lokal */
	int i;
	for (i = Awal; i <= Akhir; i++)
	{
		T[i] = T[i] + 1; /* karena T[i] identik dengan *T+i */
		printf("Dalam prosedur offset T[%d] = %d\n", i, T[i]);
	}
}
void printtab (int *T, int Awal, int Akhir)
{
	/* print isi tabel indeks awal s/d akhir */
	
	/* kamus */
	int i;
	
	/* algoritma */
	for (i = Awal; i <= Akhir; i++)
	{ printf("tab[%d] = %d\n", i, T[i]);
	}
}
