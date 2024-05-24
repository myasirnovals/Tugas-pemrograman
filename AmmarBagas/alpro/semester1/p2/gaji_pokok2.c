/*	program : if3.c
	author : 2350081008
	date : 17/10/2023
	desc : program mencari gaji total di tambah fitur masa kerja
*/

//porgram menghitung gaji total
#include <stdio.h>
#include <conio.h>

int main() {
	//kamus
	long gatot, gapok, tjanak, tjgol, tjmk;
	int anak, gol, mk;
	
	//algoritma
	printf("input gaji pokok :"); scanf("%d", &gapok);
	printf("input jumlah anak :"); scanf("%d", &anak);
	printf("input golongan :"); scanf("%d", &gol);
	printf("input masa kerja :"); scanf("%d", &mk);
	
	//kondosional
	if (gol == 1){
		tjgol = 1000000;
	}else if (gol == 2){
		tjgol = 2000000;
	}else {
		tjgol = 0;
	}
	
	if (anak <= 3){
		tjanak = anak*700000;
	}else {
		tjanak = 3*700000;
	}
	
	if(mk < 5){
		tjmk = 500000;
	}else if(5 <= mk && mk< 10){
		tjmk = 1000000;
	}else if(mk >= 10){
		tjmk = 2000000;
	}
	//hitung gaji total
	gatot = gapok + tjanak + tjgol + tjmk;
	printf("gaji total %ld", gatot);
	
	return 0;
}
