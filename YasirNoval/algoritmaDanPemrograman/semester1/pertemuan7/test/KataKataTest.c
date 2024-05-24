//
// Created by aibnu on 09/12/2023.
//
#include <stdio.h>
#include <string.h>


void masukankatakata(char kata[]);
void cetakkatakata(char hasil[]);

int main() {
    char kata[100];
    char hasil[100];


    masukankatakata(kata);
    cetakkatakata(hasil);
    printf("%s",hasil);

    return 0;
}


void masukankatakata(char kata[]) {

    while (strcmp(kata, "#") != 0) {
        printf("Masukkan kata kata (akhiri dengan menggunakan #): ");
        scanf("%s", kata);
    }
    printf("\n");
}


void cetakkatakata(char hasil[]) {

    if (strcmp(hasil, "#") != 0) {
        printf("%s ", hasil);
    }
}
