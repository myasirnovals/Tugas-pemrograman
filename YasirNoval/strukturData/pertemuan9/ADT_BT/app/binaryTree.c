#include "../lib/binaryTree.h"
void createTree(Tree *T, int X, Tree L, Tree R) {
    *T = Alokasi(X);
    if (*T != Nil) {
        left(*T) = L;
        right(*T) = R;
    }
}
address Alokasi(int X) {
    address newNode;
    newNode = (address) malloc(sizeof(Node));
    if (newNode != Nil) {
        info(newNode) = X;
        left(newNode) = Nil;
        right(newNode) = Nil;
    }
    return newNode;
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
    return tinggi;
}
int Maksimum(int Kiri, int Kanan) {
    if (Kiri > Kanan) {
        return Kiri;
    } else {
        return Kanan;
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
    return T;
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
