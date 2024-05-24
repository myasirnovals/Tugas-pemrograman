#include <stdio.h>
#include <stdlib.h>

/* contoh baca nilai x, */
/* jumlahkan nilai yang dibaca dengan WHILE	*/

int main(){
	
	//KAMUS
	int Sum;
	int x;
	
	//ALGORITMA
	Sum = 0; /* inisialisasi */
	printf("masukkan nilai x (int), akhiri dengan 999: ");
	scanf("%d", &x); /* First Elmt */
	while (x != 999) /* kondisi berhenti */
	{
		Sum = Sum + x; /* proses */
		printf("masukkan nilai x (int), akhiri dengan 999: ");
		scanf("%d", x); /* First Elmt */
	}
	printf("hasil penjumlahan = %d \n", Sum); /* Terminasi */
	
	return 0;
}
