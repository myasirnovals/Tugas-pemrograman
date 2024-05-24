/*
	program		: jam.h
	author		: 2350081008/Ammar Bagas Fathurrahman Wantoro
	kelas		: A
	deskripsi	: file header dari prototype jam.h
	tanggal		: 3/14/2024

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
}JAM;

/*prototype ADT JAM*/

/*Konstruktor membentuk ADT JAM*/
void CreateJam(JAM *J, int HH, int MM, int SS );

/*Selektor nilali JAM*/
int GetHour(JAM J);
int GetMinute(JAM J);
int GetSecond(JAM J);

/*Set nilai Komponen*/
void SetHour(JAM *J, int NewHour);
void SetMinute(JAM *J, int NewMinute);
void SetSecond(JAM *J, int NewSecond);

/*Kelompok baca tulis*/
void ReadJam(JAM *J);
void PrintJam(JAM J);

/*kelompok validasi type*/
boolean IsValid(int H, int M, int S);

/*operator relasional*/
boolean JEQ(JAM J1,JAM J2);
boolean JLT(JAM J1,JAM J2);
boolean JGT(JAM J1,JAM J2);


/*operator aritmatika*/
void Reset(JAM *J);
JAM NextDetik(JAM J);
JAM NextNDetik(JAM J, int N);
long int Durasi(JAM JAw, JAM JAkh);

/*kelompok konversi terhadap type*/
long int JamToDetik(JAM J);

#endif
