/*
	Program		: bTree.c
	Author		: 2350081062, Aji Kartiko Hartanto
	Kelas		: C
	Deskripsi	: Body file dari prototype binary tree
	Tanggal		: 12 - 06 - 2024
*/

#include "bTree.h" 
#include <stdio.h> 
#include <conio.h> 


/* Realisasi dari Prototype binary tree */ 
//Kelompok konstruktor 
void CreateTree(Tree *T, int x, Tree L, Tree R){ 
/* I.S : T terdefinisi sembarang 
 F.S : menghasilkan sebuah pohon T 
 menghasilkan sebuah pohon T dari x, L, R jika alokasi berhasil, 
 menqhasilkan pohon T = nil jika alokasi gagal 
*/ 
	// kamus 
 
	// algoritma 
	*T = Alokasi(x); 
	if(*T != nil){ 
		left(*T) = L; 
		right(*T) = R; 
	} 
} 
address Alokasi(int X){ 
/* mengirim sebuah address dari x berupa node */
	// kamus 
	address P; 
 
	// algoritma 
	P = (address) malloc(sizeof(Node)); 
	if(P!=nil){ 
		info(P) = X; 
		left(P) = nil; 
		right(P) = nil; 
	} 
	return(P); 
} 
void DeAlokasi(address P){ 
/* merelease memori bernilai P */ 
	free(P); 
} 
//Kelompok selektor 
int getRoot(Tree T); 
/* mengirim nilai root pada T */ 
Tree getLeft(Tree T); 
/* mengirim anak kiri dari T */ 
Tree getRight(Tree T); 
/* mengirim anak kanan dari T */ 
int TinggiPohon(Tree T){ 
/* mengirim tinggi pohon, pohon kosong = O */ 
	//kamus 
	int tinggi; 
 
	//algoritma 
	tinggi = 0;
	if(T!=nil){ 
		tinggi = 1 + Maksimum(TinggiPohon(left(T)),TinggiPohon(right(T))); 
	} 
	return(tinggi); 
} 
int Maksimum(int Kiri, int Kanan){ 
/* mengirim nilai terbesar dari Kiri atau Kanan */ 
	//kamus 
	//algoritma 
	if(Kiri > Kanan) 
		return(Kiri); 
	else 
		return(Kanan); 
} 
//Operasi I/O 
Tree InsSearch(Tree T, int x){ 
/* menghasilkan sebuah pohon dengan nilai x */
	//kamus 
	//algoritma 
	if(T == nil) 
		CreateTree(&T,x,nil,nil); 
	else if(x < info(T)) 
		left(T) = InsSearch(left(T), x); 
	else 
		right(T) = InsSearch(right(T), x); 
	return(T); 
} 
void CetakTree(Tree T){ 
/* I.S : T terdifinisi sembarang tidak kosong 
 F.S : semua simpul dari T tercetak 
*/ 
	//kamus 
	//algoritma 
	if(T != nil){ 
		printf("%d", info(T)); 
	} 
} 
void PreOrder(Tree T){ 
/* I.S : T terdefinisi sembarang 
 F.S : semua simpul T diproses secara preorder : 
 akar — kiri — kanan 
*/ 
	//kamus 
	//algoritma 
	if(T!=nil){ 
		CetakTree(T); 
		PreOrder(left(T)); 
		PreOrder(right(T)); 
	}
} 
void InOrder(Tree T){ 
/* I.S : T terdefinisi sembarang 
 F.S : semua simpul T diproses secara inorder : 
 kiri — akar — kanan 
*/ 
	//kamus 
	//algoritma 
	if(T!=nil){ 
		PreOrder(left(T)); 
		CetakTree(T); 
		PreOrder(right(T)); 
	} 
} 
void PostOrder(Tree T){ 
/* I.S : T terdefinisi sembarang
F.S : semua simpul T diproses secara postorder :
 kiri - kanan - akar 
*/ 
	//kamus 
	//algoritma 
	if(T!=nil){ 
		PreOrder(left(T)); 
		PreOrder(right(T)); 
		CetakTree(T); 
	} 
}
