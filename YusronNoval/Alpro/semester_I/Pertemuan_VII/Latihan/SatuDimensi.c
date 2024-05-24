#include <stdio.h>
#include <string.h>

int main()
{
    // Kamus
    char nama[100];

    // Algoritma
    printf("Siapa namamu: ");
    scanf("%[^\n]", &nama);

    printf("\nNamaku %s\n\n", nama);

    return 0;
}