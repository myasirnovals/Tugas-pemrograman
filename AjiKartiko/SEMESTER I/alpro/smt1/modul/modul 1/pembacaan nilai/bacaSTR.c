#include <stdio.h>
#include <stdlib.h>

//deklarasi dan alokasi string, kemudian mengisi nya dengan membaca

int main(int argc, char *argv[]) 
{
	
	//KAMUS
	char *str;
	char *strl;
	
	//ALGORITMA
	printf("\nBaca string, maksimal 20 karakter: ");
	str = (char *) malloc (20 * sizeof (char));
	
	printf("masukkan sebuah string, max 20 kar: ");
	scanf("%s", str);
	
	printf("string yang dibaca: %s\n", str);
	strl = (char *) malloc (20 * sizeof (char));
	strcpy (strl, str);
	
	printf("string yang disalin: $s\n", strl);
	
	return 0;
	
}
