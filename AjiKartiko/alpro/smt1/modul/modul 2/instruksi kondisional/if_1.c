#include <stdio.h>
#include <stdlib.h>

/* contoh pemakaian IF satu kasus */
/* membaca nilai integer, menuliskan nilai nya jika positif */

int main()
{
	
	//KAMUS
	int a;
	
	//ALGORITMA
	printf("contoh IF satu kasus \n");
	printf("ketikkan suatu nilai integer:");
	scanf("%d", &a);
	
	if (a >= 0)
	printf("nilai a positif %d \n", a);
	
	return 0;
	
}
