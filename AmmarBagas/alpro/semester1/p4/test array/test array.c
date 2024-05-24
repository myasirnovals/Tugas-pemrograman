#include <stdio.h>

/*typedef struct {
	int array[5]; int neff;
}TabInt;

int main() {
	int i, n;
	TabInt Mytab;
	
	printf("masukan banyak data :"); scanf ("%d", &Mytab.array[5]);
	
	for (i = 1; i <= Mytab.array[5]; i++){
		printf("masukan isi data ke-%d:", i); scanf("%d", Mytab.neff[i]);
	}
}*/













int main(){
	int n, i;
	int array[n];
	
	printf("masukan banyak data :"); scanf("%d", &array[n]);
	
	for (i = 1; i <= array[n]; i++){
		printf("masukan isi data ke-%d:", i); scanf ("%d", &array[i]);
	}
	
	for (i = 1; i<= array[n]; i++){
		if (array[i]%2 == 0){
			printf("%d", array[i]);
		}
	}
}	
