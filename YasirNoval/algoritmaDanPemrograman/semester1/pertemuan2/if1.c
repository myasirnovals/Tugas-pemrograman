/*
    Program: if1.c
    Author: 2350081004/Muhamad Yasir Noval
    Date: 17 Oktober 2023
    Description: Program mencari nilai maksimum
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* program mencari nilai maksimum */
int main() {
    /* KAMUS */
    int a, b;

    /* ALGORITMA */
    printf("Masukan a: ");
    scanf("%d", &a);

    printf("Masukan b: ");
    scanf("%d", &b);

    /* analisa kasus 1 */
    if (a > b) {
        printf("a > b");
    } else if (a == b) {
        printf("a = b");
    } else {
        printf("a < b");
    }

    return 0;
}
