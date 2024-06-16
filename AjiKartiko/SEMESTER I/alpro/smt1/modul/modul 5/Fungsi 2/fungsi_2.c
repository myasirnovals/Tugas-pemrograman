/*
nama: aji kartiko Hartanto
nim: 2350081062
kelas: C
10-Nov-2023
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
    printf("Diskriminant = %d\n", D);

    if (D > 0) {
        fungsi = persamaanKuadrat(a, b, D);
        printf("Fungsi persamaan kuadrat = %.2lf\n", fungsi);
    } else {
        printf("Nilai persamaan bernilai 9999 \n");
    }

    return 0;
}

// realisasi prototype
int Diskriminant(int a, int b, int c) {
    // KAMUS lokal
    int d;

    // ALGORITMA
    d = ((b * b) - (4 * a * c));
    return (d);
}

double persamaanKuadrat(double a, double b, double d) {
    // KAMUS lokal
    double x1, x2, hasil;;


    // ALGORITMA
    x1 = (-b + sqrt(d)) / (2 * a);
    x2 = (-b - sqrt(d)) / (2 * a);

    hasil = x1 + x2;

    return hasil;
}
