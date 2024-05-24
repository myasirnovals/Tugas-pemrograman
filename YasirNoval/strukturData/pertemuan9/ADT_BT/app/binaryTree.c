/**
 * Program: boolean.h
 * Author: (2350081004, Muhamad Yasir Noval)
 * Kelas: A
 * Deskripsi: Header file dari prototype boolean
 * Tanggal: -
 */

#include "../lib/binaryTree.h"

void createTree(Tree *T, int X, Tree L, Tree R) {
    (*T) = Alokasi(X);
    if ((*T) != Nil) {
        left((*T)) = L;
        right((*T)) = R;
    }
}

address Alokasi(int X) {
    address P;

    P = (address) malloc(sizeof(Node));
    if (P != Nil) {
        info(P) = X;
        left(P) = Nil;
        right(P) = Nil;
    }

    return (P);
}

void DeAlokasi(address P) {
    free(P);
}

int getRoot(Tree T) {
    return info(T);
}

Tree getLeft(Tree L) {
    return left(L);
}

Tree getRight(Tree R) {
    return right(R);
}

int TinggiPohon(Tree T) {
    int tinggi;

    tinggi = 0;
    if (T != Nil) {
        tinggi = 1 + Maksimum(TinggiPohon(left(T)), TinggiPohon(right(T)));
    }
    return (tinggi);
}

int Maksimum(int Kiri, int Kanan) {
    if (Kiri > Kanan) {
        return (Kiri);
    } else {
        return (Kanan);
    }
}

Tree inSearch(Tree T, int X) {
    if (T == Nil) {
        createTree(&T, X, Nil, Nil);
    } else if (X < info(T)) {
        left(T) = inSearch(left(T), X);
    } else {
        right(T) = inSearch(right(T), X);
    }

    return (T);
}

void cetakTree(Tree T) {
    if (T != Nil) {
        printf("%d ", info(T));
    }
}

void preOrder(Tree T) {
    if (T != Nil) {
        cetakTree(T);
        preOrder(left(T));
        preOrder(right(T));
    }
}

void inOrder(Tree T) {
    if (T != Nil) {
        preOrder(left(T));
        cetakTree(T);
        preOrder(right(T));
    }
}

void postOrder(Tree T) {
    if (T != Nil) {
        preOrder(left(T));
        preOrder(right(T));
        cetakTree(T);
    }
}