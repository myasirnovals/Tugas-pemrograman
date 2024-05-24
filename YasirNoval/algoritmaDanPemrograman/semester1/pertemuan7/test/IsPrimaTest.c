//
// Created by aibnu on 05/12/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "../boolean.h"

boolean IsPrima(int n);

int main() {
    int n = 4;

    if (IsPrima(n) == true) {
        printf("True");
    } else {
        printf("False");
    }

    return 0;
}



boolean IsPrima(int n) {
    // Kamus

    // Algoritma
    if (n == 2) {
        return true; // true
    } else if (n % 2 == 0 || n == 1) {
        return false; // false
    }

    return true;
}

