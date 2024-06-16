#include <stdio.h>
#include <stdlib.h>

/* file : pointf2.c */
/* pointer to function */
/* function sebagai parameter */
/* melakukan offset terhadap tabel tergantung fungsi f */
/* KAMUS GLOBAL */
/* prototype */

typedef struct
{
	int T[10];	/* isi tabel */ 
	int N; 		/* ukuran efektif */
}
TabInt;

/* fungsi yang diberikan sebagai parameter aktual */
int succ (int i); /* suksesor */
int pred (int i); /* predesesor */

/* prosedur dengsan parameter sebuah fungsi */
void geser (TabInt * TT, int (*f) (int N));

/* PROGRAM UTAMA */
int main(){
	/* KAMUS LOKAL */
	TabInt MyTab;
	int i;
	
	MyTab.N = 10;
	for (i = 0; i < MyTab.N; i++)
	{
		MyTab.T[i] = i;
	}
	printf("Nilai asal tabel dalam min \n");
	for (i = 0; i < MyTab.N; i++)
	{
		printf(" %d", MyTab.T[i]);
	}
	printf("\n");
	
	/* pakai geser dengan parameter succ */
	printf("Geser dengan succ \n");
	geser (&MyTab, succ);
	
	printf("dalam min \n");
	for (i = 0; i < MyTab.N; i++)
	{
		printf(" %d", MyTab.T[i]);
	}
	printf("\n");
	
	printf("Nilai tabel dalam main setelah aplikasi succ \n");
	for (i = 0; i < MyTab.N; i++)
	{
		printf(" %d", MyTab.T[i]);
	}
	printf("\n");
	
	/* pakai geser parameter pred */
	printf("Geser dengan pred \n");
	geser (&MyTab, pred);
	printf ("dalam main setelah aplikasi pred \n");
	for (i = 0; i < MyTab.N; i++)
	{
	printf (" %d ", MyTab.T[i]);
	}	
	printf ("\n");
	return 0;
	}
	/* BODY FUNGSI */
	int succ (int i)
	{
	return (i + 1);
	}
	int pred (int i)
	{
	return (i - 1);
	}
	void geser (TabInt * TT, int (*f) (int))
	{	
	int i;
	printf ("dalam geser \n");
	for (i = 0; i < (*TT).N; i++)
	{
	(*TT).T[i] = f ((*TT).T[i]);
	printf (" %d ", (*TT).T[i]);
	}
	printf ("\n");
	}
