#include <stdio.h>
#include <stdlib.h>

/* contoh pemakaian IF dua kasus komplementer */
/* membaca sebuah nilai */


int main() 
{
	
	//KAMUS
	int a;
	 
	//ALGORITMA
	printf("contoh IF dua kasus \n");
	printf("ketikkan suatu nilai integer:");
	scanf("%d", &a);
	
	if(a >= 0)
	printf("nilai a positif %d \n", a);
	else /* a < 0*/
	printf("nilai a integer %d \n", a);
	
	return 0; 
	
}
