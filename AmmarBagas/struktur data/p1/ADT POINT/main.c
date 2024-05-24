/*
	program		: point.h
	author		: 2350081008/Ammar Bagas Fathurrahman Wantoro
	kelas		: A
	deskripsi	: header file dari prototype point
	tanggal		: 3/16/2024

*/

#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main(){
	POINT P1,P2;
	
	/*konstruktor*/
	CreatePoint(&P1);
	CreatePoint(&P2);
	
	CreatePoint2(&P1,0,5);
	CreatePoint2(&P2,-1,3);
	
	/*selektor*/
	printf("\nNilai Absis dari P1 :%d",GetAbsis(P1));
	printf("\nNilai Ordinat dari P1 :%d",GetOrdinat(P1));
	
	/*Set nilai POINT*/
	SetAbsis(&P1,-3);
	SetOrdinat(&P1,2);
	
	/*kelompok interaksi dengan I/O device, Baca/Tulis*/
	BacaPoint(&P1);
	CetakPoint(&P1);
	CetakPoint(&P2);
	
	/*kelompok operasi relasional terhadap POINT*/
	if(EQ(P1, P2) == true){
		printf("\nNilai POINT sama");
		printf("(True)");
	}else{
		printf("\nNilai POINT berbeda");
		printf("(False)");
	}
	
	if(NEQ(P1,P2) == true){
		printf("\nNilai POINT berbeda");
		printf("(True)");
	}else{
		printf("\nNilai POINT sama");
		printf("(False)");
	}
	
	if(LT(P1,P2) == true){
		printf("\nPOINT P1 lebih kecil dari P2");
		printf("(True)");
	}else{
		printf("\nPOINT P1 tidak lebih kecil dari P2");
		printf("(False)");
	}
	
	if(MT(P1,P2) == true){
		printf("\nPOINT P1 lebih besar dari P2");
		printf("(True)");
	}else{
		printf("\nPOINT P1 tidak lebih besar dari P2");
		printf("(False)");
	}
	
	/*kelompok menentukan dimana P berada*/
	if(IsOrigin(P1) == true){
		printf("\nPOINT berada di titik (0,0)");
		printf("(True)");
	}else{
		printf("\nPOINT berada di titik selain (0,0)");
		printf("(False)");
	}
	
	if(IsOnSbX(P1) == true){
		printf("\nPOINT berada di sumbu X");
		printf("(True)");
	}else{
		printf("\nPOINT tidak berada di sumbu X");
		printf("(False)");
	}
	
	if(IsOnSbY(P1) == true){
		printf("\nPOINT berada di sumbu Y");
		printf("(True)");
	}else{
		printf("\nPOINT tidak berada di sumbu Y");
		printf("(False)");
	}
	
	printf("\nPOINT P1 berada pada kuadran : %d", Kuadran(P1));
	printf("\nPOINT P2 berada pada kuadran : %d", Kuadran(P2));
	
	/*kelompok operasi lain terhadap type*/
	MirrorOf(P1,IsOnSbX(P1) , IsOnSbY(P1));
	
	printf("\nJarak POINT dari titik (0,0) : %d", jarakO(P1));
	GeserKeSbX(&P1);
	GeserKeSbY(&P1);
	return 0;
}
