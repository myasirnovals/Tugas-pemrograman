//
// Created by myasi on 10/14/2023.
//

/*
 * Program: limit.c
 * Author: Muhamad Yasir Noval
 * NIM: 2350081004
 * Class: A
 * Description: program untuk menghitung limit
 */

#include <limits.h>

int main() {
    // KAMUS
    int i;
    long int ii;

    // PROGRAM
    printf("hello\n");
    i = 1234;
    ii = 123456;

    printf("Ini nilai i = 1234 = : %d \n", i);
    printf("Ini nilai ii = 123456 : : %10d \n", ii);

    // print nilai batas integer
    printf("Min dan Max integer : %d, %d \n", INT_MIN, INT_MAX);
    printf("Max long integer : %d, %ld \n", LONG_MAX);

    return 0;
}
