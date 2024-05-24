/**
 * Program: fungsi_2.c
 * Author: 2350081004/Muhamad Yasir Noval
 * Date: 28 November 2023
 * Description: Membuat fungsi untuk menghitung akar-akar dari persamaan
 * kuadrat, dengan masukkan berupa a, b, dan c dengan tipe data nya tipe
 * data integer. Dengan memanfaatkan fungsi diskriminant yang sudah kita
 * buat pada latihan fungsi_1.c
 */

#include <stdio.h>
#include <conio.h>
#include <math.h>

// KAMUS GLOBAL
// Definisi Prototype

// mengirim nilai diskriminant dari masukan a, b, dan c
int Diskriminant(int a, int b, int c);

double persamaanKuadrat(double a, double b, double d);

int main() {
    // KAMUS lokal pada main driver
    int D;
    int a, b, c;
    double fungsi;

    // ALGORITMA
    printf("Masukan koefesien a: ");
    scanf("%d", &a);

    printf("Masukan koefesien b: ");
    scanf("%d", &b);

    printf("Masukan koefesien c: ");
    scanf("%d", &c);

    D = Diskriminant(a, b, c);
    printf("D = %d\n\n", D);

    if (D > 0) {
        fungsi = persamaanKuadrat(a, b, D);
        printf("Fungsi persamaan kuadrat = %.2lf\n", fungsi);
    } else {
        printf("Nilai persamaan menghasilkan nilai imajiner, nilai akar = 9999\n");
    }

    return 0;
}

// realisasi prototype
int Diskriminant(int a, int b, int c) {
    // KAMUS lokal
    int d;

    // ALGORITMA
    printf("\nDiskriminant\n");
    printf("D = ((%d * %d) - (4 * %d * %d))\n", b, b, a, c);

    d = ((b * b) - (4 * a * c));

    return (d);
}

double persamaanKuadrat(double a, double b, double d) {
    // KAMUS lokal
    double x1, x2, hasil;;


    // ALGORITMA
    printf("\nAkar Kuadrat\n");
    x1 = (-b + sqrt(d)) / (2 * a);
    x2 = (-b + sqrt(d)) / (2 * a);

    printf("x1 = (-%.2lf + sqrt(%.2lf)) / (2 * %.2lf)\n", b, d, a);
    printf("x1 = %.2lf\n", x1);

    printf("x2 = (-%.2lf + sqrt(%.2lf)) / (2 * %.2lf)\n", b, d, a);
    printf("x2 = %.2lf\n", x2);

    hasil = x1 + x2;

    printf("\nx1 + x2 = ....\n");
    printf("%.2lf + %.2lf = %.2lf\n\n", x1, x2, hasil);

    return hasil;
}