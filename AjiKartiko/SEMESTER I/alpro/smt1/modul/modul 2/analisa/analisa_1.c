#include <stdio.h>
#include <stdlib.h>

/* program mencari nilai maksimum */

int main(int argc, char *argv[]) 
{
	
	//KAMUS
	int a, b;
	
	//ALGORITMA
	system("cls"); 
	printf("masukkan a:"); scanf("%d", &a);
	printf("masukkan b:"); scanf("%d", &b);
	
	//ANALISA KASUS 1
	if (a > b)
		printf("a > b");
	else if (a == b)
		printf("a = b");
	else
		printf("a < b");
		
	return 0;
	
}
