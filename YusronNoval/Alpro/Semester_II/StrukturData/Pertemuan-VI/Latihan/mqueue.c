/*
    Program: mqueue.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Program utama yang menjalankan ketiga program sebelumnya
    Tanggal: 28/03/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

int main() {
    // Kamus
    Queue MyTab;
    address ElemenQueue;

    // Algoritma
    CreateQueue(&MyTab);

    printf("Elemen pada Queue: %d\n", NBElmt(MyTab));

    printf("\n");
    if (IsQueueEmpty(MyTab)) {
        printf("Queue Kosong\n");
        PrintQueueInfo(MyTab);
        printf("\n");
    } else {
        printf("Queue tersedia\n");
        PrintQueueInfo(MyTab);
        printf("\n");
    }

    AddQueue(&MyTab, elemen(1));
    AddQueue(&MyTab, elemen(10));
    AddQueue(&MyTab, elemen(12));

    printf("\n");
    printf("Elemen pada Queue: %d\n", NBElmt(MyTab));
    PrintQueueInfo(MyTab);
    printf("\n");

    printf("\n");
    if (IsQueueFull(MyTab)) {
        printf("Queue penuh\n");
    } else {
        printf("Queue Masih tersedia\n");
    }

    AddQueue(&MyTab, elemen(5));
    AddQueue(&MyTab, elemen(8));
    AddQueue(&MyTab, elemen(9));

    printf("\n");
    PrintQueueInfo(MyTab);
    printf("\n");

    printf("\n");
    if (isInfoKetemu(MyTab, elemen(100))) {
        printf("Data pada Queue ketemu\n");
    } else {
        printf("Data pada Queue tidak ketemu\n");
    }

    printf("\n");
    DelQueue(&MyTab, elemen(100));
    printf("\n");

    printf("\n");
    DelQueue(&MyTab, elemen(8));
    printf("\n");

    printf("\n");
    DelQueue(&MyTab, elemen(1));
    printf("\n");

    PrintQueueInfo(MyTab);
    printf("\n");

    ElemenQueue = CariElemenQueue(MyTab, elemen(10));

    printf("\n");
    if (ElemenQueue != IdxUndef) {
        printf("Elemen terdapat di address %d\n", ElemenQueue);
    } else {
        printf("Elemen undefined %d\n", ElemenQueue);
    }

    return 0;
}