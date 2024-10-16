/*
	Program		: mqueuecircular2.c
   	Author		: 2350081062 Aji Kartiko Hartanto
				  2350081064 Jarwo Eddy Wicaksono
				  2350081079 Rifqi Fauzi Anwar
	Kelas		: C
	Deskripsi	: Main Driver File ADT Queue Circular
	Tanggal		: 29 Mei 2024
*/

#include "queuecircular2.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
    Queue MyQueue;
    int N, X, choice, cari;
    boolean found;

    CreateQueue(&MyQueue);
    printf("=====Menu Pilihan======\n");
    printf("1. Add Queue \n");
    printf("2. Delete Queue \n");
    printf("3. Cari Elemen \n");
    printf("0. Keluar \n");
    printf("=======================\n");

    do {
        printf("Silahkan Pilih Menu = ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Masukkan Elemen: ");
                scanf("%d", &N);
                AddQueue(&MyQueue, N);
                CetakQueue(MyQueue);
                PrintQueueData(MyQueue);
                break;
            case 2:
                DelQueue(&MyQueue, &X);
                CetakQueue(MyQueue);
                PrintQueueData(MyQueue);
                break;
            case 3:
                printf("\nMasukkan Elemen Yang Dicari = "); 
                scanf("%d", &cari);
                if (CariElemenQueue(MyQueue, cari)) {
                    printf("Elemen %d ada pada Queue\n", cari);
                } else {
                    printf("Elemen %d tidak ada pada Queue\n", cari);
                }
                break;
            case 0:
                printf("Keluar dari Program \n");
                break;
            default:
                printf("Pilihan tidak ada di Menu \n\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
