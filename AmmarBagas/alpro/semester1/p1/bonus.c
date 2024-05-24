#include <stdio.h>
#include <conio.h>

int main() {
	//kamus
	int staf;
	int nonstaf;
	int umurstaf;
	int umurnonstaf;
	int masakerja = 5;
	
	//algoritma
	printf("masukan masa kerja staf :"); scanf("%d", &staf);
	
	printf("masukan umur staf :"); scanf("%d", &umurstaf);
	
	printf("masukan masa kerja nonstaf :"); scanf("%d", &nonstaf);
	
	printf("masukan umur nonstaf :"); scanf("%d", &umurnonstaf);
	
	//staf
	if (staf > masakerja && umurstaf >= 50 ){
		printf("bonus 1 juta");
	}else if (staf < masakerja && umurstaf >= 0){
		printf("bonus 500 ribu");
	}else if (umurstaf < 50){
		printf("bonus 300 ribu");
	}

	return 0;
}
