#include <stdio.h>
#include <stdlib.h>

int main()
{
	const float pi = 3.1415;
	float r;
	
	printf ("Jari-jari lingkaran ="); 
	scanf ("%f", &r);
	
	printf ("Luas lingkaran = %f \n", pi * r * r);
	printf ("Akhir program \n");
	return 0;
}
