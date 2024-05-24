/*	program	: for5.c 
	author	: Ammar Bagas Fathurrahman Wamtoro
	nim		: 12350081008
	date	:24/10//2023
	desc 	: memunculkan segitiga "*" tergantung banyaknya n, dengan pola segitiga
*/


#include <stdio.h>
#include <conio.h>

int main() {
	//kamus
	int N;
	float i,s;
	
	//kamus
	printf("masukan N :"); scanf("%d", &N);
	s = 1.0;
	printf("s = 1+");
	for (i = 1; i <= N; i++){
		printf("%.3f", 1/i);
		if (i < N){
			printf("+");
			s = s + 1/i;
		}
	}
	
	printf("\nNilai s : %.2f", s);
	
	return 0;
}



