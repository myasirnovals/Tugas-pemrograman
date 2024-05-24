/*
    Program: TabINT.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 31/10/2023
    Description: Mencetak bilangan dari 1 sampai 100, tapi bilangan yang dicetak hanya bilangan primanya saja
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isprima(int n)
{
    // Kamus
    int li;

    // Algoritma
    if(n == 2) {
        return 1;
    }

    if(n % 2 == 0 || n == 1) {
        return 0;
    }

    for(li=3; li <= sqrt(n); li+=2) {
        if(n % li == 0) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    // Kamus
    int li;

    // Algoritma
    printf("\n");
    printf("Bilangan prima dari 1 sampai 100: ");

    for(li=1; li <= 100; li++) {
        if(isprima(li)) {
            printf("%3d", li);
        }
    }
    printf("\n\n");

    return 0;
}