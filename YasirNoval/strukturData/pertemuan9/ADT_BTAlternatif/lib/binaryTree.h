/**
 * Program: boolean.h
 * Author: (2350081004, Muhamad Yasir Noval)
 * Kelas: A
 * Deskripsi: Header file dari prototype boolean
 * Tanggal: -
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define Nil NULL
#define Info(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Parent(P) (P)->parent

typedef int infoType;
typedef struct tNode *address;

typedef struct tNode {
    infoType info;
    address left;
    address right;
    address parent;
} Node;

typedef address Tree;

void createTree(Tree *T, infoType X, Tree L, Tree R, Tree P);
// void createTree(Tree *T);

address Alokasi(infoType X);

void DeAlokasi(address P);

infoType getRoot(Tree T);

Tree getLeft(Tree L);

Tree getRight(Tree R);

infoType TinggiPohon(Tree T);

infoType Maksimum(infoType Kiri, infoType Kanan);

Tree inSearch(Tree T, infoType X);

void cetakTree(Tree T);

void preOrder(Tree T);

void inOrder(Tree T);

void postOrder(Tree T);

#endif //BINARYTREE_H