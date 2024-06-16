#include <stdio.h>
#include <math.h>

int main() {
    int angka = 20;
    int akar_angka = sqrt(angka);
	int i;
	
    printf("Faktor dari %d adalah:\n", angka);
    for (i = 1; i <= akar_angka; i++) {
        if (angka % i == 0) {
            printf("%d dan %d\n", i, angka / i);
        }
    }

    return 0;
}
