/*
    Program: TabGenap.c
    Author: 2350081003/Muhamad Yusron Noval
    Date: 31/10/2023
    Description: Membuat Tabel Integer Genap menggunakan Bahasa C dan Array
*/
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define nMax 10

typedef struct {
    int T[nMax+1];
    int neff;

} TabInt;

int main()
{
    // Kamus
    TabInt myTab;
    int i, N;

    // Algoritma
    myTab.neff = 0;
    printf("Masukan bilangan: ");
    scanf("%d", &N);

    while(N != 999) {
        if(myTab.neff < nMax) {
            myTab.neff++;
            myTab.T[myTab.neff] = N;
        } 

        printf("Masukan bilangan: ");
        scanf("%d", &N);
    }
    printf("\n\n");

    for(i=1; i <= myTab.neff; i++) {
        if(myTab.T[i] % 2 == 0) {
            printf("%d ", myTab.T[i]);
        }
    }
    printf("\n\n");

    
    return 0;
}