/**
 * Program: point.h
 * Author: (2350081004, Muhamad Yasir Noval)
 * Kelas: A
 * Deskripsi: Header file dari prototype point
 * Tanggal: 15 Maret 2024
 */

#ifndef POINT_H
#define POINT_H

#include "boolean.h"
#include <stdio.h>
#include <conio.h>

#define Absis(P) (P).X
#define Ordinat(P) (P).Y
#define PI 3.14159265

// Definisi ABSTRACT DATA TYPETYPE POINT
typedef struct {
    int X;
    int Y;
} POINT;

// PrototypePrototype POINT
/**
 *
 * @param P
 * I.S : P terdefinisi, tidak diketahui nilainya
 * F.S : membentuk sebuah POINT dari komponen-komponennya dengan P
 * diinisialisasi nilainya dengan X=0 dan Y=0
 */
void CreatePoint(POINT *P);

/**
 *
 * @param P
 * @param XBaru
 * @param YBaru
 * I.S : P terdefinisi, tidak diketahui nilainya
 * F.S : membentuk sebuah POINT dari komponen-komponennya dengan P
 * diinisialisasi nilainya dengan X=XBaru dan Y=YBaru
 */
void CreatePoint2(POINT *P, int XBaru, int YBaru);

// Selektor POINT
/**
 *
 * @param P
 * @return
 * Mengirimkan komponen Absis dari P
 */
int GetAbsis(POINT P);

/**
 *
 * @param P
 * @return
 * Mengirimkan komponen Ordinat dari P POINT
 */
int GetOrdinat(POINT P);

// Set nilai komponen
/**
 *
 * @param P
 * @param newX
 * I.S : P terdefinisi, dengan nilainya sembarang
 * F.S : Mengubah nilai komponen Absis dari P dengan X=newX
 */
void SetAbsis(POINT *P, int newX);

/**
 *
 * @param P
 * @param newY
 * I.S : P terdefinisi, dengan nilainya sembarang
 * F.S : Mengubah nilai komponen Absis dari P dengan Y=newY
 */
void SetOrdinat(POINT *P, int newY);

// Destruktor/Dealokator: tidak perlu
// {Kelompok Interaksi dengan I/O device, BACA/TULIS}
/**
 *
 * @param P
 * I.S : P terdefinisi, mungkin kosong
 * F.S : P terdefinisi, dengan membaca nilai X dan Y
 */
void BacaPoint(POINT *P);

/**
 *
 * @param P
 * I.S : P terdefinisi, mungkin kosong
 * F.S : Menampilkan nilai komponen P ke layar dengan format “(X,Y)"
 */
void CetakPoint(POINT P);

// Kelompok operasi relasional terhadap Point
/**
 *
 * @param P1
 * @param P2
 * @return
 * Mengirimkan true jika PI = P2, dan false jika sebaliknya
 */
boolean EQ(POINT P1, POINT P2);

/**
 *
 * @param P1
 * @param P2
 * @return
 * Mengirimkan true jika P1 tidak sama dengan P2, dan false jika sebaliknya
 */
boolean NEQ(POINT P1, POINT P2);

/**
 *
 * @param P1
 * @param P2
 * @return
 * Mengirimkan true jika PI 1 < P2, dan false jika sebaliknya
 * definisi lebih kecil: posisi titik lebih ke kiri atau ke bawah dalam
 * bidang kartesian
 */
boolean LT(POINT P1, POINT P2);

/**
 *
 * @param P1
 * @param P2
 * @return
 * Mengirimkan true jika PI 1 > P2, dan false jika sebaliknya
 * definisi lebih besar: posisi titik lebih ke kanan atau ke atas dalam
 * bidang kartesian
 */
boolean MT(POINT P1, POINT P2);

// Kelompok menentukan di mana P berada
/**
 *
 * @param P
 * @return
 * Menghasilkan true jika P berada pada titik origin
 * yaitu nilai X=0 dan Y=0, dan false jika sebaliknya
 */
boolean IsOrigin(POINT P);

/**
 *
 * @param P
 * @return
 * Menghasilkan true jika P terletak Pada sumbu X yaitu
 * nilai Y=0, dan false jika sebaliknya
 */
boolean IsOnSbX(POINT P);

/**
 *
 * @param P
 * @return
 * Menghasilkan true jika P terletak Pada sumbu Y yaitu
 * nilai X=0, dan false jika sebaliknya
 */
boolean IsOnSbY(POINT P);

/**
 *
 * @param P
 * @return
 * Menghasilkan kuadran dari P: 1,2,3, atau 4
 * Precondition : P bukan Titik Origin, dan P tidak terletak di salah satu
 * sumbu
 */
int Kuadran(POINT P);

// Kelompok opearsi lain terhadap type
/**
 *
 * @param P
 * @param SbX
 * @param SbY
 * @return
 * Menghasilkan salinan P yang dicerminkan tergantung nilai SbX dan SBY
 * Jika SbX bernilai true, maka dicerminkan terhadap Sumbu X
 * Jika SbY bernilai true, maka dicerminkan terhadap Sumbu Y
 */
POINT MirrorOf(POINT P, boolean SbX, boolean SbY);

/**
 *
 * @param P
 * @return
 * Menghitung jarak P dari titik Origin (0, 0)
 */
double JarakO(POINT P);

/**
 *
 * @param P
 * I.S : P terdefinisi, mungkin kosong
 * F.S : P berada pada Sumbu X, jika tidak berada pada Sumbu X maka geser P ke Sumbu X.
 * Contoh: Jika koordinat semula(9,9) menjadi (9,0)
 */
void GeserKeSbX(POINT *P);

/**
 *
 * @param P
 * I.S : P terdefinisi, mungkin kosong
 * F.S : P berada pada Sumbu Y, jika tidak berada pada Sumbu Y maka geser P ke Sumbu Y.
 * Contoh: Jika koordinat semula(9,9) menjadi (0,9)
 */
void GeserKeSbY(POINT *P);

#endif //POINT_H
