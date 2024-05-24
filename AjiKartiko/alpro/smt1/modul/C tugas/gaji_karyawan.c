#include <stdio.h>


int main() {
	int golongan, jam_kerja;
	float gaji_tetap, gaji_per_jam, gaji_lembur, total_gaji;

	printf("Masukkan golongan karyawan (1-5): ");
	scanf("%d", &golongan);
	printf("Masukkan jumlah jam kerja: ");
	scanf("%d", &jam_kerja);
	
	switch (golongan) {
	case 1:
	gaji_tetap = 500000;
	gaji_per_jam = 5000;
	break;
	case 2:
	gaji_tetap = 300000;
	gaji_per_jam = 3000;
	break;
	case 3:
	gaji_tetap = 250000;
	gaji_per_jam = 2000;
	break;
	case 4:
	gaji_tetap = 100000;
	gaji_per_jam = 1500;
	break;
	case 5:
	gaji_tetap = 50000;
	gaji_per_jam = 1000;
	break;
	default:
	printf("Golongan karyawan tidak valid.\n");
	
	return 0;
 }
 if (jam_kerja > 150) {
 gaji_lembur = (jam_kerja - 150) * gaji_per_jam * 1.5;
 jam_kerja = 150;
 } else {
 gaji_lembur = 0.0;
 }
 total_gaji = gaji_tetap + jam_kerja * gaji_per_jam + gaji_lembur;
 
 printf("Total gaji yang diterima: Rp%.2f\n", total_gaji);
 
 return 0;
}
