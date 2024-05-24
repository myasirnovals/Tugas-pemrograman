#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    int anak, usia, i;

    printf("masukan jumlah anak: ");
    scanf("%d", &anak);

    // looping
    for (i = 1; i <= anak; i++) {
        printf("anak ke-%d\n", i);
        scanf("%d", &usia);
    }
}
