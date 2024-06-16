#include <stdio.h>


int main() {
	
	int R1, R2, R3;
	char sambungan;
	float tahanan_total;
	
	printf("Masukkan nilai R1: ");
	scanf("%d", &R1);
	printf("Masukkan nilai R2: ");
	scanf("%d", &R2);
	printf("Masukkan nilai R3: ");
	scanf("%d", &R3); 
	printf("Masukkan sambungan (ketik S untuk seri, ketik P untuk paralel): ");
	scanf(" %c", &sambungan);
	
	if (sambungan == 'S' || sambungan == 's') {
	tahanan_total = R1 + R2 + R3;
	} else if (sambungan == 'P' || sambungan == 'p') {
	if (R1 == 0 || R2 == 0 || R3 == 0) {
	printf("Tidak dapat menghitung tahanan total karena terdapat tahanan yang bernilai nol.\n");

 	return 0;
 }
 tahanan_total = 1.0 / (1.0 / R1 + 1.0 / R2 + 1.0 / R3);
 } else {
 printf("Sambungan tidak valid.\n");
 return 0;
 }
 printf("Tahanan total rangkaian adalah %.2f ohm.\n", tahanan_total);
 return 0;
}

