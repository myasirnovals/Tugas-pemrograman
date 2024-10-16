#include <stdio.h>
#include <stdlib.h>

int main(){
  
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
