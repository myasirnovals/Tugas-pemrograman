/* 
Nama: Aji Kartiko Hartanto
Nim: 2350081062
Kelas: C
10-Nov-2023
*/


#include <stdio.h>
#include <conio.h>

/* Kamus Global */
/* Definisi Prototype */
int Diskriminant(int a, int b, int c);
/* mengirim nilai diskriminant dari masukan a, b dan c */

int main(){
	/* kamus lokal pada main driver */
	int D;
	int a, b, c;
	
	/* Algoritma */
	printf("masukkan koefisien a:"); scanf("%d", &a);
	printf("masukkan koefisien b:"); scanf("%d", &b);
	printf("masukkan konstanta c:"); scanf("%d", &c);
	
	D = Diskriminant(a, b, c);
	
	printf("Diskriminant = %d", D);
	
	return 0;
	
}
/* realisasi prototype */
int Diskriminant(int a, int b, int c){
	//kamus lokal
	int d;
	
	//algoritma
	d = ((b*b)-(4*a*c));
	
	return (d);
	
}
