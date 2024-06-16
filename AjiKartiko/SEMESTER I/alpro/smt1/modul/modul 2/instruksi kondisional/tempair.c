#include <stdio.h>
#include <stdlib.h>

int main() 
{
	
	//KAMUS
	int T;
	
	//ALGORITMA
	printf("contoh IF tiga kasus \n");
	printf("temperatur (der. C) = ");
	scanf("%d", T);
	if (T < 0)
	printf("wujud air beku %d \n", T);
	else if ((0<=T) && (T <= 100))
	printf("wujud air cair %d \n", T);
	else if (T > 100)
	printf("wujud air uap/gas %d \n", T);
	
	return 0;
	
}
