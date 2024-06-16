/*
	Nama: Aji Kartiko Hartanto
	Nim: 2350081062
	Kelas: C
	1-Des-2023
*/

#include <stdio.h>
#include <stdlib.h>

/* File : arrstr.c*/
/*Array of string: pendefinisian dan pengaksesan */
/* perhatikanlah permasalahannya */
int main()
{
	/* KAMUS */
	/* definisi array yang elemennya string, statik, dan sekaligus mengisi */
	static char *s[3] = {"the", "time", "is"};
	/* definisi array yang elemennya string, dinamik */ 
	char * (*TabStr);
	int i;
	
	/* PROGRAM */
	/* print isi s */
	for (i = 0; i < 3; i++)
	{
		printf("%s\n", s[i]);
	}
	/* alokasi TabStr sebanyak 3 */
	TabStr = (char **) malloc (3 * sizeof (char *));
	for (i = 0; i < 3; i++)
	{
		*(TabStr + i) = (char *) malloc (5 * sizeof (char)); 
		printf("\nInput Str[d], maksimum 5 karakter : ", i);
		scanf("%5s", *(TabStr + 1)); 
		printf("\n Nilai Str[%d] : %5s\n", i, *(TabStr + i));
	}
	return 0;
}
