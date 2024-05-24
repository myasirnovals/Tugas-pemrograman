/*	program	:  TabInt.c
	author	: Ammar Bagas Fathurrahman Wamtoro
	nim		: 12350081008
	date	:31/10//2023
	desc 	: cetak tabel array
*/

#include <stdio.h>
#include <conio.h>
#include "boolean.h"

#define nMax 10

typedef struct {
	int T[nMax + 1];
	int neff;
}TabInt;

//main driver
int main() {
	//kamus
	TabInt Mytab;
	int N;
	int i;
	
	//algoritma
	Mytab.neff = 0;
	printf("masukan bilangan :"); scanf("%d", &N);
	
	while (N != 999){
		if (Mytab.neff < nMax){
			Mytab.neff++;
			Mytab.T[Mytab.neff] = N;
		}
		printf("masukan bilangan :"); scanf("%d", &N);
	}
	
	//cetak tabel
	for (i = 1; i <= Mytab.neff; i++){
		printf("<%d>", Mytab.T[i]);
	}
	
	return 0;
}
