/* Program 		:  stack2.h
   Author		:  2350081062 Aji Kartiko Hartanto
				   2350081064 Jarwo Eddy Wicaksono
				   2350081079 Rifqi Fauzi Anwar
   Kelas		:  C
   Deskripsi	:  Header File ADT Stack List
   Tanggal  	:  15 Mei 2024
*/ 
#ifndef _STACK2_H
#define _STACK2_H
#include "boolean.h"
#include <stdio.h>
#include <conio.h>

//Pendefinisian Pointer
#define nil NULL
#define next(P) (P)->next
#define info(P) (P)->info
#define TOP(S) (S).TOP

//Pendefinisian tipe Stack
typedef int infotype; /* ELemen Stack bertipe integer */
typedef struct tElmStack *address;

typedef struct tElmStack{
	infotype info;
	address next;
} ElmStack;
typedef struct{
	address BOTTOM;
	address TOP;
} Stack;

// Prototype Stack/primitif Stack Pointer
// Konstruktor
void CreateStack(Stack *S);
/*	I.S.	: S terdefinisi tidak diketahui isinya
	F.S.	: S diinisialisasi dengan TOP(S) = nil 
*/
address Alokasi(infotype x);
/* Mengirim sebuah elemen Stack dalam bentuk address */

//Destruktor
void Dealokasi(address P);
/* Me-release memori dari P sebuah elemen Stack*/

//Operasi Stack
void Push(Stack *S, infotype X);
/* Menambahkan X sebagai elemen Stack S */
/* I.S.	: S terdefinisi, mungkin kosong, dan
		  S penampung elemen stack tidak penuh
   F.S.	: X menjadi TOP yang baru, TOP bertambah 1 
*/

void Pop(Stack *S, infotype *X);
// Menghapus X dari Stack S
/* I.S. : S terdefinisi, tidak kosong
   F.S.	: Mengambil elemen pada Top sehingga X berisi nilai elemen TOP
	      yang lama, kemudian TOP berkurang 1 
*/

void CetakStack(Stack S);
/* I.S.    : S terdefinisi sembarang, tidak kosong
   F.S.    : Menampilkan semua elemen S ke layar 
*/

boolean IsStackEmpty(Stack S);
// Mengecek apakah Stack tidak memiliki elemen
// Mengirim true jika S kosong, false sebaliknya 

boolean CariElemenStack(Stack S, infotype x);
/* Mengirim true jika x ditemukan pada S, false jika tidak ditemukan 
   skema pencarian dengan search dengan boolean
*/

#endif
