/**
 * Program: array_1.c
 * Author: 2350081004/Muhamad Yasir Noval
 * Date: 6 Desember 2023
 * Description: membuat program untuk menginput
 * nama-nama hari menggunakan prosedur Catat Hari
 * kemudian menyimpannya dalam array
 */

#include <conio.h>
#include <stdio.h>
#include <string.h>

// KAMUS global
typedef struct {
    char IsiTabel[10];
} TabString;

void CatatHari(TabString Hari[7], char NamaHari[10], int ke);

int main() {
    // KAMUS lokal di main driver
    TabString MyTabel[10];
    char Hari[10];
    int i;

    // ALGORITMA
    for (i = 1; i <= 7; i++) {
        printf("Masukan Nama Hari ke %d : ", i);
        scanf("%s", &Hari);
        CatatHari(MyTabel, Hari, i);
    }

    for (i = 1; i <= 7; i++) {
        printf("Hari ke %d = %s\n", i, MyTabel[i].IsiTabel);
    }

    return 0;
}

void CatatHari(TabString Hari[7], char NamaHari[10], int ke) {
    strcpy(Hari[ke].IsiTabel, NamaHari);
}