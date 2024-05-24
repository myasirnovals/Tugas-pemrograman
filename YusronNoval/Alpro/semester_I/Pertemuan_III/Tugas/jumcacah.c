/*
    Program: jumcacah.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 24/10/2023
    Description: Menghitung bilangan pencacah menggunakan for loop
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    // KAMUS
    int N, data,i,a,hasil,X;

    // ALGORITMA
    printf("Masukkan bilangan pencacah : ");
    scanf("%d",&N);

    i = 1;
    hasil = 0;

    do{
        // Dilakukan aksi 1x terlebih dahulu
        // Setiap aksi yang dilakukan tergantung nilai N
        printf("Masukkan data : ");
        scanf("%d",&data);printf("");
        if (i<N){
            printf("_____________+\n");
        }
        hasil = hasil + data;
        i++;

    }while (i<=N);
    printf("\n\n================================");

    printf("\nBanyak Data Integer\t\t : %d", N);
    printf("\nNilai Penjumlahan\t\t : %d \n\n", hasil);

    return 0;
}