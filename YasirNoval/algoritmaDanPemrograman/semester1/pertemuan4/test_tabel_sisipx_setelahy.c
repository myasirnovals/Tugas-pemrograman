#include <stdio.h>
#include <conio.h>
#include "boolean.h"

#define nMax 10

typedef struct {
    int T[nMax + 1];
    int neff;
} TabInt;

//main driver
int main() {
    //kamus
    TabInt Mytab;
    int N;
    int i;
    boolean ketemu;
    int x, y;
    int last;
    int j;

    //algoritma
    //tabel 1
    Mytab.neff = 0;
    printf("masukan bilangan :");
    scanf("%d", &N);

    while (N != 999) {
        if (Mytab.neff < nMax) {
            Mytab.neff++;
            Mytab.T[Mytab.neff] = N;
        }
        printf("masukan bilangan :");
        scanf("%d", &N);
    }

    //cetak tabel
    for (i = 1; i <= Mytab.neff; i++) {
        printf("<%d>", Mytab.T[i]);
    }


    //tabel 2

    printf("\nmasukan nilai x :");
    scanf("%d", &x);
    printf("masukan nilai y :");
    scanf("%d", &y);

    i = 1;
    ketemu = false;

    /*for (i = 1; i <= Mytab.neff && !ketemu; i++){
        if (Mytab.T[i] == y){
            ketemu = true;
        }else {
            ketemu = ketemu;
        }
    }*/



    while (i <= Mytab.neff && !ketemu) {
        if (Mytab.T[i] == y) {
            ketemu = true;
        } else {
            i++;
        }

        if (Mytab.T[i] != y) {
            ketemu = ketemu;
        }
    }


    if (!ketemu) {
        Mytab.neff++;
        Mytab.T[Mytab.neff] = x;
    }

    if (ketemu) {
        if (Mytab.neff < nMax) {
            last = Mytab.neff;
            if (i >= last) {
                Mytab.neff++;
                Mytab.T[Mytab.neff] = x;
            } else {
                for (j = last; last >= i; j--) {
                    Mytab.T[j + 1] = Mytab.T[j];
                    last--;
                }


                Mytab.T[i] = x;
                Mytab.neff++;
            }

        }
    }





    //cetak tabel
    for (i = 1; i <= Mytab.neff; i++) {
        printf("<%d>", Mytab.T[i]);
    }
    return 0;
}