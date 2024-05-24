/**
 * Program: loop_3.c
 * Author: 2350081004/Muhamad Yasir Noval
 * Date: 24 Oktober 2023
 * Description: Progam menghitung deret dengan perulangan do while sebanyak n kali
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    // KAMUS
    int n;
    float i, s;

    // ALGORITMA
    printf("Masukan nilai N: ");
    scanf("%d", &n);

    // menggunakan skema loop while...do
    i = 1;
    s = 1.0;
    printf("s = 1 + ");

    do {
        printf("%1.3f", 1 / i);

        if (i < n) {
            printf(" + ");
            s = s + 1 / i;
        }

        i++;
    } while (i <= n);

    printf("\nNilai s : %.2f", s);

    return 0;
}