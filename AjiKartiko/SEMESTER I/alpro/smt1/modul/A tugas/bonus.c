#include <stdio.h>
#include <stdlib.h>

int main() {
    // Kamus
    int staff, nonStaff, umurStaff, umurNonStaff;
    int lamaBekerja = 5;

    // Algoritma
    printf("Masukan nilai lama bekerja staff: ");
    scanf("%d", &staff);

    printf("Masukkan nilai lama bekerja nonStaff: ");
    scanf("%d", &nonStaff);

    printf("Masukkan nilai umur staff: ");
    scanf("%d", &umurStaff);

    printf("Masukkan nilai umur nonStaff: ");
    scanf("%d", &umurNonStaff);

    if (staff > lamaBekerja && umurStaff > 50) {
        printf("\n(staff) Anda mendapatkan Bonus sebesar Rp.1.000.000\n");
    } else if (staff <= lamaBekerja) {
        if (umurStaff < 50) {
            printf("\n(staff) Anda mendapatkan Bonus sebesar Rp.300.000\n");
        } else {
            printf("\n(staff) Anda mendapatkan Bonus sebesar Rp.500.000\n");
        }
    } else {
        printf("Error tidak terdapat data\n");
    }

    if (nonStaff > lamaBekerja && umurNonStaff > 50) {
        printf("(nonStaff) And mendapatkan Bonus sebesar Rp.400.000\n");
    } else if (nonStaff >= lamaBekerja) {
        if (umurNonStaff < 50) {
            printf("(nonStaff) Anda mendapatkan Bonus sebesar Rp.250.000\n");
        } else {
            printf("(nonStaff) Anda Tidak Mendapatkan Bonus");
        }
    } else {
        printf("Error tidak terdapat data\n");
    }

    return 0;
}
