/**
 * Program: jam.c
 * Author: (2350081004, Muhamad Yasir Noval)
 * Kelas: A
 * Deskripsi: body file dari prortotype jam
 * Tangal: 15 Maret 2024
 */

#include "../lib/jam.h"
#include <stdio.h>
#include <conio.h>

// Realisasi dari prototype ADT Jam
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
void CreateJam(JAM *J, int HH, int MM, int SS) {
    (*J).Hour = HH;
    (*J).Minute = MM;
    (*J).Second = SS;
}

// Selektor nilai JAM
/**
 *
 * @param J
 * @return
 * mengirimkan komponen Hour dari J
 */
int GetHour(JAM J) {
    return J.Hour;
}

/**
 *
 * @param J
 * @return
 * Mengirimkan komponen Minute dari J
 */
int GetMinute(JAM J) {
    return J.Minute;
}

/**
 *
 * @param J
 * @return
 * Mengirimkan komponen Second dari J
 */
int GetSecond(JAM J) {
    return J.Second;
}


// Set nilai komponen
/**
 *
 * @param J
 * @param newHour
 * I.S : J terdefinisi, dengan nilainya sembarang
 * F.S : Mengubah nilai komponen Hour dari J dengan Hour = newHour
 */
void SetHour(JAM *J, int newHour) {
    (*J).Hour = newHour;
}

/**
 *
 * @param J
 * @param newMinute
 * I.S : J terdefinisi, dengan nilanya sembarang
 * F.S : Mengubah nilai komponen Minute dari J dengan Minute = newMinute
 */
void SetMinute(JAM *J, int newMinute) {
    (*J).Minute = newMinute;
}

/**
 *
 * @param J
 * @param newSecond
 * I.S : J terdefinisi, dengan nilanya sembarang
 * F.S : Mengubah nilai komponen Second dari J dengan Second = newSecond
 */
void SetSecond(JAM *J, int newSecond) {
    (*J).Second = newSecond;
}

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
void ReadJam(JAM *J) {
    int hh, mm, ss;

    do {
        printf("Masukan Jam: ");
        scanf("%d", &hh);

        printf("Masukan Menit: ");
        scanf("%d", &mm);

        printf("Masukan Detik: ");
        scanf("%d", &ss);
    } while ((hh < 0 || hh > 23) || (mm < 0 || mm > 59) || (ss < 0 || ss > 59));

    CreateJam(&(*J), hh, mm, ss);
}

/**
 *
 * @param J
 * I.S : J diisi dengan nilai sembarang
 * F.S : Menampilkan jam (J) ke layar dengan format HH:MM:SS
 */
void PrintJam(JAM J) {
    printf("%d:%d:%d", J.Hour, J.Minute, J.Second);
}

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
boolean IsJValid(int H, int M, int S) {
    if ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >= 0 && S <= 59)) {
        return true;
    } else {
        return false;
    }
}

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
boolean JEQ(JAM J1, JAM J2) {
    if ((J1.Hour == J2.Hour) && (J1.Minute == J2.Minute) && (J1.Second == J2.Second)) {
        return true;
    } else {
        return false;
    }
}

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
boolean JLT(JAM J1, JAM J2) {
    if ((J1.Hour < J2.Hour) || (J1.Minute < J2.Minute) || (J1.Second < J2.Second)) {
        return true;
    } else {
        return false;
    }
}

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
boolean JGT(JAM J1, JAM J2) {
    if ((J1.Hour > J2.Hour) || (J1.Minute > J2.Minute) || (J1.Second > J2.Second)) {
        return true;
    } else {
        return false;
    }
}

// {operator aritmatika}
/**
 *
 * @param J
 * I.S : J sembarang
 * F.S : J bernilai "nol", yaitu semua komponen bernilai 0
 * Proses: Ubah semua nilai elemen J menjadi 0:0:0
 */
void Reset(JAM *J) {
    (*J).Hour = 0;
    (*J).Minute = 0;
    (*J).Second = 0;
}

/**
 *
 * @param J
 * @return
 * Menambahkan nilai 1 detik pada jam, dan kirimkan nilai jam baru
 */
JAM NextDetik(JAM J) {
    JAM jamBaru;

    jamBaru = J;
    jamBaru.Second = jamBaru.Second + 1;
    if (jamBaru.Second > 59) {
        jamBaru.Second = 0;
        jamBaru.Minute = jamBaru.Minute + 1;
        if (jamBaru.Minute > 59) {
            jamBaru.Minute = 0;
            jamBaru.Hour = jamBaru.Hour + 1;
            if (jamBaru.Hour > 23) {
                jamBaru.Hour = 0;
            }
        }
    }

    return jamBaru;
}

/**
 *
 * @param J
 * @param N
 * @return
 * Menambahkan nilai N detik pada jam, dan mengirimkan nilai jam baru
 */
JAM NextNDetik(JAM J, int N) {
    int i;
    JAM jamBaru;

    jamBaru = J;
    if (N > 0 && N <= 86400) {
        for (i = 1; i <= N; i++) {
            jamBaru = NextDetik(jamBaru);
        }
    }
    return (jamBaru);
}

/**
 *
 * @param JAw
 * @param JAk
 * @return
 * Menghitung selisih dari dua buah jam dalam bentuk detik
 * proses: mengirimkan JAK - JAw dalam detik
 * hasilnya negatif jika JAw > JAk
 */
long int Durasi(JAM JAw, JAM JAk) {
    long int detikAwl, detikAkh, result;

    detikAwl = JamToDetik(JAw);
    detikAkh = JamToDetik(JAk);

    result = detikAwl - detikAkh;

    if (result < 0) {
        result = result * (-1);
    }

    return result;
}

// {Kelompok konversi terhadap type}
/**
 *
 * @param J
 * @return
 * melakukan konversi jam menjadi detik
 * Rumus: detik = 3600 * hour + menit * 60 + detik
 * nilai maksimum = 3600 * 23 + 59 * 60 + 59 * 60
 */
long int JamToDetik(JAM J) {
    long int detik;

    detik = (J.Hour * 3600) + (J.Minute * 60) + J.Second;
    return detik;
}
