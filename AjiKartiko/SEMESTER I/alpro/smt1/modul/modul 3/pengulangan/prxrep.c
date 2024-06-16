#include <stdio.h>
#include <stdlib.h>

/*jumlahkan nilai yang dibaca dengan REPEAT dan penanganan kasus kosong*/

int main(){
	
	//KAMUS
	int Sum;
	int x;
	
	//ALGORITMA
	printf("masukkan nilai x (int), akhiri dengan 999: ");
	scanf("%d", &x); /*First Elmt*/
	
	if (x == 999)
	{
	printf("kasus kosong \n");
	}
	else
	{ /*minimal ada satu data yang dijumlahkan*/
	Sum = 0; /*inisialisasi; invariant !!*/
	}
	do{
	Sum = Sum + x; /*proses*/
	printf("masukkan nilai x (int), akhiri dengan 999 : ");
	scanf("%d", &x); /*Next Elmt*/
	}
	while(x != 999); /*kondisi pengulangan*/
	printf("hasil penjumlahan = %d \n", Sum); /*Terminasi*/
	
	return 0;
}	
