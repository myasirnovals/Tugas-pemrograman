/*	program : if1.c
	author : 2350081008
	date : 17/10/2023
	desc : program mencari nilai maksimum
*/

#include <stdio.h>
#include <conio.h>
//program mencari nilai maksimum
int main() {
	//kamus
	int a, b;
	
	//algoritma
	
	printf("masukan a :"); scanf("%d", &a);
	printf("masukan b :"); scanf("%d", &b);
	
	//analisa kasus 1
	if (a>b){
		printf("a > b");
	}
	else if (a == b){
		printf("a = b");
	}else{
		printf("a < b");
	}
	
	return 0;
}
