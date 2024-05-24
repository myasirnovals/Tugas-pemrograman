/*	program : if2.c
	author : 2350081008
	date : 17/10/2023
	desc : program latihan mencari gaji total
*/

//porgram menghitung gaji total
#include <stdio.h>
#include <conio.h>

int main() {
	//kamus
	long gatot, gapok, tjanak, tjgol;
	int anak, gol;
	
	//algoritma
	printf("input gaji pokok :"); scanf("%d", &gapok);
	printf("input jumlah anak :"); scanf("%d", &anak);
	printf("input golongan :"); scanf("%d", &gol);
	
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
	
	//hitung gaji total
	gatot = gapok + tjanak + tjgol;
	printf("gaji total %ld", gatot);
	
	return 0;
}

