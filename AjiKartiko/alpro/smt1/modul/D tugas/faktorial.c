#include <stdio.h>

unsigned long long hitung_faktorial(int n) {
    unsigned long long faktorial = 1;
    int i;
    
    if (n < 0) {
        printf("Faktorial tidak dapat dihitung untuk angka negatif.\n");
        return 0;
    } else if (n == 0) {
        return 1;
    } else {
        for (i = 1; i <= n; i++) {
            faktorial *= i;
        }
        return faktorial;
    }
}

int main() {
    int angka = 5; // Anda dapat mengganti angka sesuai keinginan Anda
    unsigned long long hasil = hitung_faktorial(angka);
    printf("Faktorial dari %d adalah %llu.\n", angka, hasil);

    return 0;
}
