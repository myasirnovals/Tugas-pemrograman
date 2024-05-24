#include <stdio.h>

// Definisi tipe data Point
typedef struct {
    int abs;
    int ord;
} Point;

// Definisi tipe data TabPoint
typedef struct {
    Point T[100]; // Sesuaikan ukuran array sesuai kebutuhan
    int neft;
} TabPoint;

int main() {
    TabPoint MyTab;
    int i, x, y;

    // Input nilai x dan y sebagai absis dan ordinat
    printf("Masukkan nilai x (absis): ");
    scanf("%d", &x);
    printf("Masukkan nilai y (ordinat): ");
    scanf("%d", &y);

    // Membuat Point P dari nilai absis dan ordinat
    Point P;
    P.abs = x;
    P.ord = y;

    // Menyimpan Point P ke dalam tabel T
    MyTab.T[0] = P;
    MyTab.neft = 1;

    // Menampilkan isi tabel T
    printf("\nIsi Tabel T:\n");
    for (i = 0; i < MyTab.neft; i++) {
        printf("T[%d] - Absis: %d, Ordinat: %d\n", i, MyTab.T[i].abs, MyTab.T[i].ord);
    }

    return 0;
}