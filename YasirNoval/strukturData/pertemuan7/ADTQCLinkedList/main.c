#include "app/queue.c"

int main() {
    Queue queue;
    infoType elemen, info;
    boolean result;

    // membuat queue
    CreateQueue(&queue);

    // mengecek apakah queue masih kosong
    printf("Apkah queue masih kosong? \n");
    if (IsQueueEmpty(queue)) {
        printf("Queue masih kosong");
    } else {
        printf("Queue tidak kosong");
    }

    // menambah data pada queue
    printf("\n\n");
    printf("Menambahkan data pada queue\n");
    AddQueue(&queue, 1);
    AddQueue(&queue, 2);
    AddQueue(&queue, 3);
    AddQueue(&queue, 4);

    // mencetak data queue
    CetakQueue(queue);

    // menhapus data pada queue
    printf("\n\n");
    printf("Menghapus data pada queue\n");
    DelQueue(&queue, &elemen);

    // mencetak data queue
    CetakQueue(queue);
    printf("\n");
    DelQueue(&queue, &elemen);
    CetakQueue(queue);

    // mencari elemen pada queue
    printf("\n\n");
    printf("Masukan elemen yang akan dicari: ");
    scanf("%d", &info);

    printf("\n");
    result = CariElemenQueue(queue, info);
    printf("Apakah elemen %d ada di queue? ", info);

    if (result) {
        printf("Ya");
    } else {
        printf("Tidak");
    }

    return 0;
}
