/*
    Program: point.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Header file dari prototype point
    Tanggal: 15/03/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"

void CreatePoint(POINT *P) {
    (*P).X = 0;
    (*P).Y = 0;
}

void CreatePoint2(POINT *P, int XBaru, int YBaru) {
    (*P).X = XBaru;
    (*P).Y = YBaru;
}

int GetAbsis(POINT P) {
    return (P.X);
}

int GetOrdinat(POINT P) {
    return (P.Y);
}

void SetAbsis(POINT *P, int newX) {
    (*P).X = newX;
}

void SetOrdinat(POINT *P, int newY) {
    (*P).Y = newY;
}

void BacaPoint(POINT *P) {
    int x,y;
    printf("Inputkan nilai absis dan ordinat (x,y)\n");
    printf("x = ");
    scanf("%d", &x);
    printf("y = ");
    scanf("%d", &y);
    CreatePoint2(&(*P), x, y);
}

void CetakPoint(POINT P) {
    printf("(%d,%d)", P.X, P.Y);
}

boolean EQ(POINT P1, POINT P2) {
    return (P1.X == P2.X) && (P1.Y == P2.Y);
}

boolean NEQ(POINT P1, POINT P2) {
    return (P1.X != P2.X) && (P1.Y != P2.Y);
}

boolean LT(POINT P1, POINT P2) {
    return (P1.X < P2.X) && (P1.Y < P2.Y);
}

boolean MT(POINT P1, POINT P2) {
    return (P1.X > P2.X) && (P1.Y > P2.Y);
}

boolean IsOrigin(POINT P) {
    return (P.X == 0) && (P.Y == 0);
}

boolean IsOnSbX(POINT P) {
    return (P.X == 0);
}

boolean IsOnSbY(POINT P) {
    return (P.Y == 0);
}

int Kuadran(POINT P) {
    int K = 0;
    
    if(P.X > 0 && P.Y > 0) {
        K = 1;

    } else if(P.X < 0 && P.Y > 0) {
        K = 2;
    
    } else if(P.X < 0 && P.Y < 0) {
        K = 3;
    
    } else if(P.X > 0 && P.Y < 0) {
        K = 4;
    }

    return K;
}

POINT MirrorOf(POINT P, boolean SbX, boolean SbY){
    if(SbX) {
        P.X *= -1;
    }

    if(SbY) {
        P.Y *= -1;
    }

    return P;
}

double JarakO(POINT P){
    // return sqrt(pow(P.X,2) + pow(P.Y,2));
    return sqrt((GetAbsis(P))*(GetAbsis(P)) + (GetOrdinat(P))*(GetOrdinat(P)));
}

void GeserKeSbX(POINT *P){
    (*P).X = 0;
}

void GeserKeSbY(POINT *P) {
    (*P).Y = 0;
}