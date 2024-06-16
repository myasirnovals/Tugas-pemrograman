/*
	Program 	: queuecircular.h
	Author 		: 2350081062, Aji Kartiko Hartanto
	Kelas 		: C
	Deskripsi 	: Header file dari prototype queue
	Tanggal 	: 29 Mei 2024
*/

#ifndef _QUEUECIRCULAR_H
#define _QUEUECIRCULAR_H
#include "boolean.h"
#include <stdio.h>
#include <conio.h>

#define Nil 0
#define MaxEl 10
/* 	nil adalah queue dengan elemen kosong
	karena indeks dalam bhs C dimulai dari 0 maka tabel dg indeks 0 tidak dipakai */

/* Jika Q adalah Queue maka akses elemen : */
/* Q.T[(Q.HEAD)] untuk mengakses elemen pertama */
/* Q.T[(Q.TAIL)] untuk mengakses elemen terakhir */
/* Q.HEAD adalah alamat elemen pertama */
/* Q.TAIL adalah alamat elemen terakhir */
/* Definisi akses dengan Selektor : Set dan Get */

#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]

/** Definisi ABSTRACT DATA TYPE Tab Integer **/
/* Definisi Queue :
/* Queue kosong: Head=Nil, TAIL=Nil
Atau Head = Tail + 1 untuk alternatif 2
Elemen yang dipakai menyimpan nilai Stack T[l]..T[MaxEl]
Jika Q adalah Queue maka akses elemen
Q.T[(Q.HEAD)] untuk mengakses elemen pertama
Q.T[(Q.TAIL)] untuk mengakses elemen terakhir
Q.HEAD adalah alamat elemen pertama
Q.TAIL adalah alamat elemen terakhir
*/

typedef int infotype; /*elemen queue bertipe integer*/
typedef int address; /* indeks tabel */

/* Versi pembentukan Queue -> dengan menyimpan tabel dan alamat head maupun
tail secara eksplisit */ 

typedef struct { infotype T[MaxEl+1]; /* tabel penyimpan elemen */
 address HEAD; /* alamat HEAD: elemen pertama */
 address TAIL; /* alamat TAIL: elemen terakhir */
 } Queue;

/* Prototype Queue */
/* Konstruktor membentuk Queue */
void CreateQueue(Queue *Q);
/* 	I.S : Q terdefinisi tidak diketahui isinya
	F.S : Q diinisialisasi dengan HEAD(Q)=nil, TAIL(Q)=nil */

/** { Operasi terhadap komponen : selektor Get dan Set } : tidak perlu sudah di define diatas**/
int NBElmt(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */

/* Destruktor/Dealokator: tidak perlu */

/** { KELOMPOK OPERASI pada Queue} **/
/*********** Predikat Untuk test keadaan KOLEKSI **/
boolean IsQueuekEmpty (Queue Q);
/* Mengirim true jika Queue kosong: lihat definisi di atas */

boolean IsQueuekFull(Queue Q);
/* 	Mengirim true jika tabel penampung nilai elemen stack penuh yaitu jumlah 
	elemen sudah mencapa MaxEl : lihat definisi diatas */

int NBElmt(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */

/*********** Menambahkan sebuah elemen ke Queue **********/
void AddQueue (Queue *Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S : Q terdifinisi, mungkin kosong, dan Q penampung elemen queue tidak penuh.
 F.S : F.S. X menjadi TAIL yang baru, TAIL "maju"
 Jika Tail(Q)=MaxE1+1 maka Tail(Q) diset =1
*/ 

/*********** Menqhapus sebuah elemen Queue **********/
void DelQueue (Queue *Q, infotype *X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S : Q terdefinisi, dan Q tidak kosong
 F.S : Q berkurang satu elemen didepan disimpan pada X
 Head(Q) “maju” selama Head(Q) < MaxEl,
 Tetapi Jika Head(Q)=MaxE1+1 maka Tail(Q) diset =1
*/

/** { KELOMPOK Interaksi dengan I/O device, BACA/TULIS } **/
void PrintQueueInfo (Queue S);
/* 	I.S : S terdefinisi, mungkin kosong
	F.S : Jika Queue tidak kosong, semua info yang disimpan pada elemen queue diprint.
*/

/** KELOMPOK OPERASI LAIN TERHADAP TYPE **/
boolean isInfoKetemu(Queue S, infotype x);
/* mengirim true jika x ada pada Q */

address CariElemenQueue(Queue Q, int X);
// Search apakah ada elemen tabel T yang bernilai X)
// Jika x ada pada Q, menghasilkan address terkecil
// Jika tidak ada, mengirimkan IdXUndef)
// Menghasilkan indeks tak terdefinisi(IdxUndef) jika Queue kosong)
// Memakai Skema search DENGAN boolean Found}

#endif
