/*
	Nama: Aji Kartiko Hartanto
	Nim: 2350081062
	Kelas: C
	1-Des-2023
*/

#include <stdio.h>
#include <stdlib.h>

/* File : struk2.c */
/* contoh pendefinisian dan pengisian struktur yang mengandung string */
int main() {
    struct {
        char *nama;
        char *nim;
        int nilai;
    } Mhs;

    /* alokasi */
    printf("\nNama = ");
    Mhs.nama = (char *) malloc(20 * sizeof(char));
    gets(Mhs.nama);

    printf("\nNIM = ");
    Mhs.nim = (char *) malloc(20 * sizeof(char));
    gets(Mhs.nim);

    printf("\nNilai = ");
    scanf("%d", &Mhs.nilai);

    printf("\nHasil assignment thd Mhs \n");
    printf("Nama = %s\nNim = %s\nNilai = %d\n", Mhs.nama, Mhs.nim, Mhs.nilai);

    return 0;
}
