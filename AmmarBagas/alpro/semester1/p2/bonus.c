/*	program : bonus.c
	author : 2350081008
	date : 17/10/2023
	desc : program mencari bonus pegawai
*/

#include <stdio.h>
#include <conio.h>

int main() {
	//kamus
		//deklarasi
		int staf, nonStaf, umurStaf, umurnonStaf;
		
	//algoritma
		//input
		printf("jika anda staf isi 0 pada non staf, lalu jika anda nonstaf isi 0 pada staf\n");
		
		//input staf
		printf("masukan masa kerja staf :"); scanf("%d", &staf);
		
		if (staf > 0){
			printf("masukan umur anda :"); scanf("%d", &umurStaf);
		}
		//input nonstaf
		if (staf == 0 && nonStaf > 0){
			printf("masukan masa kerja non staf :"); scanf("%d", &nonStaf);	
		}if (staf == 0 && nonStaf > 0){
			printf("masukan umur anda :"); scanf("%d", &umurnonStaf);
		}
		
		if (staf == 0 && nonStaf == 0){
			printf("anda bukan pegawai");
		}
		
		
		//kondisional
		//bonus staf
		if ( staf >= 5 && umurStaf >=50){
			printf("anda mendapatkan bonus 1 juta");
		}if (staf >= 5 && umurStaf < 50 && umurStaf > 0){
			printf("anda mendapatkan bonus 800 ribu");
		}if (staf < 5 && staf > 0){
			printf("anda mendapatkan bonus 500 ribu");
		}/*else if (umurStaf < 50 && umurStaf > 0){
			printf("anda mendapatkan bonus sebesar 300 ribu");
		}*/
		
		//bonus non staf
		if (nonStaf >= 5 && umurnonStaf >= 50){
			printf("anda mendapatkan bonus 400 ribu");
		}if (nonStaf >= 5 && umurnonStaf < 50){
			printf("anda mendapatkan bonus 300 ribu");
		}if (nonStaf > 0 && umurnonStaf > 0 && nonStaf < 5 && umurnonStaf < 50){
			printf("anda mendapatkan bonus 250 ribu");
		}
		
	return 0;
}
