#include <stdio.h>
#include <stdlib.h>

/* program untuk mencari nilai maksimum */

int main() 
{
	//KAMUS
	int a, b;
	
	//ALGORITMA
	system("cls"); //untuk membersihkan screen
	printf("masukkan a:"); scanf("%d", &a);
	printf("masukkan b:"); scanf("%d", &b);
	
	//ANALISA KASUS 2
	if (a >= b)
		if(a > b)
			printf("a > b");
		else
			printf("a = b");
	else
		printf("a < b");
	
	return 0;
	
}
