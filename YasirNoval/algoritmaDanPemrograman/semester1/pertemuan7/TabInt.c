/**
 * Program: TabInt.c
 * Author: 2350081004/Muhamad Yasir Noval
 * Date: 28 November 2023
 * Description: program untuk mencetak bilangan
 * dari 1 sampai 100 menggunakan perulangan for
 * tapi yang tercetak hanya bilangan prima saja
 */

#include <stdio.h>
#include <math.h>

// prosedur
int isPrima(int n);

int main() {
    // KAMUS
    int li;

    // ALGORITMA
    printf("Bilangan prima dari 1 sampai 100: \n");

    for (li = 1; li <= 100; li++) {
        if (isPrima(li)) {
            printf("%3d ", li);
        }
    }

    return 0;
}

int isPrima(int n) {
    // KAMUS lokal
    int li;

    // ALGORITMA lokal
    if (n == 2) {
        return 1; //true
    }

    if (n % 2 == 0 || n == 1) {
        return 0; //false
    }

    return 1; //true
}