/*	program	: loop_2.c 
	author	: Ammar Bagas Fathurrahman Wamtoro
	nim		: 12350081008
	date	:24/10//2023
	desc 	: program menghitung deret dengan repeat n times menggunakan skema loop while do
*/

#include <stdio.h>
#include <conio.h>

int main() {
	//kamus
	int N;
	float i, s;
	
	//kamus
	printf("masukan N :"); scanf("%d", &N);
	
	i = 1;
	s = 1.0;
	printf("s = 1 +");
	
	while (i <= N){
		printf("%.3f", 1/i);
		if (i < N){
			printf("+");
			s = s + 1/i;
			
		}
		i++;
	}
	printf("\nNilai s : %.2f", s);
	return 0;
}

/*#include <stdio.h>
#include <stdlib.h>

int main() {
    // KAMUS
    int n;
    float i, s;

    // ALGORITMA
    printf("Masukan nilai N: ");
    scanf("%d", &n);

    // menggunakan skema loop while...do
    i = 1;
    s = 1.0;
    printf("s = 1 + ");

    while (i <= n) {
        printf("%1.3f", 1 / i);

        if (i < n) {
            printf(" + ");
            s = s + 1 / i;
        }

        i++;
    }

    printf("\nNilai s : %.2f", s);

    return 0;
}*/








