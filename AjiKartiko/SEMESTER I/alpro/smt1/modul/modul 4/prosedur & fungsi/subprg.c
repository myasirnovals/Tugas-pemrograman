#include <stdio.h>
#include <stdlib.h>

// contoh program yang mengandung prosedur dan fungsi
/*** ada dua cara untuk deklarasi prototype. yang dipakai cara kedua ***/
/* int maxab(int, int); */
/* void tukar(int*, int*); */

int maxab(int a, int b);
void tukar (int *a, int *b);

/*** Program Utama ***/

int main(){
	/* membaca dua bilangan integer */
	/* menuliskan maksimum dua bilangan yang dibaca dengan memanggil fungsi */
	/* menukar dua bilangan dengan 'prosedur' */
	
	int a, b;
	printf("maksimum dua bilangan: \n");
	printf("ketikkan dua bilangan, pisahkan dengan RETURN: \n"); scanf("%d %d", &a, &b);
	
	printf("ke dua bilangan: a=%d, b=%d \n", a, b);
	printf("maksimum= %d \n", maxab (a, b));
	printf("tukar kedua bilangan... \n");
	
	tukar(&a, &b);
	printf("ke dua bilangan setelah ditukar: a=%d, b=%d \n",a, b);
	
	return 0;
	
}

/* BODY/REALISASI prosedur/fungsi */
int maxab (int a, int b){
	/* mencari maksimum dua bilangan bulat */
	return((a >= b)? a : b);
}

void tukar(int *a, int *b){
	/*menukar dua bilangan bulat */
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
