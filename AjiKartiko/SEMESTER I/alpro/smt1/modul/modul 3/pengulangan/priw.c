#include <stdio.h>
#include <stdlib.h>

/*baca N, Print i = 1 s/d N dengan WHILE*/

int main(){
	
	//KAMUS
	int N;
	int i;
	
	//ALGORITMA
	printf("Nilai N > 0 = "); /*inisialisasi*/
	scanf("%d", &N);
	i = 1; /*First Elmt*/
	printf("print i dengan WHILE: \n");
	while(i <= N) /*kondisi pengulangan*/
	{
		printf("%d \n", i); /*proses*/
		i++; /*Next Elmt*/
	}; /* (i > N) */
	
	return 0;
	
}
