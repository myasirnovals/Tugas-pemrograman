/*
Deskripsi program : membuat bilangan terbilangan dengan rekusif
*/

#include <stdio.h>
#include <conio.h>

void terbilang(long long int x);

int main() {
    // KAMUS UTAMA
    long long int jumUang;

    // ALGORITMA UTAMA
    printf("Masukan Jumlah Uang : ");
    scanf("%lld", &jumUang);
    terbilang(jumUang);
    printf("Rupiah");
}

void terbilang(long long int x) {
    // ALGORITMA LOKAL
    if (x == 1) {
        printf("Satu ");
    } else if (x == 2) {
        printf("Dua ");
    } else if (x == 3) {
        printf("Tiga ");
    } else if (x == 4) {
        printf("Empat ");
    } else if (x == 5) {
        printf("Lima ");
    } else if (x == 6) {
        printf("Enam ");
    } else if (x == 7) {
        printf("Tujuh ");
    } else if (x == 8) {
        printf("Delapan ");
    } else if (x == 9) {
        printf("Sembilan ");
    } else if (x == 10) {
        printf("Sepuluh ");
    } else if (x == 11) {
        printf("Sebelas ");
    } else if (x >= 12 && x <= 19) {
        terbilang(x % 10);
        printf("Belas ");
    } else if (x >= 20 && x <= 99) {
        terbilang(x / 10);
        printf("Puluh ");
        terbilang(x % 10);
    } else if (x >= 100 && x <= 199) {
        printf("Seratus ");
        terbilang(x - 100);
    } else if (x >= 200 && x <= 999) {
        terbilang(x / 100);
        printf("Ratus ");
        terbilang(x % 100);
    } else if (x >= 1000 && x <= 1999) {
        printf("Seribu ");
        terbilang(x - 1000);
    } else if (x >= 2000 && x <= 999999) {
        terbilang(x / 1000);
        printf("Ribu ");
        terbilang(x % 1000);
    } else if (x >= 1000000 && x <= 999999999) {
        terbilang(x / 1000000);
        printf("Juta ");
        terbilang(x % 1000000);
    } else if (x >= 1000000000 && x <= 999999999999) {
        terbilang(x / 1000000000);
        printf("Miliar ");
        terbilang(x % 1000000000);
    } else if (x >= 1000000000000 && x <= 999999999999999) {
        terbilang(x / 1000000000000);
        printf("Triliun ");
        terbilang(x % 1000000000000);
    }
}