/**
 * Program: binaryTree.h
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
#define info(P) (P)->info
#define left(P) (P)->left
#define right(P) (P)->right

typedef struct tNode *address;

typedef struct tNode {
    int info;
    address left;
    address right;
} Node;

typedef address Tree;

void createTree(Tree *T, int X, Tree L, Tree R);

address Alokasi(int X);

void DeAlokasi(address P);

int getRoot(Tree T);

Tree getLeft(Tree L);

Tree getRight(Tree R);

int TinggiPohon(Tree T);

int Maksimum(int Kiri, int Kanan);

Tree inSearch(Tree T, int X);

void cetakTree(Tree T);

void preOrder(Tree T);

void inOrder(Tree T);

void postOrder(Tree T);

#endif //BINARYTREE_H
