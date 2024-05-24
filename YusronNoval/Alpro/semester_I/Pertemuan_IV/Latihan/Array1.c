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
    int N, i, x, y;

    // Input jumlah N
    printf("Masukkan jumlah N: ");
    scanf("%d", &N);

    // Meminta input x dan y sebanyak N kali
    for (i = 0; i < N; i++) {
        printf("Masukkan nilai x (absis) ke-%d: ", i + 1);
        scanf("%d", &x);
        printf("Masukkan nilai y (ordinat) ke-%d: ", i + 1);
        scanf("%d", &y);

        // Membuat Point P dari nilai absis dan ordinat
        Point P;
        P.abs = x;
        P.ord = y;

        // Menyimpan Point P ke dalam tabel T
        MyTab.T[i] = P;
    }
    
    // Mengatur nilai neft
    MyTab.neft = N;

    // Menampilkan isi tabel T
    printf("\nIsi Tabel T:\n");
    for (i = 0; i < MyTab.neft; i++) {
        printf("T[%d] - Absis: %d, Ordinat: %d\n", i, MyTab.T[i].abs, MyTab.T[i].ord);
    }

    return 0;
}