#include <stdio.h>

int main() {
    int a, b, c;

    // Membaca tiga bilangan
    printf("Masukkan nilai a: ");
    scanf("%d", &a);
    printf("Masukkan nilai b: ");
    scanf("%d", &b);
    printf("Masukkan nilai c: ");
    scanf("%d", &c);

    // Melakukan perbandingan dan mencetak hasil sesuai dengan aturan
    if (a < b && b < c) {
        printf("Urutan harga: %d, %d, %d\n", a, b, c);
    } else if (a < c && c < b) {
        printf("Urutan harga: %d, %d, %d\n", a, c, b);
    } else if (b < a && a < c) {
        printf("Urutan harga: %d, %d, %d\n", b, a, c);
    } else if (b < c && c < a) {
        printf("Urutan harga: %d, %d, %d\n", b, c, a);
    } else if (c < a && a < b) {
        printf("Urutan harga: %d, %d, %d\n", c, a, b);
    } else if (c < b && b < a) {
        printf("Urutan harga: %d, %d, %d\n", c, b, a);
    }

    return 0;
}
