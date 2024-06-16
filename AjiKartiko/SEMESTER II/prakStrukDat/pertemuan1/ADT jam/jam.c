/*
    Program     : jam.c
    Author      : 2350081062, Aji Kartiko Hartanto
    Kelas       : C
    Deskripsi   : Body file dari prototype jam
    tanggal     : 15-03-2024
*/

#include "jam.h"
#include <stdio.h>
#include <conio.h>

/* Realisasi dari prototype ADT Jam */

/** Konstruktor membentuk ADT Jam **/
void CreateJam (JAM *J, int HH, int MM, int SS) {
/* Membentuk sebuah JAM dari komponen-komponennya yang valid
    Pre condition : HH,MM,SS valid untuk membentuk JAM
    I.S : J tidak terdefinisi, tidak diketahui nilainya
    F.S : membentuk sebuah Jam dari komponen-komponennya dengan J diinisialisasi nilainya dengan Hour = HH, Minute = MM, Second = SS
*/
(*J).Hour = HH;
(*J).Minute = MM;
(*J).Second = SS;
}

/* Selektor nilai JAM */
int GetHour(JAM J) {
// Mengirimkan komponen Hour dari J
return (J.Hour);
}
int GetMinute(JAM J){
// Mengirimkan komponen Minute dari J
return (J.Minute);
}
int GetSecond(JAM J) {
// Mengirimkan komponen Second dari J
return (J.Second);
}

/* Set nilai komponen */
void SetHour(JAM *J, int newHour) {
/* I.S : J terdefinisi, dengan nilainya sembarang
 F.S : Mengubah nilai komponen Hour dari J dengan Hour=newHour
*/
(*J).Hour = newHour;
}
void SetMinute(JAM *J, int newMinute) {
/* I.S : J terdefinisi, dengan nilainya sembarang
 F.S : Mengubah nilai komponen Minute dari J dengan Minute=newMinute
*/
(*J).Minute = newMinute;
}
void SetSecond(JAM *J, int newSecond) {
/* I.S : J terdefinisi, dengan nilainya sembarang
 F.S : Mengubah nilai komponen Second dari J dengan Second=newSecond
*/
(*J).Second = newSecond;
}

/** {Kelompok Baca/Tulis} **/
void ReadJam (JAM *J) {
/*  I.S. : J tidak terdefinisi
    F.S. : J terdefinisi dan merupakan jam yang valid
    Proses : proses membaca komponen H,M,S terus berlangsung sampai membentuk J yang valid. Komponen jam dikatakan valid,
    Jika : 0<=H<=23, 0<=M<=60 dan 0<=S<=59 
*/
    int hh, mm, ss;
    do {
        scanf("%d", &hh);
        scanf("%d", &mm);
        scanf("%d", &ss);
 }while (hh<0 || hh>23 || mm<0 || mm>59 || ss<0 || ss>59);
CreateJam(&(*J), hh, mm, ss);
}

/// @brief 
/// @param J

void PrintJam (JAM J) {
/*  I.S. : J diisi dengan nilai sembarang
    F.S. : Menampilkan jam (J) ke layar dengan format HH:MM:SS
*/
    printf("%d:%d:%d", J.Hour, J.Minute, J.Second);
} 

/** { kelompok Validasi Type } **/
boolean IsJValid (int H, int M, int S) {
/*  fungsi pengecekan nilai komponen jam yang valid
    Mengirimkan true jika H,M,S dapat membentuk J yang valid
    Sebaliknya mengirimkan false jika H,M,S tidak dapat membentuk J yang valid
*/
    if (H>=0 && H<=23 && M>=0 && M<=59 && S>=0 && S<=59)
        return (true);
    else
        return (false);
}

/** {Operator Relasional} **/
boolean JEQ(JAM J1, JAM J2) {
/* Mengirimkan true jika Jl=J2, false jika tidak
Artinya mengirimkan true jika semua elemen jam bernilai bernilai sama
Contoh :
    - Jika J1 = 10:20:30 dan J2 = 10:20:30, maka mengirimkan true
    - Jika J1 = 10:20:30 dan J2 = 10:30:30, maka mengirimkan false
*/
    if (J1.Hour == J2.Hour && J1.Minute == J2.Minute && J1.Second == J2.Second)
        return (true);
    else
        return (false);
}

