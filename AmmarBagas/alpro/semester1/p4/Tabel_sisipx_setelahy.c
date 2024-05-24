/*	program	: TabInt.c tambah sisipkan x sebelah y
	author	: Ammar Bagas Fathurrahman Wamtoro
	nim		: 12350081008
	date	: 31/10//2023
	desc 	: cetak tabel array dengan tambahan menyisipkan x di sebelah y
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
	int N, i, x, y, j, last;
	boolean ketemu;
	
	//algoritma
	//tabel 1
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
	
	
	//tabel 2
	//input x dan y
	printf ("\nmasukan nilai x :"); scanf("%d", &x);
	printf ("masukan nilai y :"); scanf("%d", &y);
	
	i = 1;
	ketemu = false;
	
	
	//mencari y apakah ada di dalam data array
	while (i <= Mytab.neff && !ketemu){
		//kondisional pencari data
		if (Mytab.T[i] == y){
			ketemu = true;
		}else{
			i++;
		}
		
		//kondisional jika data y tidak ada dalam array
		if (Mytab.T[i] != y){
			ketemu = ketemu;
		}
	}
	
	//menyisipkan data x ke array jika y tidak ada di array
	if (!ketemu){
			Mytab.neff++;
			Mytab.T[Mytab.neff] = x;
	}
	
	//jika y ditemukan dalam array "ketemu = true"
	if (ketemu){
		
		if (Mytab.neff < nMax){
			last = Mytab.neff;
			
			if (i >= last){
				Mytab.neff++;
				Mytab.T[Mytab.neff] = x;
				
			}else {
				for (j = last ; last >= i; j--){
					Mytab.T[j + 1] = Mytab.T[j];
					last--;
				}
			
				
				Mytab.T[i] = x;
				Mytab.neff++;
			} 
	
		}
	}
	
	
	
	//cetak tabel 2
	for (i = 1; i <= Mytab.neff ; i++){
		printf("<%d>", Mytab.T[i]);
	}
	return 0;
}
	
		
	//penggunaan menggunakan for

	/*for (i = 1; i <= Mytab.neff && !ketemu; i++){
		if (Mytab.T[i] == y){
			ketemu = true;
		}else {
			ketemu = ketemu;
		}
	}*/
	

