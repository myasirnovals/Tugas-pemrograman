#include <stdio.h>
#include "boolean.h"

#define nMax 12

typedef struct {
    int Tb[nMax + 1][nMax + 1];
    int neff;
} TabNextDay;

// prototype
void CreateTab(TabNextDay *T);

void AddData(TabNextDay *T, int x);

void CetakTab(TabNextDay T);

int tahun_kabisat(int tahun);

void nextDay(int *hari, int *bulan, int *tahun);

int main() {
    // kamus
    TabNextDay MyTab;
    int hari_ini;
    int bulan_ini;
    int tahun_ini;
    int nomorTabel;

    // algoritma
    CreateTab(&MyTab);

    printf("Masukan nomor Tabel: ");
    scanf("%d", &nomorTabel);

    printf("Masukan hari ini: ");
    scanf("%d", &hari_ini);

    printf("Masukan bulan ini: ");
    scanf("%d", &bulan_ini);

    printf("Masukan tahun ini: ");
    scanf("%d", &tahun_ini);

    while (nomorTabel != 999) {
        AddData(&MyTab, nomorTabel);
    }

    nextDay(&hari_ini, &bulan_ini, &tahun_ini);

    printf("Hari selanjutnya: %d\n", hari_ini);
    printf("Bulan selanjutnya: %d\n", bulan_ini);
    printf("Tahun selanjutnya: %d\n", tahun_ini);

    CetakTab(MyTab);

    return 0;
}

void CreateTab(TabNextDay *T) {
    (*T).neff = 0;
}

void AddData(TabNextDay *T, int x) {
    if ((*T).neff < nMax) {
        (*T).neff = (*T).neff + 1;
        (*T).Tb[(*T).neff][(*T).neff] = x;
    }
}

void CetakTab(TabNextDay T) {
    int i, j;

    for (i = 1; i <= T.neff; i++) {
        for (j = 1; j <= T.neff; j++) {
            printf("<%d>", T.Tb[i][j]);
        }
        printf("\n");
    }
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