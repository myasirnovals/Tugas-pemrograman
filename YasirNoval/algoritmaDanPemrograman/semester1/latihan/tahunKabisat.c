#include <stdio.h>

int tahun_kabisat(int tahun);

void nextDay(int *hari, int *bulan, int *tahun);

int main() {
    // kamus
    int hari_ini;
    int bulan_ini;
    int tahun_ini;

    // algoritma
    printf("Masukan hari ini: ");
    scanf("%d", &hari_ini);

    printf("Masukan bulan ini: ");
    scanf("%d", &bulan_ini);

    printf("Masukan tahun ini: ");
    scanf("%d", &tahun_ini);

    nextDay(&hari_ini, &bulan_ini, &tahun_ini);

    printf("\nHari selanjutnya: %d\n", hari_ini);
    printf("Bulan selanjutnya: %d\n", bulan_ini);
    printf("Tahun selanjutnya: %d\n", tahun_ini);

    return 0;
}

int tahun_kabisat(int tahun) {
    if (tahun % 4 == 0) {
        if (tahun % 100 == 0) {
            if (tahun % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

void nextDay(int *hari, int *bulan, int *tahun) {
    int hariDalamBulan[] = {
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    if (tahun_kabisat(*tahun)) {
        hariDalamBulan[1] = 29; // mengubah jumlah hari februari menjadi 29 untuk tahun kabisat
    }

    if (*hari < hariDalamBulan[*bulan - 1]) {
        *hari = *hari + 1;
    } else {
        *hari = 1;

        if (*bulan < 12) {
            *bulan = *bulan + 1;
        } else {
            *bulan = 1;
            *tahun = *tahun + 1;
        }
    }
}