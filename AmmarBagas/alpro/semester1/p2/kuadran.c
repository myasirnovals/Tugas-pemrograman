/*	program : kuadran.c
	author : 2350081008
	date : 17/10/2023
	desc : mencari posisi kuadran dari sebuah titik
*/

#include <stdio.h>
#include <conio.h>

typedef struct {
	int abs, ord;
} point;

int main() {
	//kamus
		point x, y;
		
	//algoritma
		printf("masukan titik x absis :"); scanf("%d", &x.abs);
		printf("masukan titik y ordinat :"); scanf("%d", &y.ord);
		
		
		if (x.abs > 0 && y.ord > 0){
			printf("titik berada di kuadran 1");
		}else if (x.abs < 0 && y.ord > 0){
			printf("titik berada di kuadran 2");
		}else if (x.abs < 0 && y.ord < 0){
			printf("titik berada di kuadran 3");
		}else if (x.abs > 0 && y.ord){
			printf("titik berada di kuadran 4");
		}else{
			printf("eror");
		}
		
		return 0;
}
