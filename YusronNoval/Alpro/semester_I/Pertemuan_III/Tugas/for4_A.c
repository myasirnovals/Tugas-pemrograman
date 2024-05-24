/*
    Program: for4_A.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 24/10/2023
    Description: Memunculkan angka tergantung N menggunakan perulangan for
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus
    int N;
    int i;
    int bil1, bil2, bil3, bil4;

    // Algoritma
    printf("Masukkan nilai N: ");
    scanf("%d", &N);

    if(N > 0) {
        bil1 = 1;
        bil2 = 2;
        bil3 = 3;
        bil4 = 4;

        for(i=1; i <= N; i++) {
            printf("%d ", bil1);
            bil1 = bil1 + 1;
        }
        printf("\n");

        for(i=1; i <= N; i++) {
            printf("%d ", bil2);
            bil2 = bil2 + 1;

        }
        printf("\n");

        for(i=1; i <= N; i++) {
            printf("%d ", bil3);
            bil3 = bil3 + 1;
        }
        printf("\n");

        for(i=1; i <= N; i++) {
            printf("%d ", bil4);
            bil4 = bil4 + 1;

        }
        printf("\n");
    
    } else {
        printf("Nilai N tidak boleh kurang dari 0");
    }

    return 0;
}