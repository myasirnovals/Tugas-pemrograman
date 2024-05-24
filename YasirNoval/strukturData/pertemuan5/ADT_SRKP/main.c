/**
 * Program: main.c
 * Author: (2350081004, Muhamad Yasir Noval)
 * Kelas: A
 * Deskripsi: Main driver dari stack
 * Tanggal: 10 Mei 2024
 */

#include "app/stack.c"

int main() {
    // kamus
    Stack stack;
    infoType tmp, x;
    address Elm;

    //algoritma
    // membuat stack
    CreateStack(&stack);

    // mengecek apakah stack kosong atau tidak
    printf("apakah stack masih kosong?\n");
    if (IsStackEmpty(stack)) {
        printf("Stack masih kosong");
    } else {
        printf("Stack tidak kosong");
    }

    // menambah elemen pada stack
    printf("\n\n");
    printf("Masukan elemen stack: ");
    scanf("%d", &x);

    while (x != 999) {
        Push(&stack, x);
        printf("Masukan elemen stack: ");
        scanf("%d", &x);
    }

    printf("\n\n");
    PrintStackInfo(stack);

    // mengecek apakah stack penuh atau tidak
    printf("\n\n");
    if (IsStackFull(stack)) {
        printf("Stack sudah penuh");
    } else {
        printf("Stack belum penuh");
    }

    // penghapusan pada stack
    printf("\n\n");
    printf("menghapus elemen pada Stack");
    Pop(&stack, &tmp);
    Pop(&stack, &tmp);

    printf("\n\n");
    PrintStackInfo(stack);

    // mecari elemen stack dan mengembalikan true atau false
    printf("\n\n");
    printf("masukan elemen yang akan dicari: ");
    scanf("%d", &x);
    if (IsInfoKetemu(stack, x)) {
        printf("Elemen %d ada di dalam stack", x);
    } else {
        printf("Elemen %d tidak ada di dalam stack", x);
    }

    // mencari elemen pada stack dan mengembalikan nilai address nya
    printf("\n\n");
    printf("masukan elemen yang akan dicari:");
    scanf("%d", &x);
    Elm = CariElemenStack(stack, x);
    if (Elm != IdxUndef) {
        printf("Elemen %d terdapat pada stack dengan index %d", x, Elm);
    } else {
        printf("Elemen %d tidak terdapat pada stack. index %d", x, IdxUndef);
    }

    return 0;
}