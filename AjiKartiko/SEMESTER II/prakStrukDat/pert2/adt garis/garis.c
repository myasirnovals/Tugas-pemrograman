/*
	Program		: garis.c
	Author		: 2350081062, Aji Kartiko Hartanto
	Kelas		: C
	Deskripsi	: main driver 
	Tanggal		: 20-03-2024
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "boolean.h"

//type
typedef struct {
	int abs;
	int ord;
} point;

typedef struct {
	point Pawal;
	point Pakhir;
} garis;


//prototype
void CreateGaris(garis *G);
void SetGaris(garis *G, point P1, point P2);
void CetakGaris(garis G);

void MoveGaris(garis *G, int d);
float GradienGaris(garis G);
garis CopyGarisNeg(garis G);
point getPointGaris(garis G);
boolean Is2GarisTgkLurus(garis G1, garis G2);


//realisasi prototype
void CreateGaris(garis *G) {
	(*G).Pawal.abs = 0;
	(*G).Pawal.ord = 0;
	(*G).Pakhir.abs = 0;
	(*G).Pakhir.ord = 0;
}

void SetGaris(garis *G, point P1, point P2) {
	//algoritma
	(*G).Pawal = P1;
	(*G).Pakhir = P2;
}

void CetakGaris(garis G) {
	//kamus
	int x1, y1, x2, y2;
	
	//algoritma
	x1 = G.Pawal.abs;
	y1 = G.Pawal.ord;
	x2 = G.Pakhir.abs;
	y2 = G.Pakhir.ord;
	
	printf("G[P1(%d, %d), P2(%d, %d)]", x1, y1, x2, y2);
}

void MoveGaris(garis *G, int d) {
	//kamus
	int x1, y1, x2, y2;
	
	//algoritma
	x1 = (*G).Pawal.abs + d;
	y1 = (*G).Pawal.ord + d;
	x2 = (*G).Pakhir.abs + d;
	y2 = (*G).Pakhir.ord + d;
	
	printf("garis pindah sebanyak %d jadi P1(%d, %d), P2(%d, %d)", d, x1, y1, x2, y2);
}

float GradienGaris(garis G) {
	//kamus
	int x1, y1, x2, y2;
	float gradien;
	
	//algoitma
	x1 = G.Pawal.abs;
	y1 = G.Pawal.ord;
	x2 = G.Pakhir.abs;
	y2 = G.Pakhir.ord;
	
	gradien = (float) (y2 - y1) / (x2 - x1);
	
	return gradien;
}

garis CopyGarisNeg(garis G){
	//kamus
	garis garis1;
	
	//algoritma
	garis1.Pawal.abs = G.Pawal.abs * -1;
	garis1.Pawal.ord = G.Pawal.ord * -1;
	garis1.Pakhir.abs = G.Pakhir.abs * -1;
	garis1.Pakhir.ord = G.Pakhir.ord * -1;
	
	return garis1;
}


point getPointGaris(garis G){
    return G.Pawal;
}

boolean Is2GarisTgkLurus(garis G1, garis G2){
	float TgkLurus;
	TgkLurus = GradienGaris(G1) * GradienGaris(G2);
	if (TgkLurus == -1)
		{
			return true;
		}
	else
		{
        	return false;
    	}
}


//main driver
int main() {
	//kamus
	point P1, P2, Poingaris;
	garis MyGaris, MyGaris1;
	int x1, y1, x2, y2;
	int titikbaru;
	float gradien;
	
	
	//algoritma
	CreateGaris(&MyGaris);
	printf("x1:"); scanf("%d,", &x1); 
	printf("y1:"); scanf("%d,", &y1);
	printf("x2:"); scanf("%d,", &x2);
	printf("y2:"); scanf("%d,", &y2);
	P1.abs = x1;
	P1.ord = y1;
	P2.abs = x2;
	P2.ord = y2;
	
	SetGaris(&MyGaris, P1, P2);
	CetakGaris(MyGaris);
	printf("\n");
	
	printf("masukkan titik baru: "); scanf("%d", &titikbaru);
	MoveGaris(&MyGaris, titikbaru);  
	printf("\n");
	
	gradien = GradienGaris(MyGaris);
	printf("cetak gradien: %2f \n", gradien);
	
	MyGaris1 = CopyGarisNeg(MyGaris);
	CetakGaris(MyGaris1);
	printf("\n");
	
	Poingaris = getPointGaris(MyGaris);
    printf("\nPoin garis nya adalah : (%d,%d)", Poingaris.abs, Poingaris.ord);
    
    
    if (Is2GarisTgkLurus(MyGaris, MyGaris1))
    {
        printf("\nGaris tegak lurus");
    }
    else
    {
        printf("\nGaris tidak tegak lurus");
    }
    
	return 0;
}


