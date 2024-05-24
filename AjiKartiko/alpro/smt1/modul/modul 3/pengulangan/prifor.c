#include <stdio.h>
#include <stdlib.h>

//Baca N, Print 1 s/d N dengan FOR 

int main(){
	
	//KAMUS
	int i;
	int N;
	
	//ALGORITMA
	printf("Baca N, 1 s/d N");
	printf("N= ");
	scanf("%d", &N);
	
	for(i = 1; i<= N; i++)
	{
		printf("%d \n", i);
	};
	
	printf("Akhir program \n");
	
	return 0;
}
