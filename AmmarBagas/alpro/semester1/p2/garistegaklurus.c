/*	program : garistegaklurus.c
	author : 2350081008
	date : 17/10/2023
	desc : program membuktikan garis tegak lurus 
*/

#include <stdio.h>
#include <conio.h>

	typedef struct {
		int abs, ord;
	}point;

	typedef struct {
		point p1, p2;
	}garis;

int main() {
	//kamus
		//titik point
		point x1, y1, x2, y2, x3, y3, x4, y4;
		//garis 
		garis g1, g2;
		//gradien
		double m1, m2;
	//algoritma
		//input
		printf("masukan x1 absis :"); scanf("%d", &x1.abs);
		printf("masukan y1 ordinat :"); scanf("%d", &y1.ord);
		printf("masukan x2 absis :"); scanf("%d", &x2.abs);
		printf("masukan y2 ordinat :"); scanf("%d", &y2.ord);
		printf("masukan x3 absis :"); scanf("%d", &x3.abs);
		printf("masukan y3 ordinat :"); scanf ("%d", &y3.ord);
		printf("masukan x4 absis :"); scanf ("%d", &x4.abs);
		printf("masukan y4 ordinat :"); scanf("%d", &y4.ord);
		
		//garis 1
		g1.p1.abs = x1.abs;
		g1.p1.ord = y1.ord;
		g1.p2.abs = x2.abs;
		g1.p2.ord = y2.ord;
		
		//garis 2
		g2.p1.abs = x3.abs;
		g2.p1.ord = y3.ord;
		g2.p2.abs = x4.abs;
		g2.p2.ord = y4.ord;
		
		//menghitung gradien m garis 1
		m1 = (g1.p2.ord - g1.p1.ord)/(g1.p2.abs - g1.p1.abs);
		
		//menghitung gradien m garis 2
		m2 = (g2.p2.ord - g2.p1.ord)/(g2.p2.abs - g2.p1.abs);
		
		
		
		//pembuktian tegak lurus
		if (m1*m2 == -1){
			printf("garis tegak lurus");
		}else{
			printf("garis tidak tegak lurus");
		}
		
		return 0;
}
