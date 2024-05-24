#include <stdio.h>
#include <stdlib.h>

int main(){
	char i, j;
	i = 3;
	j = 4;

	if (i && j) {
		printf("i && j is true\n");
	}
	if (i & j) {
		printf("i & j is true\n");
	}
	// false = 00000000;
	if (i || j) {
		printf("i || j is true\n");
	}
	if (i | j) {
		printf("i | j is true\n");
	}
	// true = 00000001
	if (i ^ j) {
		printf("i ^ j is true\n");
	}
	if (~i) {
		printf("~i is true\n");
	}
	// true = 11111000

	return 0;
}
