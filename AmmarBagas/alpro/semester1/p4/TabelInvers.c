/*	program	:  TabInt_Invers.c
	author	: Ammar Bagas Fathurrahman Wamtoro
	nim		: 12350081008
	date	:31/10//2023
	desc 	: cetak tabel array dengan invers
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
	printf("masukan angka 999 untuk menghentikan input");
	printf("\nmasukan bilangan :"); scanf("%d", &N);
	
	while (N != 999){
		if (Mytab.neff < nMax){
			Mytab.neff++;
			Mytab.T[Mytab.neff] = N;
		}
		printf("masukan bilangan :"); scanf("%d", &N);
	}
	
	//cetak tabel
	for (i = Mytab.neff; i>= 1; i--){
		printf("<%d>", Mytab.T[i]);
	}
	
	return 0;
}
