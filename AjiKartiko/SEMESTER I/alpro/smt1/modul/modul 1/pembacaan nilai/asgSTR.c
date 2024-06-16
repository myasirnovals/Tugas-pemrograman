#include <stdio.h>
#include <stdlib.h>

//deklarasi dan alokasi string, kemudian mengisi nya dengan membaca

int main(int argc, char *argv[]) 
{
	
	//KAMUS
	char *str; 
	char *strl;
	
	//ALGORITMA
	printf ("\nBaca string, Maks 20 karakter: ");
	str = (char *) malloc (20 * sizeof (char));
	strcpy (str,"ini string..");
	
	printf ("String yang diisikan : %s \n", str);
	strl = (char *) malloc (20 * sizeof (char));
	
	strcpy (strl, str);
	printf ("String yang disalin : %s \n ", strl); 
	
	return 0;
	
}
