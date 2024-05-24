#include <stdio.h>
#include <stdlib.h>

/*Baca N, Print i = 1 s/d N dengan while (ringkas)*/

int main(){
	
	//KAMUS
	int N;
	int i = 1;
	
	//ALGORITMA
	printf("nilai N > 0 = ");
	scanf("%d", &N);
	
	printf("print i dengan WHILE (ringkas): \n");
	while (i <= N)
	{
		printf("%d \n", i++);
	} /* (i > N) */
	
	return 0;
}
