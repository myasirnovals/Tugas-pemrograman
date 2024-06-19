#include "../lib/point.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>

void CreatePoint(POINT *P) {
    (*P).X = 0;
    (*P).Y = 0;
}

void CreatePoint2(POINT *P, int XBaru, int YBaru) {
    (*P).X = XBaru;
    (*P).Y = YBaru;
}

int GetAbsis(POINT P) {
    return P.X;
}

int GetOrdinat(POINT P) {
    return P.Y;
}

void SetAbsis(POINT *P, int newX) {
    (*P).X = newX;
}

void SetOrdinat(POINT *P, int newY) {
    (*P).Y = newY;
}

void BacaPoint(POINT *P) {
    // kamus lokal
    int x, y;

    // algoritma
    printf("Masukan Absis: ");
    scanf("%d", &x);

    printf("Masukan Ordinat: ");
    scanf("%d", &y);

    CreatePoint2(&(*P), x, y);
}

void CetakPoint(POINT P) {
    printf("titik : (%d, %d)", GetAbsis(P), GetOrdinat(P));
}

boolean EQ(POINT P1, POINT P2) {
    if ((GetAbsis(P1) == GetAbsis(P2)) && (GetOrdinat(P1) == GetOrdinat(P2))) {
        return true;
    } else {
        return false;
    }
}

boolean NEQ(POINT P1, POINT P2) {
    if ((GetAbsis(P1) != GetAbsis(P2)) || (GetOrdinat(P1) != GetOrdinat(P2))) {
        return true;
    } else {
        return false;
    }
}

boolean LT(POINT P1, POINT P2) {
    if ((GetAbsis(P1) < GetAbsis(P2)) || (GetOrdinat(P1) < GetOrdinat(P2))) {
        return true;
    } else {
        return false;
    }
}

boolean MT(POINT P1, POINT P2) {
    if ((GetAbsis(P1) > GetAbsis(P2)) || (GetOrdinat(P1) > GetOrdinat(P2))) {
        return true;
    } else {
        return false;
    }
}

boolean IsOrigin(POINT P) {
    if ((GetAbsis(P) == 0) && (GetOrdinat(P) == 0)) {
        return true;
    } else {
        return false;
    }
}

boolean IsOnSbX(POINT P) {
    if ((GetOrdinat(P) == 0)) {
        return true;
    } else {
        return false;
    }
}

boolean IsOnSbY(POINT P) {
    if ((GetAbsis(P) == 0)) {
        return true;
    } else {
        return false;
    }
}

int Kuadran(POINT P) {
    if ((GetAbsis(P) > 0) && (GetOrdinat(P) > 0)) {
        return 1;
    } else if ((GetAbsis(P) < 0) && (GetOrdinat(P) > 0)) {
        return 2;
    } else if ((GetAbsis(P) < 0) && (GetOrdinat(P) < 0)) {
        return 3;
    } else if ((GetAbsis(P) > 0) && (GetOrdinat(P) < 0)) {
        return 4;
    } else {
        return 0;
    }
}

POINT MirrorOf(POINT P, boolean SbX, boolean SbY) {
    // kamus lokal
    POINT newPoint;

    // algoritma
    CreatePoint2(&newPoint, GetAbsis(P), GetOrdinat(P));

    if (SbX == true) {
        newPoint.X = GetAbsis(P) * -1;
    } else if (SbY == true) {
        newPoint.Y = GetOrdinat(P) * -1;
    }

    return newPoint;
}

double JarakO(POINT P) {
    // kamus lokal
    double jarak;

    // algoritma
    jarak = sqrt(pow((GetAbsis(P) - 0), 2) + pow((GetOrdinat(P) - 0), 2));

    return jarak;
}

void GeserKeSbX(POINT *P) {
    if (GetOrdinat((*P)) != 0) {
        SetOrdinat(&(*P), 0);
    }
}

void GeserKeSbY(POINT *P) {
    if (GetAbsis((*P)) != 0) {
        SetAbsis(&(*P), 0);
    }
}
