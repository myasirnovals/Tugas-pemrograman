#include <stdio.h>

int hitung_sigma(int k) {
    int hasil = 0;
    int n;
    
    for (n = 0; n <= k; n++) {
        hasil += (n * n) + 5;
    }
    return hasil;
}

int main() {
    int k = 5; // Anda dapat mengganti nilai K sesuai keinginan Anda
    int hasil = hitung_sigma(k);
    printf("Hasil penjumlahan sigma dari 0 sampai %d adalah %d.\n", k, hasil);

    return 0;
}
