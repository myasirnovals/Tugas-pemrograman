#include <stdio.h>
#include <math.h>

float hitung_standar_deviasi(int arr[], int n) {
    float mean = 0, sum_deviation = 0, standar_deviasi = 0;
    int i;

    for (i = 0; i < n; ++i) {
        mean += arr[i];
    }
    mean = mean / n;

    for (i = 0; i < n; ++i) {
        sum_deviation += pow(arr[i] - mean, 2);
    }
    standar_deviasi = sqrt(sum_deviation / n);

    return standar_deviasi;
}

int main() {
    int bilangan[20] = {3, 8, 12, 14, 16, 18, 21, 24, 27, 30, 34, 36, 39, 41, 45, 48, 50, 53, 57, 60};
    int n = 20;
    float hasil = hitung_standar_deviasi(bilangan, n);
    printf("Standar deviasi dari bilangan adalah %f.\n", hasil);

    return 0;
}
