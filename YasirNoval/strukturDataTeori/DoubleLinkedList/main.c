/**
 * Program: main.c
 * Author: kelompok
 * Kelas: A
 * Deskripsi: main program dari Adt double linked list
 * Tanggal: -
 */

#include "view/menu.c"

int main() {
    // kamus
    List MyList;
    infoType menu;
    boolean selesai;

    // algoritma
    CreateList(&MyList);

    selesai = tidak;
    do {
    kembali:
        printf("\n");
        printf("\t===== MENU UTAMA =====\t\n");
        printf("1. Sisip Data\n");
        printf("2. Hapus Data\n");
        printf("3. Cari Data\n");
        printf("4. Tampil Data\n");
        printf("5. Keluar\n");

        printf("\nPilih menu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                menuSisip(&MyList);
                goto kembali;
                break;
            case 2:
                menuHapus(&MyList);
                goto kembali;
                break;
            case 3:
                menuCari(&MyList);
                goto kembali;
                break;
            case 4:
                printf("\n");
                CetakList(MyList);
                printf("\n");
                goto kembali;
                break;
            case 5:
                printf("\n");
                member();
                break;
            default:
                printf("\nPilihan anda tidak diketahui\n");
                goto kembali;
        }
    } while (selesai);

    return 0;
}