boolean JLT(JAM J1, JAM J2) {
/* Mengirimkan true jika J1<J2 , false jika tidak
Artinya mengirimkan true jika elemen pada J1 bernilai kurang dari J2
Contoh :
    - Jika J1 = 10:20:30 dan J2 = 10:30:30, maka mengirimkan true
    - Jika J1 = 10:30:30 dan J2 = 10:30:30, maka mengirimkan false
    - Jika J1 = 10:30:30 dan J2 = 11:30:30, maka mengirimkan false
*/
    if (J1.Hour < J2.Hour || J1.Minute < J2.Minute || J1.Second < J2.Second)
        return (true);
    else
        return (false);
}

boolean JGT(JAM J1, JAM J2) {
/* Mengirimkan true jika Jl>J2, false jika tidak
Artinya mengirimkan true jika elemen pada J1 bernilai lebih dari J2
Contoh : 
    - Jika J1 = 10:40:30 dan J2 = 10:30:30, maka mengirimkan true
    - Jika J1 = 10:30:30 dan J2 = 10:30:30, maka mengirimkan false
    - Jika J1 = 10:20:30 dan J2 = 10:20:30, maka mengirimkan false
*/
    if (J1.Hour > J2.Hour || J1.Minute > J2.Minute || J1.Second > J2.Second)
        return (true);
    else
        return (false);
}

/** { operator aritmatika } **/
void Reset (JAM *J) {
/*  I.S. : J sembarang
    F.S. : J bernilai "nol", yaitu semua komponen bernilai 0
    Proses : Ubah semua nilai elemen J menjadi 0:0:0
*/
    (*J).Hour = 0;
    (*J).Minute = 0;
    (*J).Second = 0;
}

/// @brief 
/// @param J 
/// @return

JAM NextDetik (JAM J) {
/* Menambahkan nilai 1 detik pada jam, dan kirimkan nilai jam baru */
 JAM jamBaru;
/*  mencopy nilai J kepada jamBaru {bisa pakai cara ini atau yang dibawah}
jamBaru.Hour = J.Hour;
jamBaru.Minute = J.Minute;
jamBaru.Second = J.Second + 1;
*/
jamBaru = J;
jamBaru.Second = jamBaru.Second + 1;
if (jamBaru.Second > 59) {
    jamBaru.Second = 0;
    jamBaru.Minute = jamBaru.Minute + 1;
    if (jamBaru.Minute > 59) {
        jamBaru.Minute = 0;
        jamBaru.Hour = jamBaru.Hour + 1;
        if(jamBaru.Hour > 23){
            jamBaru.Hour = 0;
        }
    }
 }

return (jamBaru);
} 

JAM NextNDetik (JAM J, int N) {
/* Menambahkan nilai N detik pada jam, dan mengirimkan nilai jam baru */
int i;
JAM jamBaru;

jamBaru = J;
if (N > 0 && N <= 86400) { // menambahkan detik hanya sampai 24 jam
    for (i=1; i<=N; i++){
        jamBaru = NextDetik (jamBaru);
    }
 }

return (jamBaru);
}

long int Durasi ( JAM JAw , JAM JAkh) {
/* Menghitung selisih dari dua buah jam dalam bentuk detik
    Proses : Mengirimkan JAkh -JAw dlm Detik, Hasilnya negatif jika Jaw > JAkhir
    Jika hasilnya negatif maka ubahlah menjadi nilai positif
*/
long int detikAwl, detikAkh, result;

detikAwl = JamToDetik(JAw);
detikAkh = JamToDetik(JAkh);
result = detikAwl - detikAkh;
if (result < 0) {
    result = result * (-1);
 }

 return (result);
}

/** {Kelompok Konversi Terhadap Type} **/
long int JamToDetik (JAM J) {
/* melakukan konversi jam menjadi Detik
    Rumus : detik = 3600*hour+menit*60 + detik
    nilai maksimum = 3600*23+59*60+59*60
*/
long int detik;

detik = (J.Hour * 3600) + (J.Minute * 60) + J.Second;
return (detik);
} 