/*
    File: incr.c
    Efek dari operator ++
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // KAMUS
    int i, j;

    // PROGRAM
    i = 3;
    j = i++;

    printf("Nilai i : %d \nNilai j : %d\n", ++i, j);

    return 0;
}
