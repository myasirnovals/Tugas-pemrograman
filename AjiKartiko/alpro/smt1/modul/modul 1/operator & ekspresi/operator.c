#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // KAMUS
    bool Bool1, Bool2, TF;
    int i, j, hsl;
    float x, y, res;

    // ALGORITMA
    printf("Untuk program ini, baca teksnya dan tambahkan output");

    Bool1 = true;
    Bool2 = false;

    // Boolean AND
    TF = Bool1 && Bool2;

    // Boolean OR
    TF = Bool1 || Bool2;

    // Boolean NOT
    TF = !Bool1;

    // Boolean XOR
    TF = Bool1 ^ Bool2;

    // Operasi Numerik
    i = 5;
    j = 2;
    hsl = i + j;
    hsl = i - j;
    hsl = i / j;
    hsl = i * j;

    // Pembagian/Division (DIV) bilangan bulat
    hsl = i / j;

    // Sisa bagi atau Modulo (MOD)
    hsl = i % j;

    // Operasi Numerik Pecahan
    x = 5.0;
    y = 2.0;
    res = x + y;
    res = x - y;
    res = x / y;
    res = x * y;

    // Operasi relasional numerik
    TF = (i == j);
    TF = (i != j);
    TF = (i > j);
    TF = (i < j);
    TF = (i >= j);
    TF = (i <= j);

    // Operasi relasional numerik
    TF = (x != y);
    TF = (x > y);
    TF = (x < y);
    TF = (x >= y);
    TF = (x <= y);

    return 0;
}
