/*
    Program: mstack_2.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Program utama yang menjalankan ketiga program sebelumnya
    Tanggal: 02/04/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack_2.c"

int main() {
    Stack stack;
    infoType tmp, x;

    createStack(&stack);

    printf("================Opreator pengecekan apakah stack kosong atau tidak================\n");
    if(isEmpty(stack)) {
        printf("Stack masih kosong\n");
    } else {
        printf("Stack tidak kosong\n");
    }

    printf("\n================Opreator tambah elemen================\n");
    printf("Masukan bilangan: ");
    scanf("%d", &x);

    while(x != 999) {
        Push(&stack, x);
        printf("Masukan bilangan: ");
        scanf("%d", &x);
    }
    printf("\n");
    cetakStack(stack);

    printf("\n\n================Opreator penghapusan elemen================\n");
    Pop(&stack, &tmp);
    Pop(&stack, &tmp);
    cetakStack(stack);

    printf("\n\n================Opreator pencarian elemen dan mengembalikan nilai true/false================\n");
    printf("Masukan bilangan: ");
    scanf("%d", &x);
    if(cariElm(stack, x)) {
        printf("Elemen %d ada di dalam stack\n", x);
    } else {
        printf("Elemen %d tidak ditemukan\n", x);
    }

    printf("\n\n");

    return 0;
}