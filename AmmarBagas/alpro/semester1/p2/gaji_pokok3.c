/*	program : if4.c
	author : 2350081008
	date : 17/10/2023
	desc : program mencari gaji total di tambah fitur masa kerja di tambah fitur tunjangan anak
*/

//porgram menghitung gaji total
#include <stdio.h>
#include <conio.h>

int main() {
	//kamus
	long gatot, gapok, tjanak, tjgol, tjmk, anak1, anak2, anak3;
	int anak, gol, mk, umur1, umur2, umur3;
	
	//algoritma
	printf("input gaji pokok :"); scanf("%d", &gapok);
	printf("input golongan :"); scanf("%d", &gol);
	printf("input masa kerja :"); scanf("%d", &mk);
	
	printf("masukan jumlah anak :"); scanf("%d", &anak);


	/*printf("masukan umur anak 1 :"); scanf("%d", &umur1);
	printf("masukan umur anak 2 :"); scanf ("%d", &umur2);
	printf("masukan umur anak 3 :"); scanf ("%d", &umur3);	
	*/

	//kondosional
	if (gol == 1){
		tjgol = 1000000;
	}else if (gol == 2){
		tjgol = 2000000;
	}else {
		tjgol = 0;
	}
	
	//anak
	if (anak > 0){
		printf("masukan umur anak maksimal 17 tahun, isi dengan 0 jika anak kurang dari 3""\n");
		printf("masukan umur anak 1 :"); scanf("%d", &umur1);
		printf("masukan umur anak 2 :"); scanf("%d", &umur2);
		printf("masukan umur anak 3 :"); scanf("%d", &umur3);
	}
	
	if (anak > 0){
		if (umur1 <= 17 && umur1 > 0){
			anak1 = 700000;
		}if (umur2 <= 17 && umur2 > 0){
			anak2 = 700000;
		}if (umur3 <= 17 && umur3 > 0){
			anak3 = 700000;
		}else{
			anak1, anak2, anak3 = 0;
		}
	}
	
	tjanak = anak1 + anak2 + anak3;
	
	/*if (anak > 3){
		tjanak = 3*700000;
	}*/
	
	//mk
	if(mk < 5){
		tjmk = 500000;
	}else if(5 <= mk && mk< 10){
		tjmk = 1000000;
	}else if(mk >= 10){
		tjmk = 2000000;
	}
	
	//hitung tj anak
	//tjanak = anak1 + anak2 + anak3;
	
	//hitung gaji total
	
	gatot = gapok + tjanak + tjgol + tjmk;
	printf ("gaji total : %d", gatot);
	
	return 0;
}
