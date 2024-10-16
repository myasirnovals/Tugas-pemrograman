/*
	Program		: bTree.h
	Author		: 2350081062, Aji Kartiko Hartanto
	Kelas		: C
	Deskripsi	: Header file dari prototype binary tree
	Tanggal		: 12 - 06 - 2024
*/

// preprosesor
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>

/* Deklarasi Btree */
#define nil NULL
#define info(P) (P)->info
#define left(P) (P)->left
#define right(P) (P)->right

//pembentukan tipe BTree
typedef struct tNode *address;
typedef struct tNode{
 int info;
 address left;
 address right;
 }Node;
typedef address Tree;

//prototype BinTree
//Kelompok konstruktor
void CreateTree(Tree *T, int x, Tree L, Tree R);
/*
	I.S : T terdefinisi sembarang
	F.S : menghasilkan sebuah pohon T
 			menghasilkan sebuah pohon T dari x, L, R jika alokasi berhasil,
			menghasilkan pohon T = nil jika alokasi gagal
*/

address Alokasi(int X);
/* mengirim sebuah address dari x berupa node */

void DeAlokasi(address P);
/* merelease memori bernilai P */


//Kelompok selektor
int getRoot(Tree T);
/* mengirim nilai root pada T */

Tree getLeft(Tree T);
/* mengirim anak kiri dari T */

Tree getRight(Tree T);
/* mengirim anak kanan dari T */

int TinggiPohon(Tree T);
/* mengirim tinggi pohon, pohon kosong = O */

int Maksimum(int Kiri, int Kanan);
/* mengirim nilai terbesar dari Kiri atau Kanan */


//Operasi I/O
Tree InsSearch(Tree T, int x);
/* menghasilkan sebuah pohon dengan nilai X */

void CetakTree(Tree T);
/*
	I.S : T terdifinisi sembarang tidak kosong
	F.S : semua simpul dari T tercetak
*/ 

void PreOrder(Tree T);
/*
	I.S : T terdefinisi sembarang
	F.S : semua simpul T diproses secara preorder :
 			akar — kiri — kanan
*/

void InOrder(Tree T);
/*
	I.S : T terdefinisi sembarang
	F.S : semua simpul T diproses secara inorder :
 			kiri — akar — kanan
*/

void PostOrder(Tree T);
/*
	I.S : T terdefinisi sembarang
	F.S : semua simpul T diproses secara postorder 2
 			kiri — kanan — akar
*/ 

