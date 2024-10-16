#include <stdio.h>
#include <stdlib.h>
#define pi 3.1415

int main(){
	
	float r;
	float luas;
	
	printf ("Jari-jari lingkaran =");
	scanf ("%f", &r);
	luas = pi * r * r;
	
	printf ("Luas lingkaran = %6.2f\n", luas);
	printf ("Akhir program \n");
	return 0;
}
