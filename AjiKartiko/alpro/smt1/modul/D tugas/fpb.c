#include <stdio.h>

int hitung_FPB(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int main() {
	int i;
	
    int pairs[5][2] = {{45, 30}, {12, 18}, {8, 16}, {81, 27}, {24, 36}};
    for (i = 0; i < 5; i++) {
        int hasil = hitung_FPB(pairs[i][0], pairs[i][1]);
        printf("FPB dari %d dan %d adalah %d.\n", pairs[i][0], pairs[i][1], hasil);
    }
    return 0;
}
