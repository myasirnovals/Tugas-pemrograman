/*
	program		: point.h
	author		: 2350081008/Ammar Bagas Fathurrahman Wantoro
	kelas		: A
	deskripsi	: header file dari prototype point
	tanggal		: 3/16/2024

*/

#include "point.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>

/*konstruktor POINT*/
void CreatePoint(POINT *P){
	(*P).X = 0;
	(*P).Y = 0;
}
void CreatePoint2(POINT *P,int XBaru,int YBaru){
	(*P).X = XBaru;
	(*P).Y = YBaru;
}

/*selektor POINT*/
int GetAbsis(POINT P){
	return P.X;
}
int GetOrdinat(POINT P){
	return P.Y;
}

/*set nilai POINT*/
void SetAbsis(POINT *P,int XBaru){
	(*P).X = XBaru;
}
void SetOrdinat(POINT *P,int YBaru){
	(*P).Y = YBaru;
}

/*kelompok interaksi dengan I/O device, Baca/Tulis*/
void BacaPoint(POINT *P){
	int X,Y;
	
	printf("\nMasukan nilai Absis X :");scanf("%d", &X);
	printf("Masukan nilai Ordinat Y :");scanf("%d", &Y);
	CreatePoint2(&(*P),X,Y);
}
void CetakPoint(POINT *P){
	printf("\nNilai Point adalah (%d,%d)",(*P).X,(*P).Y);
}

/*kelompok operasi relasional terhadap POINT*/
boolean EQ(POINT P1, POINT P2){
	if(GetAbsis(P1) == GetAbsis(P2) && GetOrdinat(P1) == GetOrdinat(P2)){
		return true;
	}else{
		return false;
	}
}
boolean NEQ(POINT P1,POINT P2){
	if(GetAbsis(P1) == GetAbsis(P2) && GetOrdinat(P1) == GetOrdinat(P2)){
		return false;
	}else{
		return true;
	}
}
boolean LT(POINT P1,POINT P2){
	if(GetAbsis(P1) < GetAbsis(P2) && GetOrdinat(P1) < GetOrdinat(P2)){
		return true;
	}else{
		return false;
	}
}
boolean MT(POINT P1,POINT P2){
	if(GetAbsis(P1) > GetAbsis(P2) && GetOrdinat(P1) > GetOrdinat(P2)){
		return true;
	}else{
		return false;
	}
}

/*kelompok menentukan dimana P berada*/
boolean IsOrigin(POINT P){
	if(GetAbsis(P) == 0 && GetOrdinat(P) == 0){
		return true;
	}else{
		return false;
	}
}
boolean IsOnSbX(POINT P){
	if(GetOrdinat(P) == 0){
		return true;
	}else{
		return false;
	}
}
boolean IsOnSbY(POINT P){
	if(GetAbsis(P) == 0){
		return true;
	}else{
		return false;
	}
}
int Kuadran(POINT P){
	if(GetAbsis(P) > 0 && GetOrdinat(P) > 0){
		return 1;
	}else if(GetAbsis(P) < 0 && GetOrdinat(P) > 0){
		return 2;
	}else if(GetAbsis(P) < 0 && GetOrdinat(P) < 0){
		return 3;
	}else if(GetAbsis(P) > 0 && GetOrdinat(P) < 0){
		return 4;
	}else{
		return 0;
	}
}

/*kelompok operasi lain terhadap type*/
POINT MirrorOf(POINT P, boolean SbX, boolean SbY){
	if(SbX == true){
		P.X = GetAbsis(P) * -1;
		
	}else if(SbY == true){
		P.Y = GetOrdinat(P) * -1;
	}
	
	return P;
}
float jarakO(POINT P){
	float Jarak;

	Jarak= sqrt(pow((GetAbsis(P) - 0), 2) + pow((GetOrdinat(P) - 0), 2));

}
void GeserKeSbX(POINT *P){
	if (GetOrdinat((*P)) != 0) {
 			SetOrdinat(&(*P), 0);
 		}
}
void GeserKeSbY(POINT *P){
	if (GetAbsis((*P)) != 0) {
 			SetAbsis(&(*P), 0);
 		}
}
