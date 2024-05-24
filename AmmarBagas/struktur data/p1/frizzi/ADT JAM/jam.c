/*	program	:  jam.h
	author	: Frizzi Dipta Juniar
	nim		: 2350081007
	date	:3/15/2024
	desc 	: program jam.c untuk function dan procedure ADT JAM
*/

#include "jam.h"
#include <stdio.h>
#include <conio.h>


void CreateJam(JAM *J, int HH, int MM, int SS ){
/*Konstruktor ADT JAM*/
	(*J).Hour = HH;
	(*J).Minute = MM;
	(*J).Second = SS;
}


int GetHour(JAM J){
/*Selektor nilali JAM*/
	return J.Hour;
}
int GetMinute(JAM J){
/*Selektor nilali JAM*/
	return J.Minute;
}
int GetSecond(JAM J){
/*Selektor nilali JAM*/
	return J.Second;
}


void SetHour(JAM *J, int NewHour){
/*Set nilai Komponen*/
	(*J).Hour = NewHour;
}
void SetMinute(JAM *J, int NewMinute){
/*Set nilai Komponen*/
	(*J).Minute = NewMinute;
}
void SetSecond(JAM *J, int NewSecond){
/*Set nilai Komponen*/
	(*J).Second = NewSecond;
}


void ReadJam(JAM *J){
/*Kelompok baca*/
	int hh,mm,ss;
	
	do{
		scanf("%d", &hh);
		scanf("%d", &mm);
		scanf("%d", &ss);
	}while(hh < 0 || hh > 23 || mm < 0 || mm > 59 || ss < 0 || ss > 59);
	CreateJam(&(*J),hh,mm,ss );

}
void PrintJam(JAM J){
/*Kelompok tulis*/
	printf("%d:%d:%d",J.Hour,J.Minute,J.Second);
}

