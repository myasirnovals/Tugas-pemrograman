/*	program	: for3.c 
	author	: Ammar Bagas Fathurrahman Wamtoro
	nim		: 12350081008
	date	:24/10//2023
	desc 	: memunculkan segitiga "*" tergantung banyaknya n, dengan pola segitiga
*/

#include <stdio.h>
#include <conio.h>
int main () {
	//kamus
	int i;
	int N;
	int j;
	
	
	//kamus
	printf("masukan N :"); scanf("%d", &N);
	
	//kondisional dan pengulangan
	if (N < 0){
		printf("segitiga tidak jadi");
	}else {
		
		//segitiga atas
		//pengulangan enter atau break 
		for (i = 1; i <= N; i++){
			
			//pengulangan bintang
			for (j = 1 ;j <= i; j++){
				printf("*");
			}
		
			printf("\n");
		}
		
		//segitga bawah
		//pengulangan enter atau break
		for (i = 1; i <= N; i++){
			
			//pengulangan bintang
			for (j = i; j <= N; j++){
				printf("*");
			}
			
			printf("\n");
		}
		
		
	}
	return 0;
}
