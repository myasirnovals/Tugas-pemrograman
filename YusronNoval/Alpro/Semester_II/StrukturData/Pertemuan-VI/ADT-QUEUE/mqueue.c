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
    Queue myTab;
    address ElmQueue;

    createQueue(&myTab);

    printf("Elemen pada Queue: %d\n", JumElm(myTab));

    printf("\n=========Operator Pengecekan apakah Queue kosong atau tidak=========\n");
    if(IsQueueEmpty(myTab)) {
        printf("Queue Kosong\n");
        cetakQueue(myTab);
        printf("\n");

    } else {
        printf("Queue tidak kosong\n");
        cetakQueue(myTab);
        printf("\n");
    }

    printf("\n=========Operator menambahkan Elemen=========\n");
    addQueue(&myTab, Elemen(3));
    addQueue(&myTab, Elemen(11));
    addQueue(&myTab, Elemen(13));

    printf("Elemen pada Queue: %d\n", JumElm(myTab));
    cetakQueue(myTab);
    printf("\n");

    printf("\n=========Operator Pengecekan apakah Queue penuh atau tidak=========\n");
    if(IsQueueFull(myTab)) {
        printf("Queue sudah penuh\n");
    } else {
        printf("Queue masih tersedia\n");
    }

    addQueue(&myTab, Elemen(5));
    addQueue(&myTab, Elemen(7));
    addQueue(&myTab, Elemen(9));

    printf("\n");
    cetakQueue(myTab);
    printf("\n");

    printf("\n=========Operator Menemukan Elemen Queue=========\n");
    if(IsKetemu(myTab, Elemen(11))) {
        printf("Elemen pada Queue ketemu\n");
    } else {
        printf("Elemen pada Queue tidak ketemu\n");
    }

    printf("\n=========Operator Penghapusan Elemen Queue=========\n");
    deleteQueue(&myTab, Elemen(77));
    printf("\n");

    deleteQueue(&myTab, Elemen(7));
    printf("\n");

    deleteQueue(&myTab, Elemen(3));
    printf("\n");

    cetakQueue(myTab);
    printf("\n");

    printf("\n=========Operator Mencari Elemen Queue=========\n");
    ElmQueue = cariElmQueue(myTab, Elemen(13));

    if(ElmQueue != false) {
        printf("Elemen terdapat di address %d\n\n", ElmQueue);
    } else {
        printf("Elemen tidak ditemukan\n\n");
    }

    return 0;
}