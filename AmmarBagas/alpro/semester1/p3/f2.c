/*	program	: for2.c 
	author	: Ammar Bagas Fathurrahman Wamtoro
	nim		: 12350081008
	date	:24/10//2023
	desc 	: cetak bilabngan genap sebanyak n
*/

#include <stdio.h>
#include <conio.h>

int main() {
	//kamus
	int i;
	int N;
	
	//kamus
	printf("masukan N :"); scanf("%d", &N);
	
	if (N > 0){
		for (i = 1; i<= N; i++){
			if (i % 2 == 0){
				printf("%d", i);
			}
		}
	}
	
	return 0;
}
