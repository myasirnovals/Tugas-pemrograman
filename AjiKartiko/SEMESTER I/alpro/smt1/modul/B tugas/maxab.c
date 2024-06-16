#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;

    // Input dua buah harga a dan b
    printf("NAMA: Aji Kartiko Hartanto\n");
    printf("NIM: 2350081062\n");
    printf("Masukkan nilai a: ");
    scanf("%d", &a);
    printf("Masukkan nilai b: ");
    scanf("%d", &b);

    // ALGORITMA
    if (a >= b) {
        // Menuliskan a jika a lebih besar atau sama dengan b
        printf("Harga yang lebih besar: %d\n", a);
    } else {
        // Menuliskan b jika b lebih besar dari a
        printf("Harga yang lebih besar: %d\n", b);
    }

    return 0;
}
