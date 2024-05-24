/*
    Program: for4_B.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 24/10/2023
    Description: Memunculkan angka tergantung N menggunakan perulangan for tetapi setelah mencapai batas ulangi dari angka 1
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus
    int N;
    int i;
    int j;

    // Algoritma
    printf("Masukkan nilai N: ");
    scanf("%d", &N);

    if(N > 0) {
        for(i = 1; i < N; i++) {
            for(j = i; j < N; j++) {
                printf("%d ", j);
            }

            for(j=1; j < i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }

    } else {
        printf("Nilai N tidak boleh kurang dari 0");
    }

    return 0;
}
// Hasil ada 5
// Tugas ada 4
