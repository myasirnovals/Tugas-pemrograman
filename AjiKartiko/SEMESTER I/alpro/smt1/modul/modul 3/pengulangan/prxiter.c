#include <stdio.h>
#include <stdlib.h>

//jumlah nilai yang dibaca dengan ITERATE

int main(){
	
	//KAMUS:
	int Sum;
	int x;
	
	//ALGORITMA
	printf("masukkan nilai x (int), akhiri dengan 999: ");
	scanf("%d", &x); /*First Elmt*/
	
	if(x == 999)
	{
		printf("kasus kosong \n");
	}
	else
	{
		/*minimal ada satu yang dijumlahkan*/
		Sum = x; /*inisialisasi, invariant !!*/
		for (;;)
		{
			printf("masukkan nilai x (int), akhiri dengan 999 : ");
			scanf("%d", &x); /* Next Elmt*/
			if(x == 999)
				break;
			else
			{
				Sum = Sum + x; /*proses*/
			}
		}
		printf("hasil penjumlahan = %d \n", Sum); /*Terminasi*/
	}
	return 0;
}
