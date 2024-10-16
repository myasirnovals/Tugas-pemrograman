/*
    Program     : point.c
    Author      : 2350081062, Aji Kartiko Hartanto
    Kelas       : C
    Deskripsi   : Body file dari prototype point
    Tanggal     : 16-03-2024
*/

#include "point.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>


/* Prototype POINT */
void CreatePoint(POINT *P) {
    (*P).X = 0;
    (*P).Y = 0;
}
/*
    I.S : P terdefinisi, tidak diketahui nilainya
    F.S : membentuk sebuah POINT dari komponen-komponennya dengan P diinisialisasi nilainya dengan X=0 dan Y=0
*/

void CreatePoint2(POINT *P, int XBaru, int YBaru) {
    (*P).X = XBaru;
    (*P).Y = YBaru;
}
/*
    I.S : P terdefinisi, tidak diketahui nilainya
    F.S : membentuk sebuah POINT dari komponen-komponennya dengan P diinisialisasi nilainya dengan X=XBaru dan Y=YBaru
*/


/* Selektor POINT */
int GetAbsis(POINT P) {
    return P.X;
}
//Mengirimkan komponen Absis dari P

int GetOrdinat(POINT P) {
    return P.Y;
}
//Mengirimkan komponen Ordinat dari P POINT


/* Set nilai komponen */
void SetAbsis(POINT *P, int newX) {
    (*P).X = newX;
}
/* 
    I.S : P terdefinisi, dengan nilainya sembarang
    F.S : Mengubah nilai komponen Absis dari P dengan X=newX 
*/

void SetOrdinat(POINT *P, int newY) {
    (*P).Y = newY;
}
/*
    I.S : P terdefinisi, dengan nilainya sembarang
    F.S : Mengubah nilai komponen Absis dari P dengan Y=newY
*/


/* Destruktor/Dealokator: tidak perlu */

/* {Kelompok Interaksi dengan I/O device, BACA/TULIS} */
/*
    I.S : P terdefinisi, kemungkinan kosong
    F.S : P terdefinisi, dengan membaca nilai X dan Y
*/
void BacaPoint(POINT *P) {
    // kamus lokal
    int x, y;

    // algoritma
    printf("Masukan Absis: ");
    scanf("%d", &x);

    printf("Masukan Ordinat: ");
    scanf("%d", &y);

    CreatePoint2(&(*P), x, y);
}

/*
    I.S : P terdefinisi, mungkin kosong
    F.S : Menampilkan nilai komponen P ke layar dengan format “(X,Y)"
*/
void CetakPoint(POINT P) {
    printf("titik : (%d, %d)", GetAbsis(P), GetOrdinat(P));
}


/* Kelompok operasi relasional terhadap Point */
boolean EQ(POINT P1, POINT P2) {
    if ((GetAbsis(P1) == GetAbsis(P2)) && (GetOrdinat(P1) == GetOrdinat(P2))) {
        return true;
    } else {
        return false;
    }
}
//Mengirimkan true jika PI = P2, dan false jika sebaliknya

boolean NEQ(POINT P1, POINT P2) {
    if ((GetAbsis(P1) != GetAbsis(P2)) || (GetOrdinat(P1) != GetOrdinat(P2))) {
        return true;
    } else {
        return false;
    }
}
//Mengirimkan true jika P1 tidak sama dengan P2, dan false jika sebaliknya

boolean LT(POINT P1, POINT P2) {
    if ((GetAbsis(P1) < GetAbsis(P2)) || (GetOrdinat(P1) < GetOrdinat(P2))) {
        return true;
    } else {
        return false;
    }
}
//Mengirimkan true jika P1 < P2, dan false jika sebaliknya definisi lebih kecil: posisi titik lebih ke kiri atau ke bawah dalam bidang kartesian

boolean MT(POINT P1, POINT P2) {
    if ((GetAbsis(P1) > GetAbsis(P2)) || (GetOrdinat(P1) > GetOrdinat(P2))) {
        return true;
    } else {
        return false;
    }
}
//Mengirimkan true jika PI 1 > P2, dan false jika sebaliknya definisi lebih besar: posisi titik lebih ke kanan atau ke atas dalam bidang kartesian


