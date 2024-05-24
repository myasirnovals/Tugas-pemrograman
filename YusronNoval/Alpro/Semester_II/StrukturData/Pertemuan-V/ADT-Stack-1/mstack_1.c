/*
    Program: mstack_1.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Program utama yang menjalankan ketiga program sebelumnya
    Tanggal: 02/04/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack_1.c"

int main() {
    Stack stack;
    infoType tmp, x;
    address elmen;

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

    printf("\n\n================Opreator pengecekan apakah stack penuh atau tidak================\n");
    if(isFull(stack)) {
        printf("Stack sudah penuh\n");
    } else {
        printf("Stack tidak penuh\n");
    }

    printf("\n\n================Opreator penghapusan elemen================\n");
    Pop(&stack, &tmp);
    Pop(&stack, &tmp);
    cetakStack(stack);

    printf("\n\n================Opreator pencarian elemen dan mengembalikan nilai true/false================\n");
    printf("Masukan bilangan: ");
    scanf("%d", &x);
    if(isKetemu(stack, x)) {
        printf("Elemen %d ada di dalam stack\n", x);
    } else {
        printf("Elemen tidak ditemukan\n");
    }

    printf("\n================Opreator pencarian elemen dan mengembalikan address-nya================\n");
    printf("Masukan bilangan: ");
    scanf("%d", &x);
    elmen = cariElm(stack, x);
    if(elmen != false) {
        printf("Elemen %d terdapat di stack dengan address %d", x, elmen);
    } else {
        printf("Elemen %d tidak terdapat pada stack, address %d", x, false);
    }

    printf("\n\n");

    return 0;
}