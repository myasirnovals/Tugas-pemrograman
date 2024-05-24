/*	program	:  jam.h
	author	: Frizzi Dipta Juniar
	nim		: 2350081007
	date	:3/15/2024
	desc 	: program header jam.h
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
int GetHour(JAM J);/*pengambilan nilai Hour pada type data JAM*/
int GetMinute(JAM J);/*pengambilan nilai Minute type data JAM*/
int GetSecond(JAM J);/*pengambilan nilai Second type data JAM*/

/*Set nilai Komponen*/
void SetHour(JAM *J, int NewHour);/*setting nilai atau ubah nilai Hour pada type data JAM*/
void SetMinute(JAM *J, int NewMinute);/*setting nilai atau ubah nilai Minute pada type data JAM*/
void SetSecond(JAM *J, int NewSecond);/*setting nilai atau ubah nilai Second pada type data JAM*/

/*Kelompok baca tulis*/
void ReadJam(JAM *J);/*procedure membaca JAM*/
void PrintJam(JAM J);/*procedure menulis JAM*/

#endif
