#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    // Kamus
    short ks = 1;
    int ki = 1;
    long kl = 10000;
    char c = 65;
    char cl = 'Z';
    float x = 1.55;

    // Algoritma
    printf("Karakter = %c \n\n", c);
    printf("Karakter = %c \n\n", cl);
    printf("Karakter = %d \n\n", c);
    printf("Karakter = %d \n\n", cl);
    
	printf("Bilangan integer (short) = %d \n\n", ks);
    
	printf("\t\t(int) = %d \n\n", ki);
    printf("\t\t(long) = %ld \n\n", kl);
   
    printf("Bilangan Real = %f8.3 \n\n", x);

    return 0;
}

