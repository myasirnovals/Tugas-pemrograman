/**
 * Program: boolean.h
 * Author: (2350081004, Muhamad Yasir Noval)
 * Kelas: A
 * Deskripsi: Header file dari prototype boolean
 * Tanggal: -
 */

#include "../lib/binaryTree.h"

void createTree(Tree *T, infoType X, Tree L, Tree R, Tree P) {
    // kamus
    address rootNode;

    // algoritma
    rootNode = *T;

    if (rootNode != Nil) {
        printf("\nTree sudah dibuat\n");
    } else {
        rootNode = Alokasi(X);

        Info(rootNode) = X;
        Left(rootNode) = L;
        Right(rootNode) = R;
        Parent(rootNode) = P;
    }
}

Tree *inserLeft(Tree *T, infoType X) {
    // kamus
    address rootNode, newNode;

    // algoritma
    rootNode = *T;

    if (rootNode == Nil) {
        printf("\nTree belum dibuat\n");
        return Nil;
    } else {
        if (Left(rootNode) != Nil) {
            printf("\nNode untuk anak kiri sudah ada\n");
            return Nil;
        } else {
            newNode = Alokasi(X);

            Info(newNode) = X;
            Left(newNode) = Nil;
            Right(newNode) = Nil;
            Parent(newNode) = rootNode;

            Left(rootNode) = newNode;

            return newNode;
        }
    }
}

address Alokasi(infoType X) {
    // kamus
    address newNode;

    // alokasi
    newNode = (Node *) malloc(sizeof(Node));

    // algoritma
    Info(newNode) = X;
    Left(newNode) = Nil;
    Parent(newNode) = Nil;
    Right(newNode) = Nil;

    return newNode;
}

void DeAlokasi(address P) {
    free(P);
}

infoType getRoot(Tree T) {
    return Info(T);
}

Tree getLeft(Tree L) {
    return Left(L);
}

Tree getRight(Tree R) {
    return Right(R);
}


// infoType TinggiPohon(Tree T) {
//     infoType tinggi;
//
//     tinggi = 0;
//     if (Root(T) != Nil) {
//         tinggi = 1 + Maksimum(TinggiPohon(T), TinggiPohon(Right(T)));
//     }
//     return (tinggi);
// }
//
// infoType Maksimum(infoType Kiri, infoType Kanan) {
//     if (Kiri > Kanan) {
//         return (Kiri);
//     } else {
//         return (Kanan);
//     }
// }
//
// Tree inSearch(Tree T, infoType X) {
//     if (T == Nil) {
//         createTree(&T, X, Nil, Nil);
//     } else if (X < Info(T)) {
//         Left(T) = inSearch(Left(T), X);
//     } else {
//         Right(T) = inSearch(Right(T), X);
//     }
//
//     return (T);
// }

void cetakTree(Tree T) {
    if (Root(T) != Nil) {
        printf("%d ", Info(Root(T)));
    }
}

// void preOrder(Tree T) {
//     if (Root(T) != Nil) {
//         cetakTree(T);
//         preOrder(Left(Root(T)));
//         preOrder(Right(T));
//     }
// }
//
// void inOrder(Tree T) {
//     if (T != Nil) {
//         preOrder(Left(T));
//         cetakTree(T);
//         preOrder(Right(T));
//     }
// }
//
// void postOrder(Tree T) {
//     if (T != Nil) {
//         preOrder(Left(T));
//         preOrder(Right(T));
//         cetakTree(T);
//     }
// }
