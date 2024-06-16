/*
	Program 	: mqueuecircular.c
	Author 		: 2350081062, Aji Kartiko Hartanto
	Kelas 		: C
	Deskripsi 	: Main Driver dari prototype queue
	Tanggal 	: 29 Mei 2024
*/

#include "queuecircular.h"
#include <stdio.h>

void PrintMenu() {
    printf("===== { MENU PILIHAN } =====\n");
    printf("1. ADD QUEUE\n");
    printf("2. DELETE QUEUE\n");
    printf("3. CARI ELEMEN\n");
    printf("0. QUEUE BERHENTI\n");
}

void PrintQueueState(Queue Q) {
    int i;
	printf("\nELEMEN : ");
    PrintQueueInfo(Q);
    if (!IsQueuekEmpty(Q)) {
        printf("Nilai HEAD : %d\n", InfoHead(Q));
        printf("HEAD berada pada tabel ke %d\n", Head(Q));
        printf("Nilai TAIL : %d\n", InfoTail(Q));
        printf("TAIL berada pada tabel ke %d\n", Tail(Q));
        printf("Banyak antrian : %d\n", NBElmt(Q));

        // Menghitung rata-rata waktu menunggu (jumlah seluruh elemen dibagi dengan jumlah elemen)
        int sum = 0;
        for (i = Head(Q); i != Tail(Q); i = (i % MaxEl) + 1) {
            sum += Q.T[i];
        }
        sum += Q.T[Tail(Q)];
        printf("Waktu rata rata mengantri : %.2f\n", (float)sum / NBElmt(Q));
    }
}

int main() {
    Queue Q;
    CreateQueue(&Q);
    int pilihan;
    infotype elem;

    do {
        PrintMenu();
        printf("Silahkan masukkan pilihan = ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("\nMasukkan elemen : ");
                scanf("%d", &elem);
                if (!IsQueuekFull(Q)) {
                    AddQueue(&Q, elem);
                } else {
                    printf("Queue penuh, tidak dapat menambahkan elemen\n");
                }
                PrintQueueState(Q);
                break;
            case 2:
                if (!IsQueuekEmpty(Q)) {
                    DelQueue(&Q, &elem);
                    printf("\nElemen yang dihapus: %d\n", elem);
                } else {
                    printf("Queue kosong, tidak ada elemen yang dapat dihapus\n");
                }
                PrintQueueState(Q);
                break;
            case 3:
                printf("\nMasukkan elemen yang dicari : ");
                scanf("%d", &elem);
                address idx = CariElemenQueue(Q, elem);
                if (idx != Nil) {
                    printf("Elemen %d ada\n", elem);
                    printf("Ditemukan pada indeks ke %d\n", idx);
                } else {
                    printf("Elemen %d tidak ditemukan\n", elem);
                }
                break;
            case 0:
                printf("Queue berhenti\n");
                break;
            default:
                printf("Pilihan tidak valid\n");
                break;
        }

    } while (pilihan != 0);

    return 0;
}

