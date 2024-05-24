/*
    Program: btree.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Memasukan instruksi yang akan dieksekusi didalam fungsi dan prosedur
    Tanggal: 05/04/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

void createTree(Tree *T, int X, Tree L, Tree R) {
    (*T) = Alokasi(X);
    if((*T) != Nil) {
        left((*T)) = L;
        right((*T)) = R;
    }
}

address Alokasi(int X) {
    address P;

    P = (address) malloc(sizeof(Node));
    if(P != Nil) {
        info(P) = X;
        left(P) = Nil;
        right(P) = Nil;
    }

    return (P);
}

void DeAlokasi(address P) {
    free(P);
}

int getRoot(Tree T);
Tree getLeft(Tree L);
Tree getRight(Tree R);

int TinggiPohon(Tree T) {
    int tinggi;

    tinggi = 0;
    if(T != Nil) {
        tinggi = 1 + Maksimum(TinggiPohon(left(T)), TinggiPohon(right(T)));
    }
    return (tinggi);
}

int Maksimum(int Kiri, int Kanan) {
    if(Kiri > Kanan) {
        return (Kiri);
    } else {
        return (Kanan);
    }
}

Tree inSearch(Tree T, int X) {
    if(T == Nil) {
        createTree(&T, X, Nil, Nil);
    } else if(X < info(T)) {
        left(T) = inSearch(left(T), X);
    } else {
        right(T) = inSearch(right(T), X);
    }

    return (T);
}

void cetakTree(Tree T) {
    if(T != Nil) {
        printf("%d ", info(T));
    }
}

void preOrder(Tree T) {
    if(T != Nil) {
        cetakTree(T);
        preOrder(left(T));
        preOrder(right(T));
    }
}

void inOrder(Tree T) {
    if(T != Nil) {
        preOrder(left(T));
        cetakTree(T);
        preOrder(right(T));
    }
}

void postOrder(Tree T) {
    if(T != Nil) {
        preOrder(left(T));
        preOrder(right(T));
        cetakTree(T);
    }
}