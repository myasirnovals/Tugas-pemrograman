//
// Created by myasi on 5/21/2024.
//

#include "../app/doubleLinkedList.c"

void menuSisip(List *L) {
    // kamus
    infoType menu, x, elemen;
    boolean selesai;

    // algoritma
    do {
    kembali:
        printf("\n\n");
        printf("\t===== MENU SISIP =====\t\n");
        printf("1. Sisip Depan\n");
        printf("2. Sisip Tengah\n");
        printf("3. Sisip Belakang\n");
        printf("4. Kembali ke Menu Utama\n");

        printf("\nPilih menu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("Masukan data: ");
                scanf("%d", &x);
                SisipDepan(L, x);
                goto kembali;
                break;
            case 2:
                printf("Masukan data: ");
                scanf("%d", &x);

                printf("\n");
                CetakList(*L);
                printf("\n");

                printf("ingin disisipkan setelah elemen: ");
                scanf("%d", &elemen);

                SisipTengah(L, x, elemen);

                goto kembali;
                break;
            case 3:
                printf("Masukan data: ");
                scanf("%d", &x);
                SisipBelakang(L, x);
                goto kembali;
                break;
            case 4:
                break;
            default:
                printf("\nPilihan anda tidak diketahui\n");
                goto kembali;
        }
    } while (selesai);
}


void menuHapus(List *L) {
    // kamus
    infoType menu, Tmp, position;
    boolean selesai;

    // algoritma
    do {
    kembali:
        printf("\n\n");
        printf("\t===== MENU HAPUS =====\t\n");
        printf("1. Hapus Depan\n");
        printf("2. Hapus Tengah\n");
        printf("3. Hapus Belakang\n");
        printf("4. Kembali ke Menu Utama\n");

        printf("\nPilih menu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                HapusDepan(L, &Tmp);
                if (Tmp != 0) {
                    printf("Penghapusan berhasil");
                }
                goto kembali;
            case 2:
                printf("\n");
                CetakList(*L);
                printf("\n");
                printf("Jumlah Node: %d\n", jumlahElemen(*L));
                printf("Ingin menghapus node di posisi ke: ");
                scanf("%d", &position);
                HapusTengah(L, &Tmp, position);
                goto kembali;
            case 3:
                HapusBelakang(L, &Tmp);
                if (Tmp != 0) {
                    printf("Penghapusan berhasil");
                }
                goto kembali;
            case 4:
                break;
            default:
                printf("\nPilihan anda tidak diketahui\n");
                goto kembali;
        }
    } while (selesai);
}

void menuCari(List *L) {
    // kamus
    infoType menu, elemen;
    address alamat;
    boolean selesai;

    // algoritma
    do {
    kembali:
        printf("\n\n");
        printf("\t===== MENU CARI =====\t\n");
        printf("1. Cari Elemen\n");
        printf("2. Kembali ke Menu Utama\n");

        printf("\nPilih menu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n");
                CetakList(*L);
                printf("\n");

                printf("Masukan elemen yang ingin dicari: ");
                scanf("%d", &elemen);

                alamat = CariElm(*L, elemen);

                if (alamat != Nil) {
                    printf("Elemen yang anda cari terdapat di alamat %p", alamat);
                } else {
                    printf("Error: Element yang anda cari tidak ada dialamat mana pun.");
                    printf("\nError: address undefined: %p", alamat);
                }
                goto kembali;
            case 2:
                break;
            default:
                printf("\nPilihan anda tidak diketahui\n");
                goto kembali;
        }
    } while (selesai);
}

void member() {
    printf("Terimakasih telah menggunakan aplikasi\n");
    printf("Anggota kelompok: \n");
    printf("1. Muhamad Yasir Noval\t\t\t2350081004\n");
    printf("2. Ricky Gunaldo\t\t\t2350081028\n");
    printf("3. Muhammad Abhinaya Rakan Abarra\t2350081011\n");
}
