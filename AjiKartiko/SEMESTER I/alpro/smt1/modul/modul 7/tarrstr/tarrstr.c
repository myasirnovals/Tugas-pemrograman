#include <stdio.h>
#include <stdlib.h>

/* file : tarrstr.c */
/* array of string : pendefinisian dan pengaksesan */

#define STRING char* 
int main(){
	/* KAMUS */
	
	/* definisi array yang elemennya string, statik, dan sekaligus mengisi */
	static STRING s[3] = {"the", "time", "is"};
	
	/* definisi array yang elemennya string, dinamik */
	STRING (*TabStr); /* deklarasi array of string */ 
	int i;
	
	/* PROGRAM */
	/* print isi s */
	for (i = 0; i < 3; i++)
	{
		printf("%s\n", s[i]);
	}
	/* alokasi TabStr sebanyak 3 */
	TabStr = (STRING *) malloc (3 * sizeof (STRING));
	for (i = 0; i < 3; i++)
	{
	/* alokasi string yang merupakan elemen tabel */
	*(TabStr + i) = (STRING) malloc (5 * sizeof (char));
	printf("\nInput Str[%d], maksimum 5 karakter : ",i); scanf("%5s", *(TabStr + i)); /* mengisi nilai string */
	printf("\n Nilai Str[%d] : %5s\n", i, *(TabStr + i));
	}
	
	return 0;
}
