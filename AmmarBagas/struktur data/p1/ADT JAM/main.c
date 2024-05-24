/*
	program		: main.c
	author		: 2350081008/Ammar Bagas Fathurrahman Wantoro
	kelas		: A
	deskripsi	: main driver untuk menjalankan prototype JAM
	tanggal		: 3/14/2024

*/

#include <stdio.h>
#include <stdlib.h>
//#include "jam.c"
#include "jam.h"

int main (){
	JAM J1,J2,J3,J4;
	int tambahanDetik;
	ReadJam(&J1);
	printf("Nilai J1 =");PrintJam(J1);
	printf("\n");
	
	J2 = NextDetik(J1);
	printf("Nilai J2 =");PrintJam(J2);printf("\n");
	
	printf("Masukan nilai tambahan detik (0...59) =");
	scanf("%d",&tambahanDetik);
	J3 = NextNDetik(J1,tambahanDetik);
	printf("Nilai J3 =");PrintJam(J3);printf("\n");
	J4 = J1;
	printf("Nilai J4 =");PrintJam(J4);printf("\n");
	
	printf("\npengecekan operator relasional\n");
	if(JEQ(J1,J2)){
		printf("\nNIilai J1 sama dengan J2");
	}
	if(JLT(J1,J2)){
		printf("\nNilai J1 lebih kecil dari J2");
	}
	if(JGT(J1,J2)){
		printf("\nNilai J1 lebih besar dari J2");
	}
	
	if(JEQ(J3,J1)){
		printf("\nNIilai J3 sama dengan J1");
	}
	if(JLT(J3,J1)){
		printf("\nNilai J3 lebih kecil dari J1");
	}
	if(JGT(J3,J1)){
		printf("\nNilai J3 lebih besar dari J1");
	}
	
	if(JEQ(J1,J4)){
		printf("\nNIilai J1 sama dengan J4");
	}
	if(JLT(J1,J4)){
		printf("\nNilai J1 lebih kecil dari J4");
	}
	if(JGT(J1,J4)){
		printf("\nNilai J1 lebih besar dari J4");
	}
	
	Reset(&J4);
	printf("\nNilai J4 =");PrintJam(J4);printf("\n");
	
	return 0;
}


