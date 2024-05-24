#include <stdio.h>
#include <stdlib.h>

// Definisikan struktur untuk data murid
struct Murid {
    char nama[50];
    int umur;
    // Anda dapat menambahkan lebih banyak informasi murid sesuai kebutuhan
};

int main() {
    // kamus
    int jumlahKelas, i, j;

    // algoritma
    // Tentukan jumlah kelas dan jumlah murid per kelas
    jumlahKelas = 5;
    int jumlahMuridPerKelas[] = {30, 40, 50, 60, 70}; // Misalnya, kelas 1: 30 murid, kelas 2: 40 murid, dan seterusnya

    // Alokasikan memori dinamis untuk tabel murid
    struct Murid **kelas = (struct Murid **)malloc(jumlahKelas * sizeof(struct Murid *));
    if (kelas == NULL) {
        fprintf(stderr, "Gagal mengalokasikan memori untuk kelas\n");
        return 1;
    }

    // Inisialisasi data murid untuk setiap kelas
    for (i = 0; i < jumlahKelas; ++i) {
        kelas[i] = (struct Murid *)malloc(jumlahMuridPerKelas[i] * sizeof(struct Murid));
        if (kelas[i] == NULL) {
            fprintf(stderr, "Gagal mengalokasikan memori untuk murid dalam kelas %d\n", i + 1);
            return 1;
        }

        // Isi data murid (contoh: beri nama dan umur acak)
        for (j = 0; j < jumlahMuridPerKelas[i]; ++j) {
            sprintf(kelas[i][j].nama, "Murid-%d-%d", i + 1, j + 1);
            kelas[i][j].umur = 10 + rand() % 10; // Umur antara 10-19 tahun
        }
    }

    // Contoh penggunaan data (tampilkan nama dan umur murid kelas 1)
    printf("Data murid kelas 1:\n");
    for (i = 0; i < jumlahMuridPerKelas[0]; ++i) {
        printf("Nama: %s, Umur: %d tahun\n", kelas[0][i].nama, kelas[0][i].umur);
    }

    // Dealokasikan memori setelah selesai digunakan
    for (i = 0; i < jumlahKelas; ++i) {
        free(kelas[i]);
    }
    free(kelas);

    return 0;
}
