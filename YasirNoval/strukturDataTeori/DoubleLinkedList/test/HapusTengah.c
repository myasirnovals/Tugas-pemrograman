//
// Created by myasi on 5/21/2024.
//
#include "../lib/doubleLinkedList.h"

void HapusTengah(List *L, infoType *X, infoType position) {
    // kamus
    address delNode, current, after, before;
    boolean ketemu;

    // algoritma
    current = First(*L);

    ketemu = tidak;
    while (Next(current) != Nil && !ketemu) {
        if (Info(current) == position) {
            delNode = current;
            before = Prev(delNode);

            if (Prev(current) != Nil) {
                after = Next(delNode);

                // proses penghapusan
                *X = Info(delNode);

                Next(before) = after;
                Prev(after) = before;

                Prev(delNode) = Nil;
                Next(delNode) = Nil;

                Dealokasi(delNode);

                ketemu = ya;
            } else {


                ketemu = ya;
            }
        }

        current = Next(current);
    }

    if (Next(current) == Nil && Info(current) == position) {
        HapusBelakang(L, X);

        ketemu = ya;
    } else if (ketemu == false){
        printf("\nError: data tidak ditemukan\n");
    }
}