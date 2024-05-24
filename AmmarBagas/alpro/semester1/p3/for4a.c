/*	program	: for4a.c 
	author	: Ammar Bagas Fathurrahman Wamtoro
	nim		: 12350081008
	date	:24/10//2023
	desc 	: memunculkan bilangan tergantung nilai n versi 2
*/

#include <stdio.h>
#include <conio.h>

int main() {
	//kamus
	int i;
	int N;
	int j;
	
	//algoritma
	//input
	printf("masukan N :"); scanf("%d", &N);
	
	
	//kondisional dan pengulangan
	if (N < 0){
		printf ("masukan angka positif");
	}else{
		for (i = 1; i <= N; i++){
			
			for (j = i; j <= N; j++){
				printf("%d", j);
			}
			
			for (j = 1; j < i; j++){
				printf("%d", j + N);
			}
			printf("\n");
		}
	}
	
	return 0;
}
