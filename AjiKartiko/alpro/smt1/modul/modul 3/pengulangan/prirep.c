#include <stdio.h>
#include <stdlib.h>


//Print 1 s/d N dengan REPEAT

int main(){
	
	//KAMUS
	int N;
	int i;
	
	//ALGORITMA
	printf("Nilai N > 0 = "); /*inisialisasi*/
	scanf("%d", &N);
	
	i = 1; /*First Elmt*/
	printf("Print i dengan REPEAT: \n");
	do{
		printf("%d \n", i); /*proses*/
		i++; /*Next Elmt*/
	}
	while(i <= N); /*kondisi pengulangan*/
	
	return 0;
	
}