/* Kelompok menentukan di mana P berada */
boolean IsOrigin(POINT P) {
    if ((GetAbsis(P) == 0) && (GetOrdinat(P) == 0)) {
        return true;
    } else {
        return false;
    }
}
//Menghasilkan true jika P berada pada titik origin yaitu nilai X=0 dan Y=0, dan false jika sebaliknya

boolean IsOnSbX(POINT P) {
    if ((GetOrdinat(P) == 0)) {
        return true;
    } else {
        return false;
    }
}
//Menghasilkan true jika P terletak Pada sumbu X yaitu nilai Y=0, dan false jika sebaliknya

boolean IsOnSbY(POINT P) {
    if ((GetAbsis(P) == 0)) {
        return true;
    } else {
        return false;
    }
}
//Menghasilkan true jika P terletak Pada sumbu Y yaitu nilai X=0, dan false jika sebaliknya

int Kuadran(POINT P) {
    if ((GetAbsis(P) > 0) && (GetOrdinat(P) > 0)) {
        return 1;
    } else if ((GetAbsis(P) < 0) && (GetOrdinat(P) > 0)) {
        return 2;
    } else if ((GetAbsis(P) < 0) && (GetOrdinat(P) < 0)) {
        return 3;
    } else if ((GetAbsis(P) > 0) && (GetOrdinat(P) < 0)) {
        return 4;
    } else {
        return 0;
    }
}
/* Menghasilkan kuadran dari P: 1,2,3, atau 4
    Precondition : P bukan Titik Origin, dan P tidak terletak di salah satu sumbu
*/


/* Kelompok opearsi lain terhadap type */
POINT MirrorOf(POINT P, boolean SbX, boolean SbY) {
    // kamus lokal
    POINT newPoint;

    // algoritma
    CreatePoint2(&newPoint, GetAbsis(P), GetOrdinat(P));

    if (SbX == true) {
        newPoint.X = GetAbsis(P) * -1;
    } else if (SbY == true) {
        newPoint.Y = GetOrdinat(P) * -1;
    }

    return newPoint;
}
/* Menghasilkan salinan P yang dicerminkan tergantung nilai SbX dan SBY
    -Jika SbX bernilai true, maka dicerminkan terhadap Sumbu X
    -Jika SbY bernilai true, maka dicerminkan terhadap Sumbu Y
*/

//Menghitung jarak P dari titik Origin (0, 0)
double JarakO(POINT P) {
    // kamus lokal
    double jarak;

    // algoritma
    /*
    gunakan function sqrt() yang diambil dari library math.h
    function sqrt digunakan sebagai akar dari matematika dan memiliki 1 parameter
    
    gunakan function pow() yang diambil dari library math.h
    function pow digunakan sebaga exponensial dari matematika dan memiliki 2
    parameter, parameter yang pertama digunakan sebagai base, dan parameter
    kedua digunakan sebagai exponen
    */
    jarak = sqrt(pow((GetAbsis(P) - 0), 2) + pow((GetOrdinat(P) - 0), 2));

    return jarak;
}

void GeserKeSbX(POINT *P) {
    if (GetOrdinat((*P)) != 0) {
        SetOrdinat(&(*P), 0);
    }
}
/*
    I.S : P terdefinisi, kemungkinan kosong
    F.S : P berada pada Sumbu X, jika tidak berada pada Sumbu X maka geser P ke Sumbu X.
    Contoh: Jika koordinat semula(9,9) menjadi (9,0)
*/

void GeserKeSbY(POINT *P) {
    if (GetAbsis((*P)) != 0) {
        SetAbsis(&(*P), 0);
    }
}
/*
    I.S : P terdefinisi, kemungkinan kosong
    F.S : P berada pada Sumbu Y, jika tidak berada pada Sumbu Y maka geser P ke Sumbu Y.
    Contoh: Jika koordinat semula(9,9) menjadi (0,9)
*/
