#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char IsiTabel[10];

} TabString;

void CatatHari(TabString Hari[7], char NamaHari[10], int ke);

int main()
{
    // Kamus
    TabString myTab[7];
    char Hari[10];
    int i;

    // Algoritma
    for(i=1; i <= 7; i++) {
        printf("Masukan nama hari ke %d : ", i);
        scanf("%s", &Hari);
        CatatHari(myTab, Hari, i);
    }
    printf("\n");

    for(i=1; i <= 7; i++) {
        printf("Hari ke %d = %s\n", i, myTab[i].IsiTabel);
    }

    return 0;
}

void CatatHari(TabString Hari[7], char NamaHari[10], int ke) {
    strcpy(Hari[ke].IsiTabel, NamaHari);
}