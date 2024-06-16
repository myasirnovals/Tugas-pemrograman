/*
	Nama: Aji Kartiko Hartanto
	Nim: 2350081062
	Kelas: C
	1-Des-2023
*/

#include <stdio.h>
#include <stdlib.h>

/* latihan array dinamis dan statis: mengisi dg baca, menulis */ 
/* Latihan passing parameter tabel */ 
typedef struct
{
	int tab[10]; 
	int N;
}
TabInt;

/* prototype */
void incTab (TabInt *T); /* increment setiap element tabel */ 
void printTab (TabInt T); /* print tabel */
int main() 
{
	/* Kamus */ 
	int i;
	TabInt T;
	
	/* Program */
	T.N = 3;
	printf("Isi dan print tabel untuk indeks 1..5 \n");
	/* isi dari pembacaan */
	for (i = 0; i < T.N; i ++)
	{
	printf("Input Tabel ke- [%d] = ", i); scanf ("%d", &(T.tab[i]));
	};
	/* print: perhatikan passing parameter */
	printTab (T); 
	/* Increment: perhatikan passing parameter */
	incTab (&T);
	printTab (T);
	 
	return 0;
}
/* Body prototype */
void incTab (TabInt * T) /* increment setiap element tabel */
{
	/* Kamus lokal */ 
	int i;
	/* Algoritma */
	/* traversal : print */
	for (i = 0; i < (*T).N; i++)
	{
		(*T).tab[i] = (*T).tab[i] + 1 ;
	}
}
void printTab (TabInt T) 
/* print tabel */
{
	/* Kamus lokal */ 
	int i;
	/* Algoritma*/
	/* traversal : print */ 
	for (i = 0; i < T.N; i ++)
	{
		printf("T[%d] = %d \n", i, T.tab[i]);
	}
}
