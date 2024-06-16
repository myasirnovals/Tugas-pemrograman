#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;

    // Input nilai T
    printf("Masukkan suhu (T) dalam derajat Celsius: ");
    scanf("%d", &T);

    // ALGORITMA
    if (T <= 0) {
        // Air beku
        printf("Wujud air: Beku\n");
    } else if (T <= 100) {
        // Air cair
        printf("Wujud air: Cair\n");
    } else {
        // Air uap
        printf("Wujud air: Uap\n");
    }

    return 0;
}
