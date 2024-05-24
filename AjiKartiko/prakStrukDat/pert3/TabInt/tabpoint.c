/*
	Program		: TabPoint.c
	Author		: 2350081062, Aji Kartiko Hartanto
	Kelas		: C
	Deskripsi	: 
	Tanggal		: 27-03-2024
*/


#include <stdio.h>
#include <conio.h>

//definisi nilai max = 10
#define nMax 10

typedef struct{
	int abs;
	int ord;
}Point;

typedef struct{
	Point Tp[nMax + 1];
	int nEff;
}TabPoint;


//prototype
void CreateTabPoint(TabPoint *T);
void AddElmTab(TabPoint *T, Point P);
void CetakTab(TabPoint T);

//tugas
void AddFirstElm(TabPoint *T, Point P);
void CetakInversTab(TabPoint T);
void CetakKuadranPoint(TabPoint T);
TabPoint CopyTabNeg(TabPoint T);
int PointMax(TabPoint T);
int kuadran(Point P);
void InversTab(TabPoint *T);


//main driver
int main(){
	//kamus
	TabPoint MyTab;
	int x, y, x1, y1;
	Point P;
	
	//algoritma
	CreateTabPoint(&MyTab);
		printf("input x: "); scanf("%d", &x);
		printf("input y: "); scanf("%d", &y);
	
	while( x != 999 && y != 999 ){
		P.abs = x;
		P.ord = y;
		
		AddElmTab(&MyTab, P);
		printf("input x: "); scanf("%d", &x);
		printf("input y: "); scanf("%d", &y);
	}
	CetakTab(MyTab);
	
	printf("\n");
	printf("input x baru: "); scanf("%d", &x1);
	printf("input y baru: "); scanf("%d", &y1);
	P.abs = x1;
	P.ord = y1;
	AddFirstElm(&MyTab, P);
	CetakTab(MyTab);
	
	
	printf("\n");
    printf("Tab dalam reverse order:\n");
    CetakInversTab(MyTab);

    printf("\n");
    printf("Kuadran of each point:\n");
    CetakKuadranPoint(MyTab);

    printf("\n");
    printf("Copying points dengan negasi:\n");
    TabPoint negTab = CopyTabNeg(MyTab);
    CetakTab(negTab);

    printf("\n");
    int maxIndex = PointMax(MyTab);
    printf("Index point dengan maksimum jaran from origin: %d\n", maxIndex);

    printf("\n");
    printf("Inversi Tab nya:\n");
    InversTab(&MyTab);
    CetakTab(MyTab);

    return 0;
}
	

//realisasi prototype
void CreateTabPoint(TabPoint *T){
	(*T).nEff = 0;
}

void AddElmTab(TabPoint *T, Point P){
	if((*T).nEff < nMax){
		(*T).nEff++;
		(*T).Tp[(*T).nEff] = P;
	}
}

void CetakTab(TabPoint T){
	//kamus
	int i, x, y;
	//algoritma
	for(i = 1; i <= T.nEff; i++){
		x = T.Tp[i].abs;
		y = T.Tp[i].ord;
		printf("< %d , %d >", x, y);
	}
}

//realisasi prototype tugas
void AddFirstElm(TabPoint *T, Point P){
	if((*T).nEff < nMax){
		int i;
		for(i = (*T).nEff; i > 0; i--){
			(*T).Tp[i + 1] = (*T).Tp[i];
		}
		(*T).Tp[1] = P;
		(*T).nEff++;
	}
}

void CetakInversTab(TabPoint T){
    int i;
	for(i = T.nEff; i > 0; i--){
        printf("< %d , %d >", T.Tp[i].abs, T.Tp[i].ord);
    }
}


void CetakKuadranPoint(TabPoint T){
    int i;
	for(i = 1; i <= T.nEff; i++){
        printf("Point < %d , %d > adalah di kuadran %d\n", T.Tp[i].abs, T.Tp[i].ord, kuadran(T.Tp[i]));
    }
}


TabPoint CopyTabNeg(TabPoint T){
    TabPoint result;
    CreateTabPoint(&result);
	int i;
	
    for(i = 1; i <= T.nEff; i++){
        if(T.Tp[i].ord < 0){
            AddElmTab(&result, T.Tp[i]);
        }
    }

    return result;
}


int PointMax(TabPoint T){
    int maxIndex = 1;
    double maxDistance = T.Tp[1].abs * T.Tp[1].abs + T.Tp[1].ord * T.Tp[1].ord; 
	int i;
	
    for(i = 2; i <= T.nEff; i++){
        double distance = T.Tp[i].abs * T.Tp[i].abs + T.Tp[i].ord * T.Tp[i].ord;
        if(distance > maxDistance){
            maxDistance = distance;
            maxIndex = i;
        }
    }

    return maxIndex;
}


int kuadran(Point P){
    if(P.abs > 0 && P.ord > 0)
        return 1;
    else if(P.abs < 0 && P.ord > 0)
        return 2;
    else if(P.abs < 0 && P.ord < 0)
        return 3;
    else if(P.abs > 0 && P.ord < 0)
        return 4;
    else
        return 0; 
}


void InversTab(TabPoint *T){
    Point temp;
    int i;
	for(i = 1; i <= T->nEff / 2; i++){
        temp = T->Tp[i];
        T->Tp[i] = T->Tp[T->nEff - i + 1];
        T->Tp[T->nEff - i + 1] = temp;
    }
}

