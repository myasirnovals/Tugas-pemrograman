/**
 * Program: jam.h
 * Author: (2350081004, Muhamad Yasir Noval)
 * Kelas: A
 * Deskripsi: Header file dari prortotype jam
 * Tangal: 15 Maret 2024
 */

#ifndef JAM_H
#define JAM_H

#include "boolean.h"

typedef struct {
    int Hour;
    int Minute;
    int Second;
} JAM;

// Prototype ADT Jam
// kontruktor membentuk ADT Jam
/**
 *
 * @param J
 * @param HH
 * @param MM
 * @param SS
 * Membentuk sebuah jam dari komponen-komponennya yang valid
 * pre condition: HH, MM, SS valid untuk membentuk JAM
 * I.S : J tidak terdefinisi, tidak diketahui nilainya
 * F.S : membentuk sebuah Jam dari komponen-komponennya dengan j
 * diinisialisasi nilainya dengan
 * Hour = HH, Minute = MM, Second = SS
 */
void CreateJam(JAM *J, int HH, int MM, int SS);

// Selektor nilai JAM
/**
 *
 * @param J
 * @return
 * mengirimkan komponen Hour dari J
 */
int GetHour(JAM J);

/**
 *
 * @param J
 * @return
 * Mengirimkan komponen Minute dari J
 */
int GetMinute(JAM J);

/**
 *
 * @param J
 * @return
 * Mengirimkan komponen Second dari J
 */
int GetSecond(JAM J);


// Set nilai komponen
/**
 *
 * @param J
 * @param newHour
 * I.S : J terdefinisi, dengan nilainya sembarang
 * F.S : Mengubah nilai komponen Hour dari J dengan Hour = newHour
 */
void SetHour(JAM *J, int newHour);

/**
 *
 * @param J
 * @param newMinute
 * I.S : J terdefinisi, dengan nilanya sembarang
 * F.S : Mengubah nilai komponen Minute dari J dengan Minute = newMinute
 */
void SetMinute(JAM *J, int newMinute);

/**
 *
 * @param J
 * @param newSecond
 * I.S : J terdefinisi, dengan nilanya sembarang
 * F.S : Mengubah nilai komponen Second dari J dengan Second = newSecond
 */
void SetSecond(JAM *J, int newSecond);

// Destruktor/Dealokator: tidak perlu

// {Kelompok Baca/tulis}
/**
 *
 * @param J
 * I.S : J tidak terdefinisi
 * F.S : J terdefinisi dan merupakan jam yang valid
 * Proses: proses membaca komponen H, M, S terus berlangsung sampai
 * membentuk J yang valid. Komponen jam dikatakan valid, jika
 * 0 <= H <= 23, 0 <= M <= 59, dan 0 <= S <= 59
 */
void ReadJam(JAM *J);

/**
 *
 * @param J
 * I.S : J diisi dengan nilai sembarang
 * F.S : Menampilkan jam (J) ke layar dengan format HH:MM:SS
 */
void PrintJam(JAM J);

// {Kelompok validasi Type}
/**
 *
 * @param H
 * @param M
 * @param S
 * @return
 * fungsi pengecekan nilai komponen jam yang valid
 * mengirimkan true jika H, M, S dapat membentuk J yang valid
 * sebaliknya mengirimkan false jika H, M, S tidak dapat membentuk J yang
 * valid
 */
boolean IsJValid(int H, int M, int S);

// {Operator Relasional}
/**
 *
 * @param J1
 * @param J2
 * @return
 * Mengirimkan true jika J1 = J2, false jika tidak
 * artinya mengirimkan true jika semua elemen jam bernilai sama
 * contoh
 * jika J1 = 10:20:30 dan J2 = 10:20:30, maka mengirimkan true
 * jika J1 = 10:20:30 dan J2 = 10:30:30, maka mengirimkan false
 */
boolean JEQ(JAM J1, JAM J2);

/**
 *
 * @param J1
 * @param J2
 * @return
 * Mengirimkan true jika J1 < J2, false jika tidak
 * artinya mengirimkan true jika elemen pada J1 bernilai kurang dari J2
 * contoh
 * jika J1 = 10:20:30 dan J2 = 10:30:30, maka mengirimkan true
 * jika J1 = 10:30:30 dan J2 = 10:30:30, maka mengirimkan false
 * jika J1 = 11:30:30 dan J2 = 10:30:30, maka mengirimkan false
 */
boolean JLT(JAM J1, JAM J2);

/**
 *
 * @param J1
 * @param J2
 * @return
 * Mengirimkan true jika J1 > J2, false jika tidak
 * artinya mengirimkan true jika elemen pada J1 bernilai lebih dari J2
 * contoh
 * jika J1 = 10:20:30 dan J2 = 10:30:30, maka mengirimkan false
 * jika J1 = 10:30:30 dan J2 = 10:30:30, maka mengirimkan true
 * jika J1 = 11:30:30 dan J2 = 10:30:30, maka mengirimkan true
 */
boolean JGT(JAM J1, JAM J2);

// {operator aritmatika}
/**
 *
 * @param J
 * I.S : J sembarang
 * F.S : J bernilai "nol", yaitu semua komponen bernilai 0
 * Proses: Ubah semua nilai elemen J menjadi 0:0:0
 */
void Reset(JAM *J);

/**
 *
 * @param J
 * @return
 * Menambahkan nilai 1 detik pada jam, dan kirimkan nilai jam baru
 */
JAM NextDetik (JAM J);

/**
 *
 * @param J
 * @param N
 * @return
 * Menambahkan nilai N detik pada jam, dan mengirimkan nilai jam baru
 */
JAM NextNDetik (JAM J, int N);

/**
 *
 * @param JAw
 * @param JAk
 * @return
 * Menghitung selisih dari dua buah jam dalam bentuk detik
 * proses: mengirimkan JAK - JAw dalam detik
 * hasilnya negatif jika JAw > JAk
 */
long int Durasi(JAM JAw, JAM JAk);

// {Kelompok konversi terhadap type}
/**
 *
 * @param J
 * @return
 * melakukan konversi jam menjadi detik
 * Rumus: detik = 3600 * hour + menit * 60 + detik * 60
 * nilai maksimum = 3600 * 23 + 59 * 60 + 59 * 60
 */
long int JamToDetik(JAM J);

#endif //JAM_H
