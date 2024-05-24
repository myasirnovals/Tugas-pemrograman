/**
 * Program: jumcacah.c
 * Author: 2350081004/Muhamad Yasir Noval
 * Date: 24 Oktober 2023
 * Description: Membaca sekumpulan nilai integer yang diinputkan melalui
 * keyboard pengguna
 */

#include <stdio.h>

int main() {
    // KAMUS
    int n, data, i, hasil;

    // ALGORITMA
    printf("input pencacah : ");
    scanf("%d", &n);

    i = 1;
    hasil = 0;
    // inisialisasi
    do {
        //dilakukan aksi 1x terlebih dahulu
        printf("input data : ");
        scanf("%d", &data);
        printf("");
        if (i < n) {
            printf("_____________+\n");
        }
        hasil = hasil + data;
        i++;
    } while (i <= n);
    printf("\n\n================================");

    printf("\nBanyak Data Integer\t\t : %d", n);
    printf("\nNilai Penjumlahan\t\t : %d ", hasil);

    return 0;
}
