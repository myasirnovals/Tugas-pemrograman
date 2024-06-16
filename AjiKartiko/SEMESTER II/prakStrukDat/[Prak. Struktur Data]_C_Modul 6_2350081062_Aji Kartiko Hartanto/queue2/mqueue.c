/*
    Program     : mqueue2.c
    Author      : 2350081062, Aji Kartiko Hartanto
    Kelas       : C
    Deskripsi   : Main driver dari prototype queue
    Tanggal     : 23 Mein 2024
 */

#include "queue.c"

int main() {
    // Kamus
    Queue queue;
    infotype elemen, info;

    // Algoritma
    CreateQueue(&queue);

    // cek apakah queue kosong
    printf("Apakah queue kosong?\n");
    if (IsQueueEmpty(queue)) {
        printf("Queue masih kosong");
    } else {
        printf("Queue tidak kosong");
    }

    // Menambahkan queue
    printf("\n\n");
    printf("Menambah queue");
    AddQueue(&queue, 1);
    AddQueue(&queue, 2);
    AddQueue(&queue, 3);
    AddQueue(&queue, 4);
    AddQueue(&queue, 5);

    // cetak queue
    printf("\n");
    PrintQueueInfo(queue);

    // cek apakah queue penuh
    printf("\n\n");
    if (IsQueueFull(queue)) {
        printf("Queue penuh");
    } else {
        printf("Queue belum penuh");
    }

    // Menambahkan queue
    printf("\n\n");
    printf("Menambah queue");
    AddQueue(&queue, 6);
    AddQueue(&queue, 7);

    // cetak queue
    printf("\n");
    PrintQueueInfo(queue);

    // Menghapus queue
    printf("\n\n");
    printf("Menghapus queue");
    DelQueue(&queue, &elemen);

    // cetak queue
    printf("\n");
    PrintQueueInfo(queue);

    // Menghapus queue
    printf("\n\n");
    printf("Menghapus queue");
    DelQueue(&queue, &elemen);

    // cetak queue
    printf("\n");
    PrintQueueInfo(queue);

    // Menghapus queue
    printf("\n\n");
    printf("Menghapus queue");
    DelQueue(&queue, &elemen);

    // cetak queue
    printf("\n");
    PrintQueueInfo(queue);

    // cek apakah x berada pada queue
    printf("\n\n");
    if (isInfoKetemu(queue, 4)) {
        printf("Elemen yang anda masukan terdapat pada queue");
    } else {
        printf("Elemen yang anda masukan tidak terdapat pada queue");
    }

    // mencari elemen x yang terdapat pada queue
    info = CariElemenQueue(queue, 4);

    printf("\n\n");
    if (info != IdxUndef) {
        printf("Elemen terdapat pada queue di index ke-%d", info);
    } else {
        printf("Elemen tidak terdapat pada queue, index %d", info);
    }

    // mengirim banyak elemen pada queue
    printf("\n\n");
    printf("Terdapat %d elemen pada queue", NBElmt(queue));

    return 0;
}