#include <stdio.h>

int main()
{
    // Kamus
    int matriks [3][3] = {
        {1,3,5,},
        {2,4,6},
        {1,2,3}
    };

    // Algoritma
    printf("Isi data pada indeks ke-(1,0): %d\n", matriks[1][0]);

    return 0;
}