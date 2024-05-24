#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	
	//KAMUS
	char cc;
	
	//ALGORITMA
	printf("ketikkan sebuah huruf, akhiri dengan RETURN \n");
	scanf("%s", &cc);
	switch (cc)
	{
	case 'a':
	{
	printf("yang anda ketik adalah a \n");
	break;
	}
	case 'u':
	{
	printf("yang anda ketik adalah u \n");
	break;
	}
	case 'e':
	{
	printf("yang anda ketik adalah e \n");
	break;
	}
	case 'i':
	{
	printf("yang anda ketik adalah i \n");
	break;
	}
	default:
	printf("yang anda ketik adalah huruf mati \n");
}

return 0;

}
