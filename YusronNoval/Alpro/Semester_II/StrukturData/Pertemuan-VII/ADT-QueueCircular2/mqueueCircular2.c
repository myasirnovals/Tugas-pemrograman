/*
    Program: mqueueCircular2.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Program utama yang menjalankan ketiga program sebelumnya
    Tanggal: 09/04/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include "queueCircular2.c"

int main() {
    Queue queue;
    infoType elemen, info, N;
    boolean result;

    createQueue(&queue);

    printf("=========Operator Pengecekan apakah Queue kosong atau tidak=========\n");
    if(isEmpty(queue)) {
        printf("Queue masih kosong\n");
    } else {
        printf("Queue tidak kosong\n");
    }

    printf("\n=========Operator tambah queue=========\n");
    printf("Masukan bilangan: ");
    scanf("%d", &N);

    while(N != 999) {
        addQueue(&queue, N);
        printf("Masukan bilangan: ");
        scanf("%d", &N);
    }
    printf("\n");
    cetakQueue(queue);

    printf("\n\n=========Operator Hapus queue=========\n");
    deleteQueue(&queue, &elemen);
    cetakQueue(queue);
    printf("\n");

    deleteQueue(&queue, &elemen);
    cetakQueue(queue);

     printf("\n\n=========Operator cari elemen queue=========\n");
     printf("Masukan bilangan: ");
     scanf("%d", &info);

     result = cariElm(queue, info);
     if(result != false) {
        printf("Elemen %d ada di queue", info);
     } else {
        printf("Elemen tidak ada di queue");
     }
     printf("\n\n");

    return 0;
}