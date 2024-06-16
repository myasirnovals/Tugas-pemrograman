/* Program 		:  mstack2.c 
   Author		:  2350081062 Aji Kartiko Hartanto
				   2350081064 Jarwo Eddy Wicaksono
				   2350081079 Rifqi Fauzi Anwar
   Kelas		:  C
   Deskripsi	:  Main Driver File ADT Stack List
   Tanggal  	:  15 Mei 2024
*/ 
#include "stack2.h"
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
//Kamus
	Stack MyStack;
	infotype x, y, cari;
	boolean ketemu;
//Algoritma
	CreateStack(&MyStack);
	printf("Nilai Stack = "); CetakStack(MyStack);
	printf("\nMengecek Nilai Stack : ");
	if(IsStackEmpty(MyStack)){
		printf("Stack Belum Terisi\n");
	}
	printf("\n==================================================\n");
	printf("Menginput Nilai pada Stack\n");
	printf("Masukan Bilangan : ");
	scanf("%d", &x);
		while(x != 999){
			Push(&MyStack, x);
			scanf("%d", &x);
		}
	printf("Hasil Stack = "); CetakStack(MyStack);
	printf("\n==================================================\n");
	printf("Stack Setelah di Hapus\n");
	Pop(&MyStack, &y);
	printf("Hasil Stack = "); CetakStack(MyStack);
	printf("\n==================================================");
	printf("\nPencarian Stack\n");
	printf("Masukan Angka yang Ingin Dicari : ");
	scanf("%d", &cari);
	ketemu = CariElemenStack(MyStack, cari);
		if(!IsStackEmpty(MyStack)){
			if(ketemu != false){
				printf("Elemen %d Ada Dalam Stack\n\n", cari);
			} 
			else{
				printf("Elemen %d Tidak Ada Dalam Stack\n\n", cari);
			}
		}
}

