#include <stdio.h>
#include <conio.h>

//Program Untuk Memanggil Sebuah Prosedur

/* kamus global */
/* definisi prototype */

void tukar(int *a, int *b);
/* 	I.S: a, b terdefinisi sembarang
	F.S: a dan b saling bertukar nilai */

int main(){
	/* kamus lokal pada main driver */
	int bil1, bil2;
	
	//KAMUS
	system("cls");
	printf("masukkan bilangan 1: "); scanf("%d", &bil1);
	printf("masukkan bilangan 2: "); scanf("%d", &bil2);
	
	/* pemanggilan prosedur tukar */
	tukar(&bil1, &bil2);
	printf("hasil pertukaran a: %d; b; %d", bil1, bil2);
	
	return 0;
	
}

/* realisasi prototype */
void tukar(int *a, int *b){

/* 	I.S: a, b terdefinisi sembarang
	F.S: a dan b saling bertukar nilai */
	
	/* kamus lokal */
	int tmp;
	
	/* algoritma */
	tmp = *a;
	*a = *b;
	*b = tmp;
}
