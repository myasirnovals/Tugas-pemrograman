/*
	program		: jam.c
	author		: 2350081008/Ammar Bagas Fathurrahman Wantoro
	kelas		: A
	deskripsi	: program untuk pengoperasian atau menuliskan operasi dari prototype JAM
	tanggal		: 3/14/2024

*/

#include "jam.h"
#include <stdio.h>
#include <conio.h>

/*Konstruktor membentuk ADT JAM*/
void CreateJam(JAM *J, int HH, int MM, int SS ){
	(*J).Hour = HH;
	(*J).Minute = MM;
	(*J).Second = SS;
}

/*Selektor nilali JAM*/
int GetHour(JAM J){
	return J.Hour;
}
int GetMinute(JAM J){
	return J.Minute;
}
int GetSecond(JAM J){
	return J.Second;
}

/*Set nilai Komponen*/
void SetHour(JAM *J, int NewHour){
	(*J).Hour = NewHour;
}
void SetMinute(JAM *J, int NewMinute){
	(*J).Minute = NewMinute;
}
void SetSecond(JAM *J, int NewSecond){
	(*J).Second = NewSecond;
}

/*Kelompok baca tulis*/
void ReadJam(JAM *J){
	int hh,mm,ss;
	
	do{
		scanf("%d", &hh);
		scanf("%d", &mm);
		scanf("%d", &ss);
	}while(hh < 0 || hh > 23 || mm < 0 || mm > 59 || ss < 0 || ss > 59);
	CreateJam(&(*J),hh,mm,ss );

}
void PrintJam(JAM J){
	printf("%d:%d:%d",J.Hour,J.Minute,J.Second);
}

/*kelompok validasi type*/
boolean IsValid(int H, int M, int S){
	if(H >= 0 && H <= 23 && M >= 0 && M <= 59 && S >= 0 && S <= 59){
		return true;
	}else{
		return false;
	}
}

/*operator relasional*/
boolean JEQ(JAM J1,JAM J2){
	if(J1.Hour == J2.Hour && J1.Minute == J2.Minute && J1.Second == J2.Second){
		return true;
	}else{
		return false;
	}
}
boolean JLT(JAM J1,JAM J2){
	if(J1.Hour < J2.Hour || J1.Minute < J2.Minute || J1.Second < J2.Second){
		return true;
	}else{
		return false;
	}
}
boolean JGT(JAM J1,JAM J2){
		if(J1.Hour > J2.Hour || J1.Minute > J2.Minute || J1.Second > J2.Second){
		return true;
	}else{
		return false;
	}
}


/*operator aritmatika*/
void Reset(JAM *J){
	(*J).Hour = 0;
	(*J).Minute = 0;
	(*J).Second = 0;
}
JAM NextDetik(JAM J){
	JAM JamBaru;
	
	JamBaru = J;
	JamBaru.Second = JamBaru.Second + 1;
	if(JamBaru.Second > 59){
		JamBaru.Second = 0;
		JamBaru.Minute = JamBaru.Minute + 1;
		if(JamBaru.Minute > 59){
			JamBaru.Minute = 0;
			JamBaru.Hour = JamBaru.Hour + 1;
			if(JamBaru.Hour > 23){
				JamBaru.Hour = 0;
			}
		}
	}
	return JamBaru;
}
JAM NextNDetik(JAM J, int N){
	int i;
	JAM JamBaru;
	
	JamBaru = J;
	if(N > 0 && N <= 86400){//86400 adalah second dari 24 jam
		for(i=1;i<=N;i++){
			JamBaru = NextDetik(JamBaru);
		}
	}
	return JamBaru;
}
long int Durasi(JAM JAw, JAM JAkh){
	long int DetikAw,DetikAkh,result;
	
	DetikAw = JamToDetik(JAw);
	DetikAkh = JamToDetik(JAkh);
	
	result = DetikAw - DetikAkh;
	if(result < 0){
		result = result * (-1);
	}
	return result;
}

/*kelompok konversi terhadap type*/
long int JamToDetik(JAM J){
	long int Detik;
	
	Detik = (J.Hour * 3600) + (J.Minute * 60) + J.Second;
	return Detik;
}

