/*
    Program: mqueueCircular.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Program utama yang menjalankan ketiga program sebelumnya
    Tanggal: 28/03/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include "queueCircular.c"

int main() {
    Queue queue;
    infoType elemen, info, N;
    boolean status;

    createQueue(&queue);
    setQueue(&queue);

    printf("=========Operator Pengecekan apakah Queue kosong atau tidak=========\n");
    if(isEmpty(queue)) {
        printf("Queue masih kosong\n");
    } else {
        printf("Queue tidak kosong\n");
    }

    printf("\n=========Operator tambah queue=========\n");
    printf("Masukan antrian: ");
    scanf("%d", &N);

    while(N != 999) {
        addQueue(&queue, N);
        printf("Masukan antrian: ");
        scanf("%d", &N);
    }
    printf("\n");
    cetakQueue(queue);

    printf("\n=========Operator Pengecekan apakah Queue penuh atau tidak=========\n");
    if(isFull(queue)) {
        printf("Queue sudah penuh\n");
    } else {
        printf("Queue belum penuh\n");
    }

    printf("\n=========Operator tambah queue=========\n");
    printf("Masukan antrian: ");
    scanf("%d", &N);

    while(N != 999) {
        addQueue(&queue, N);
        printf("Masukan antrian: ");
        scanf("%d", &N);
    }
    printf("\n");
    cetakQueue(queue);

    printf("\n=========Operator Hapus queue=========\n");
    deleteQueue(&queue, &elemen);
    cetakQueue(queue);
    printf("\n");
    deleteQueue(&queue, &elemen);
    cetakQueue(queue);

    printf("\n\n=========Operator tambah queue=========\n");
    printf("Masukan antrian: ");
    scanf("%d", &N);

    while(N != 999) {
        addQueue(&queue, N);
        printf("Masukan antrian: ");
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
    printf("\n");

    deleteQueue(&queue, &elemen);
    cetakQueue(queue);
    printf("\n");

    deleteQueue(&queue, &elemen);
    cetakQueue(queue);
    printf("\n");

    deleteQueue(&queue, &elemen);
    cetakQueue(queue);
    printf("\n");

    deleteQueue(&queue, &elemen);
    cetakQueue(queue);
    printf("\n");

    deleteQueue(&queue, &elemen);
    cetakQueue(queue);
    printf("\n");

    deleteQueue(&queue, &elemen);
    cetakQueue(queue);

    printf("\n\n=========Operator menemukan queue apakah ada/tidak=========\n");
    printf("Masukan bilangan: ");
    scanf("%d", &N);

    if(IsKetemu(queue, N)) {
        printf("Elemen %d ada di dalam queue\n", N);
    } else {
        printf("Elemen %d tidak ada di dalam queue\n", N);
    }

    printf("\n=========Operator cari elemen queue=========\n");
    printf("Masukan bilangan: ");
    scanf("%d", &N);

    info = cariElm(queue, N);
    if(info != false) {
        printf("ELemen terdapat pada queue di index ke-%d\n", info);
    } else {
        printf("Elemen tidak teradapat pada queue\n");
    }

    printf("\n=========Operator jumlah queue=========\n");
    printf("Terdapat %d elemen pada queue\n\n", JumElm(queue));

    return 0;
}