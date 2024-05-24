/*
    Program: Assigment1.c
    Name: Muhamad Yusron Noval
    NIM: 2350081003
    Class: A
    Description: ...
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus
    // Staff > 5 dan umurnya >= 50 : Rp.1.000.000
    // Staff < 5 dan umurnya bebas : Rp.500.000
    // nonStaff > 5 jika umurnya > 50 : Rp.400.000
    // nonStaff umurnya < 50 : Rp.250.000
    // Staff umurnya < 50 : Rp.300.000
    int Staff;
    int nonStaff;
    int umurStaff;
    int umurNonStaff;
    int lamaBekerja = 5;

    // Algoritma
    printf("Masukan nilai lama bekerja untuk Staff: ");
    scanf("%d", &Staff);

    printf("Masukkan nilai lama bekerja nonStaff: ");
    scanf("%d", &nonStaff);

    printf("Masukkan nilai umur Staff: ");
    scanf("%d", &umurStaff);

    printf("Masukkan nilai umur nonStaff: ");
    scanf("%d", &umurNonStaff);

    if(Staff >= lamaBekerja && umurStaff >= 50) {
        printf("\n\n(Staff) Anda mendapatkan Bonus sebesar Rp.1.000.000\n\n");
    
    } else if(Staff < lamaBekerja) {
        printf("(Staff) Anda mendapatkan Bonus sebesar Rp.500.000\n\n");

    } else if(umurStaff < 50) {
        printf("(Staff) Anda mendapatkan Bonus sebesar Rp.300.000\n\n");
    }


    if(nonStaff > lamaBekerja) {
        printf("(nonStaff) Anda mendapatkan Bonus sebesar Rp.400.000\n\n");
    
    } else if(umurNonStaff < 50) {
        printf("(nonStaff) Anda mendapatkan Bonus Rp.250.000\n\n");
    }
    

    else {
        printf("Error\n\n");
    }

    return 0;
}

