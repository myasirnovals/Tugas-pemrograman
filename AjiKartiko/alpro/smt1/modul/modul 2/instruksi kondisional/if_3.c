#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	
	//KAMUS
	int a;
	
	//ALGORITMA
	printf("contoh IF tiga kasus \n");
	printf("ketikkan suatu nilai integer:");
	scanf("%d", &a);
	if (a > 0)
	printf("nilai a positif %d \n", a);
	else if (a == 0)
	printf("nilai nol %d \n", a);
	else /* a > 0*/
	printf("nilai a negatif &d \n", a);
	
	return 0;
	
}
