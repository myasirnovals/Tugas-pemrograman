/* Program	: jam.h
   Author	: (2350081028, Ricky Gunaldo)
   Kelas	: A
   Deskripsi: Header file dari prototype jam
   Tanggal	: 14 - 03 - 2024
*/

#ifndef JAM_H
#define JAM_H
#include "boolean.h"
#define true 1
#define false 0
#define boolean unsigned char

typedef struct{
int Hour;
int Minute;
int Second;
} JAM;

//Prototype ADT JAM
//Kontruktor membentuk ADT JAM
void CreateJam(JAM *J, int HH, int MM, int SS);

//Selektor nilai JAM
int GetHour (JAM J);
int GetMinute (JAM J);
int GetSecond (JAM J);

//Set nilai komponen
void SetHour (JAM *J, int newHour);
void SetMinute (JAM *J, int newMinute);
void SetSecond (JAM *J, int newSecond);

//Destruktor / Dealokator: tidak perlu

//{Kelompok baca / tulis}
void ReadJam (JAM *J);
void PrintJam (JAM J);

//{Kelompok validasi Type}
boolean IsJValid(int H, int M, int S);

//{Operator Relasional}
boolean JEQ(JAM J1, JAM J2);
boolean JLT(JAM J1, JAM J2);
boolean JGT(JAM J1, JAM J2);

//{Operator aritmatika}
void Reset(JAM *J);
JAM NextDetik(JAM J);
JAM NextNDetik(JAM J, int N);
long int Durasi(JAM JAw, JAM JAk);
long int JamToDetik(JAM J);

#endif //JAM_H
