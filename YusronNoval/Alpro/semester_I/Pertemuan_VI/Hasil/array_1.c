/*
    Program: array_1.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 31/10/2023
    Description: Membuat tanggal berupa hari dengan menggunakan array
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char IsiTabel[10];

} TabString;

int main()
{
    // Kamus
    TabString myTabel[10];
    char Hari[10];
    int i;

    // Algoritma
    for(i=1; i <= 7; i++) {
        printf("Masukan nama hari ke %d :", i);
        scanf("%s", &Hari);
        strcpy(myTabel[i].IsiTabel, Hari);
    }
    printf("\n");

    for(i=1; i<=7; i++) {
        printf("Hari ke %d = %s\n", i, myTabel[i].IsiTabel);
    }

    return 0;
}