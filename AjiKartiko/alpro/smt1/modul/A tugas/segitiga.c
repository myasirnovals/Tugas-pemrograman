#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    // KAMUS
    int a, b, c;

    // ALGORITMA
    printf("Masukan nilai A: ");
    scanf("%d", &a);

    printf("Masukan nilai B: ");
    scanf("%d", &b);

    printf("Masukan nilai C: ");
    scanf("%d", &c);

    if (a > 0 && b > 0 && c > 0) {
        printf("Sebuah segitiga");
    } else {
        printf("Bukan segitiga");
    }

    return 0;
}
