//
// Created by myasi on 11/30/2023.
//

#include <stdio.h>
#include <string.h>
#include <conio.h>

void IsiTabHari(int hariKe);

int main() {
    // kamus
    int i;

    printf("Masukan hari ke = ");
    scanf("%d", &i);

    if (i <= 0 || i > 7) {
        printf("Hari tidak ada");
    } else {
        IsiTabHari(i);
    }


    return 0;
}

void IsiTabHari(int namaHari) {
    // kamus lokal

    // algoritma lokal
    char TabelNamaHari[8][10] = {
            "",
            "Senin",
            "Selasa",
            "Rabu",
            "Kamis",
            "Jum'at",
            "Sabtu",
            "Minggu"
    };

    printf("%s", TabelNamaHari[namaHari]);
}