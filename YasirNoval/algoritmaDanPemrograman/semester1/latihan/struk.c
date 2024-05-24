//
// Created by myasi on 11/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
contoh pendefinisian
dan pengisian
struktur: titik, mhs, meter */

int main() {
    //KAMUS
    /* cara 1 */
    struct {
        char nama[20];
        int nim;
        int nilai;
    } Mhs; /* nama variabel berupa struct */

    /* cara 2 */
    struct meter/* tag, untuk menyebut struct... */ {
        int m;
        int cm;
    };
    struct meter M1; /* M1 adalah variabel */

    /* cara 3: INI yang membuat TYPE BARU */
    typedef struct {
        float x;
        float y;
    } Point; /* nama type */
    Point P1;
    Point *P2; /* pointerke struct, akan dibahas pada pointer */
    Point P3; /* latihan baca */

    //ALGORITMA
    printf("contoh mengisi struktur dengan assignment: \n");
    printf("Titik P1, dengan P1.x dan P1.y: \n");
    P1.x = 1.1;
    P1.y = 2.5;
    printf("P1.x = %4.1f \nP1.y = %4.1f \n", P1.x, P1.y);

    /* mengacu pointer ke struct, akan dibahas setelah pointer */
    printf("Titik P2, dengan P2->x dan P2->y : \n");
    P2 = (Point *) malloc(sizeof(Point));
    P2->x = 9.12;
    P2->y = 2.567;
    printf("P2.x = %f \nP2.y = %f\n", P2->x, P2->y);

    printf("Baca Titik P3 \n");
    scanf("%f %f", &P3.x, &P3.y);
    printf("P3.x = %f \nP3.y = %f \n", P3.x, P3.y);

    strcpy(Mhs.nama, "aji");
    Mhs.nim = 2350081062;
    Mhs.nilai = 80;

    printf("Hasil assignment thd Mhs \n");
    printf("Nama = %s \nNim = %d \nNilai = %d \n", Mhs.nama, Mhs.nim, Mhs.nilai);

    return 0;
}