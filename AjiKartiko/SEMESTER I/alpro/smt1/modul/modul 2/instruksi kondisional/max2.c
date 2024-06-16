#include <stdio.h>
#include <stdlib.h>

/* maksimum dua bilangan yang dibaca */

int main()
{
	//KAMUS
	int a, b;
	
	//ALGORITMA
	printf("maksimum dua bilangan: \n");
	printf("ketikkan dua bilangan, pisahkan dg RETURN: \n");
	scanf("%d %d, &a, &b");
	
	printf("ke dua bilangan: a=%d, b=%d \n", a, b);
	if (a >= b)
	{
	printf("nilai a yang maksimum %d \n", a);
	}
	else /* a > b */
	{
	printf("nilai b maksimum: %d \n", b);
	};
	
	return 0;
	
}
