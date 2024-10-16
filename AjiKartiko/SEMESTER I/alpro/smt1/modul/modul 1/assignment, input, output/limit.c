#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 

{
    // KAMUS
    int i;
    long int ii;

    // ALGORITMA
    printf("Hello \n");
    i = 1234;
    ii = 123456;

    printf("Ini nilai i=1234 = : %d \n\n",i);
    printf("Ini nilai ii=123456 = : %d \n\n", ii);

    printf("Min dan Max integer: %d, %d \n\n", __WINT_MIN__, __INT_MAX__);
    printf("Max long integer: %ld, %ld \n\n", __LONG_MAX__);

    return 0;
}
