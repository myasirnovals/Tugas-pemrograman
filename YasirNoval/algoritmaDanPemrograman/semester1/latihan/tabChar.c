//
// Created by myasi on 1/16/2024.
//

#include <stdio.h>

int main() {
    int i, j;
    char tmp;

    char T[11] = {
            'P', 'A', 'R', 'A', 'H', '#', 'P', 'A', 'R', 'A', 'H'
    };

    for (i = 0; i < sizeof(T); i++) {
        printf("%c ", T[i]);
    }
    printf("\n\n");

    // algoritma
    i = 0;
    while (i < sizeof(T)) {
        if (T[i] == 'P') {
            for (j = 1; j < sizeof(T); j++) {
                if (T[j] == 'H') {
                    tmp = T[j];
                    T[j] = T[i];
                    T[i] = tmp;
                }
            }
        }

        i = i + 6;
    }

    for (i = 0; i < sizeof(T); i++) {
        printf("%c ", T[i]);
    }
    printf("\n\n");

    return 0;
}