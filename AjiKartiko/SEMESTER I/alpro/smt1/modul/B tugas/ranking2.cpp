#include <iostream>

int main() {
    // Declare variables
    int a, b, c;

    // Input three integers
    std::cout << "Sebutkan 3 Integer atau variabel (a, b, c): ";
    std::cin >> a >> b >> c;

    // Check if the three values are distinct
    if (a != b && b != c && a != c) {
        // Sort the three values from smallest to largest
        int temp;
        if (a > b) {
            temp = a;
            a = b;
            b = temp;
        }
        if (b > c) {
            temp = b;
            b = c;
            c = temp;
        }
        if (a > b) {
            temp = a;
            a = b;
            b = temp;
        }

        // Output the sorted values
        std::cout << "Sorted values: " << a << ", " << b << ", " << c << std::endl;
    } else {
        std::cout << "Data salah, tidak sesuai spesifikasi" << std::endl;
    }

    return 0;
}
