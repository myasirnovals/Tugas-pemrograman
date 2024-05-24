/*
    File: oper1.c
    Pemakaian beberapa operator terhadap bit
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // KAMUS
    int n = 10;     // 1010
    int x = 1;      // 1
    int y = 2;      // 10

    // ALGORITMA
    printf("n = %d \n", n);
    printf("x = %d \n", x);
    printf("y = %d \n", y);
    printf("n & 8 = %d \n", n & 8);     // 1010 AND 1000
    printf("x & ~ 8 = %d \n", x & ~8);  // 1    AND 0111
    printf("y << 2 = %d \n", y << 2);   // 10 ==> 1000 = 8
    printf("y >> 3 = %d \n", y >> 3);   // 10 ==> 0000 = 0

    return 0;
}
