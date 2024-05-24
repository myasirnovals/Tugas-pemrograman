/*	program	: for1.c 
	author	: Ammar Bagas Fathurrahman Wamtoro
	nim		: 12350081008
	date	:24/10//2023
	desc 	: cetak bilangan ganjil sebanyak n
*/

#include <stdio.h>
#include <conio.h>

int main() {
	//kamus
	int i;
	int bil;
	int N;
	
	//kamus
	printf("masukan N :"); scanf("%d", &N);
	if (N > 0){
		bil = 1;
		for (i = 1; i <= N; i++){
			printf ("<%d>", bil);
			bil = bil + 2;
		}
	}
	return 0;
}
