/**
 * Program: main.c
 * Author: (2350081004, Muhamad Yasir Noval)
 *         (2350081028, Ricky Gunaldo)
 *         (2350081011, M Abhinaya Rakan A)
 * Kelas: A
 * Deskripsi: main driver dari stack
 * Tanggal: 10 Mei 2024
 */

#include "app/stack2.c"

int main() {
    Stack stack;
    infoType tmp;

    // membuat stack
    CreateStack(&stack);

    // mengecek apakah stack masih kosong
    printf("Apakah stack kosong?\n");
    if (IsStackEmpty(stack)) {
        printf("Stack masih kosong");
    } else {
        printf("Stack tidak kosong");
    }

    // menambah stack
    printf("\n\n");
    printf("Menambah stack");
    Push(&stack, 1);
    Push(&stack, 2);
    Push(&stack, 3);
    Push(&stack, 4);

    // cetak stack
    printf("\n");
    CetakStack(stack);

    // menghapus stack
    printf("\n\n");
    printf("Menghapus stack");
    Pop(&stack, &tmp);
    Pop(&stack, &tmp);

    // cetak stack
    printf("\n");
    CetakStack(stack);

    // apakah elemen ada di stack
    printf("\n\n");
    if (CariElemenStack(stack, 2)) {
        printf("Elemen terdapat pada stack");
    } else {
        printf("Elemen tidak terdapat pada stack");
    }

    return 0;
}
