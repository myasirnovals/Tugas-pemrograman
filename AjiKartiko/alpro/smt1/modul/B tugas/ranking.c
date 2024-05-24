#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;

    // Input tiga bilangan integer
    printf("NAMA: Aji \n");
    printf("NIM: 2350081062\n");
    
    printf("Masukkan nilai a: ");
    scanf("%d", &a);
    printf("Masukkan nilai b: ");
    scanf("%d", &b);
    printf("Masukkan nilai c: ");
    scanf("%d", &c);

    // Proses pengurutan
    if (a < b) {
        if (b < c) {
            printf("Urutan terkecil ke terbesar: %d, %d, %d\n", a, b, c);
        } else { // b > c
            if (c > a) {
                printf("Urutan terkecil ke terbesar: %d, %d, %d\n", a, c, b);
            } else { // c < a
                printf("Urutan terkecil ke terbesar: %d, %d, %d\n", c, a, b);
            }
        }
    } else { // a > b
        if (a < c) {
            printf("Urutan terkecil ke terbesar: %d, %d, %d\n", b, a, c);
        } else { // a > c
            if (b < c) {
                printf("Urutan terkecil ke terbesar: %d, %d, %d\n", b, c, a);
            } else { // b > c
                printf("Urutan terkecil ke terbesar: %d, %d, %d\n", c, b, a);
            }
        }
    }
    return 0;
}
