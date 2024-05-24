//
// Created by myasi on 12/3/2023.
//

#include <stdio.h>

#define MaxKata 50

typedef struct {
    char TabKata[1 + MaxKata];
    int length;
} Kata;

// prototype
void BacaTulisKata();

int main() {
    BacaTulisKata();

    return 0;
}

void BacaTulisKata() {
    // Kamus lokal
    Kata K;
    int i;
    char Cc;

    // algoritma lokal
    K.length = 0;

    if (Cc == '@') {
        printf("Tidak ada kata yang dibaca");
    } else {
        do {
            K.length = K.length + 1;
            K.TabKata[K.length] = Cc;

            scanf("%s", &Cc);
        } while ((Cc == '@') || (K.length == MaxKata));

        if (Cc != '@') {
            printf("Pembacaan kata dihentikan\n");
        } else {
            printf("Kata yang dibaca adalah : ");
        }

        for (i = 1; i <= K.length; i++) {
            printf("%c\n", K.TabKata[i]);
            printf("Panjang kata: %d\n", K.length);
        }
    }

}