/*	program	: jumcacah.c 
	author	: Ammar Bagas Fathurrahman Wamtoro
	nim		: 12350081008
	date	:24/10//2023
	desc 	: program mmembaca sekumpulan interger yang diinputkan pengguna
*/


#include <stdio.h>
#include <conio.h>

int main() {
	//kamus
	int N;
	int i,s;
	
	//kamus
	printf("masukan N :"); scanf("%d", &N);
	s = N;
	printf("s = 0 + ");
	for (i = 1; i <= N; i++){
		printf("%d", i);
		if (i < N){
			printf(" + ");
			 s = s + i;
		}
	}
	
	printf("\nNilai s : %d", s);
	
	return 0;
}
