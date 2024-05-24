//
// Created by aibnu on 09/12/2023.
//
#include <stdio.h>
#include <string.h>

int main() {
    // kamus
    char kata;
    char tagar = '#';
    int i;

    // algoritma
    printf("Masukan kata: ");
    scanf("%s", &kata);
    strcat(&kata, &tagar);

    while (&kata == strchr(&kata, '#')) {
        printf("Masukan kata: ");
        scanf("%s", &kata);
    }

    printf("%c", kata);


    return 0;
}