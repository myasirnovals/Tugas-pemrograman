/*	program	: loop_2.c 
	author	: Ammar Bagas Fathurrahman Wamtoro
	nim		: 12350081008
	date	:24/10//2023
	desc 	: program menghitung deret dengan repeat n times menggunakan skema repeat until
*/

#include <stdio.h>
#include <conio.h>

int main() {
	//kamus
	int N;
	float i, s;
	
	//kamus
	printf("masukan N :"); scanf("%d", &N);
	
	i = 1;
	s = 1.0;
	printf("s = 1 +");
	
	do  {
		printf("%1.3f", 1/i);
		if (i < N){
			printf("+");
			s = s + 1/i;
		}
		i++;
	} while (i <= N);
	
	printf("\nNilai s : %.2f", s);
	return 0;
}
