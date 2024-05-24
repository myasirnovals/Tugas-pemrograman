/*
    Program: main.c
    Author: 2350081008/Ammar Bagas Fathurrahman Wantoro
    Kelas: A
    Deskripsi: Mline.c merupakan program yang menjalankan
               Semua Prosedur dan function
    Tanggal: 03/20/2024
*/
#include <stdio.h>
#include "line.c"
#include "point.c"

int main()
{
    LINE L1, L2, L3, L4;
    int deltaX, deltaY;

    BacaLine(&L1);
    printf("Line1 = ");
    CetakLine(L1);

    CreateLine(&L2);
    BacaLine(&L2);

    printf("Line2 = ");
    CetakLine(L2);

    printf("\nGaris Line 1 akan digeser sejauh: \n");
    printf("delta X: ");
    scanf("%d", &deltaX);

    printf("delta Y: ");
    scanf("%d", &deltaY);

    L3 = GeserLine(L1, deltaX, deltaY);
    printf("Line 3 = ");
    CetakLine(L3);

    L4 = L1;
    printf("Line 4 = ");
    CetakLine(L4);

    SetAbsis(&L2.PAwal, 0);
    SetOrdinat(&L2.PAwal, 0);

    printf("\nPengecekan operator relasional\n");
    if (IsEQLine(L1, L2))
    {
        printf("Nilai Line 1 sama dengan Line 2\n");
    }

    if (IsNEQLine(L1, L2))
    {
        printf("Nilai Line 1 tidak sama dengan Line 2\n");
    }

    if (IsEQLine(L3, L4))
    {
        printf("Nilai Line 3 sama dengan Line 4\n");
    }

    if (IsNEQLine(L3, L4))
    {
        printf("Nilai Line 3 tidak sama dengan Line 4\n");
    }

    printf("\nPengecekan garis apakah tegak lurus\n");
    if (IsTegakLurus(L1, L2))
    {
        printf("Garis Line 1 Tegak lurus dengan Line 2\n");
    }
    else
    {
        printf("Garis Line 1 Tidak Tegak lurus dengan Line 2\n");
    }

    if (IsTegakLurus(L2, L3))
    {
        printf("Garis Line 2 Tegak lurus dengan Line 3\n");
    }
    else
    {
        printf("Garis Line 2 Tidak Tegak lurus dengan Line 3\n");
    }

    if (IsTegakLurus(L3, L4))
    {
        printf("Garis Line 3 Tegak lurus dengan Line 4\n");
    }
    else
    {
        printf("Garis Line 3 Tidak Tegak lurus dengan Line 4\n");
    }

    if (IsTegakLurus(L4, L1))
    {
        printf("Garis Line 4 Tegak lurus dengan Line 1\n");
    }
    else
    {
        printf("Garis Line 4 Tidak Tegak lurus dengan Line 1\n");
    }

    printf("\nPengecekan garis apakah sejajar\n");
    if (IsSejajar(L1, L2))
    {
        printf("Garis L1 sejajar dengan L2\n");
    }
    else
    {
        printf("\nGaris Line 1 tidak sejajar dengan Line 2\n");
    }

    if (IsSejajar(L1, L3))
    {
        printf("Garis Line 1 sejajar dengan Line 3\n");
    }
    else
    {
        printf("Garis Line 1 tidak sejajar dengan Line 3\n");
    }

    if (IsSejajar(L1, L4))
    {
        printf("Garis Line 1 sejajar dengan Line 4\n");
    }
    else
    {
        printf("Garis Line 1 tidak sejajar dengan Line 4\n");
    }

    printf("\nPengecekan operator posisi\n");
    if (IsLOnSbX(L1))
    {
        printf("Garis Line 1 berada pada sumbu X\n");
    }

    if (IsLOnSbX(L2))
    {
        printf("Garis Line 2 berada pada sumbu X\n");
    }

    if (IsLOnSbX(L3))
    {
        printf("Garis Line 3 berada pada sumbu X\n");
    }

    if (IsLOnSbX(L4))
    {
        printf("Garis Line 4 berada pada sumbu X\n");
    }

    if (IsLOnSbY(L1))
    {
        printf("Garis Line 1 berada pada sumbu Y\n");
    }

    if (IsLOnSbY(L2))
    {
        printf("Garis Line 2 berada pada sumbu Y\n");
    }

    if (IsLOnSbY(L3))
    {
        printf("Garis Line 3 berada pada sumbu Y\n");
    }

    if (IsLOnSbY(L4))
    {
        printf("Garis Line 4 berada pada sumbu Y\n");
    }

    return 0;
}