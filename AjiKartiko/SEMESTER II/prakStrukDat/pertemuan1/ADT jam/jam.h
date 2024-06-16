/*
    Program     : jam.h
    Author      : 2350081062, Aji Kartiko Hartanto
    Kelas       : C
    Deskripsi   : Header file dari prototype jam
    tanggal     : 15-03-2024
*/

#ifndef JAM_H
#define JAM_H
#include "boolean.h"
#define true 1
#define false 0
#define boolean unsigned char

typedef struct {
int Hour ; /* Hour [0..23] */
int Minute; /* Minute [0..59] */
int Second; /* Second [0..59] */
} JAM;

/* Prototype ADT Jam */

/** Konstruktor membentuk ADT Jam **/
void CreateJam (JAM *J, int HH, int MM, int SS);
/* 
    Membentuk sebuah JAM dari komponen-komponennya yang valid
        Pre condition : HH,MM,SS valid untuk membentuk JAM
        I.S : J tidak terdefinisi, tidak diketahui nilainya
        F.S : membentuk sebuah Jam dari komponen-komponennya dengan J diinisialisasi nilainya dengan Hour = HH, Minute = MM, Second = SS
*/

/* Selektor nilai JAM **/
int GetHour(JAM J);
// Mengirimkan komponen Hour dari J
int GetMinute(JAM J);
// Mengirimkan komponen Minute dari J
int GetSecond(JAM J);
// Mengirimkan komponen Second dari J

/* Set nilai komponen */
void SetHour(JAM *J, int newHour);
/*  I.S : J terdefinisi, dengan nilainya sembarang
    F.S : Mengubah nilai komponen Hour dari J dengan Hour=newHour 
*/
void SetMinute(JAM *J, int newMinute);
/*  I.S : J terdefinisi, dengan nilainya sembarang
    F.S : Mengubah nilai komponen MInute dari J dengan Minute=newMinute
*/
void SetSecond(JAM *J, int newSecond);
/*  I.S : J terdefinisi, dengan nilainya sembarang
    F.S : Mengubah nilai komponen Second dari J dengan Second=newSecond
*/ 

/* Destruktor/Dealokator: tidak perlu */

/** {Kelompok Baca/Tulis} **/
void ReadJam (JAM *J);
/*  I.S. : J tidak terdefinisi
    F.S. : J terdefinisi dan merupakan jam yang valid
    Proses : proses membaca komponen H,M,S terus berlangsung sampai membentuk J yang valid. Komponen jam dikatakan valid, Jika 0≤H≤23, 0≤M≤60, dan 0≤S≤59
*/
void PrintJam (JAM J);
/*  I.S. : J diisi dengan nilai sembarang
    F.S. : Menampilkan jam (J) ke layar dengan format HH:MM:SS
*/

/** { kelompok Validasi Type } **/
boolean IsJValid (int H, int M, int S);
/*  fungsi pengecekan nilai komponen jam yang valid
    Mengirimkan true jika H,M,S dapat membentuk J yang valid
    Sebaliknya mengirimkan false jika H,M,S tidak dapat membentuk J yang valid
*/

/** {Operator Relasional} **/
boolean JEQ(JAM J1, JAM J2);
/* Mengirimkan true jika Jl=J2, false jika tidak
 Artinya mengirimkan true jika semua elemen jam bernilai bernilai sama
 Contoh :
- Jika J1 = 10:20:30 dan J2 = 10:20:30, maka mengirimkan true
- Jika J1 = 10:20:30 dan J2 = 10:30:30, maka mengirimkan false
*/
boolean JLT(JAM J1, JAM J2);
/* Mengirimkan true jika J1<J2 , false jika tidak
 Artinya mengirimkan true jika elemen pada J1 bernilai kurang dari J2
 Contoh :
- Jika J1 = 10:20:30 dan J2 = 10:30:30, maka mengirimkan true
- Jika J1 = 10:30:30 dan J2 = 10:30:30, maka mengirimkan false
- Jika J1 = 11:30:30 dan J2 = 10:30:30, maka mengirimkan false
*/
boolean JGT(JAM J1, JAM J2);
/* Mengirimkan true jika Jl>J2, false jika tidak
 Artinya mengirimkan true jika elemen pada J1 bernilai lebih dari J2
 Contoh : 
- Jika J1 = 10:40:30 dan J2 = 10:30:30, maka mengirimkan true
- Jika J1 = 10:30:30 dan J2 = 10:30:30, maka mengirimkan false
- Jika J1 = 10:20:30 dan J2 = 11:20:30, maka mengirimkan false
*/ 

/** { operator aritmatika } **/
void Reset (JAM *J);
/*  I.S. : J sembarang
    F.S. : J bernilai “nol”, yaitu semua komponen bernilai 0
    Proses : Ubah semua nilai elemen J menjadi 0:0:0
*/
JAM NextDetik (JAM J);
/* Menambahkan nilai 1 detik pada jam, dan kirimkan nilai jam baru */
JAM NextNDetik (JAM J, int N);
/* Menambahkan nilai N detik pada jam, dan mengirimkan nilai jam baru */
long int Durasi ( JAM Jaw , JAM JAkh);
/* Menghitung selisih dari dua buah jam dalam bentuk detik
    Proses : Mengirimkan JAkh —JAw dlm Detik, Hasilnya negatif jika Jaw > JAkhir
*/ 

/** {Kelompok Konversi Terhadap Type} **/
long int JamToDetik (JAM J);
/* melakukan konversi jam menjadi Detik
    Rumus : detik = 3600*hour+menit*60 + detik
    nilai maksimum = 3600*23+59*60+59*60
*/ 

#endif