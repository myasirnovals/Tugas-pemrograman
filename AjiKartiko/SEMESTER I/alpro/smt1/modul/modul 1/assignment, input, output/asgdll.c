#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
    // Kamus
    float f;  //f=20.0f
    double fll;  //fll=10.0L

    // Algoritma
    printf("Masukkan float: ");
    scanf("%f", &f);

    printf("Masukkan double: ");
    scanf("%lf", &fll);

    printf("Hasil float: %f \n", f);
    printf("Hasil double: %lf \n", fll);

    return 0;
}
